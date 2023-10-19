// Definición de pines para segmentos y otros valores constantes
#define A 10
#define B 11
#define C 5
#define D 6
#define E 7
#define F 9
#define G 8
#define CLAVIJA 2
#define UNIDAD A4
#define DECENA A5
#define APAGADO 0
#define TIMEDISPLAYON 10
#define MOTOR_PIN 3

const int sensorPin = A0; // Pin analógico para el sensor

int countDigit = 1;       // Contador para los dígitos en el display
int isArduinoOn = 1;      // Control de encendido/apagado del Arduino
int motorIsOn = 0;        // Control de encendido/apagado del motor

// Función para verificar si un número es primo
int esPrimo(int numero) {
    if (numero <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Función para verificar si el interruptor está presionado
int keypressed() {
    int interruptor = digitalRead(CLAVIJA);
    delay(10);
    if (interruptor == 1) {
        return interruptor;
    }
    return APAGADO;
}

// Configuración inicial del Arduino
void setup() {
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(UNIDAD, OUTPUT);
    pinMode(DECENA, OUTPUT);
    pinMode(MOTOR_PIN, OUTPUT);
    Serial.begin(9600);
    printDigit(0);  
}

// Bucle principal del programa
void loop() {
    int sensorValue = analogRead(sensorPin); // Lectura del valor del sensor
    float voltage = (sensorValue / 1023.0) * 5.0; // Conversión del valor del sensor a voltaje
    float temperatureC = (voltage - 0.5) * 100.0; // Conversión del voltaje a temperatura en grados Celsius

    // Comprobar si la temperatura es igual o mayor a 30 grados Celsius
    if (temperatureC >= 30.0) {
        isArduinoOn = 0; // Apagar Arduino
        digitalWrite(MOTOR_PIN, 0); // Apagar motor
        digitalWrite(UNIDAD, LOW);  // Apagar segmento de unidades
        digitalWrite(DECENA, LOW); // Apagar segmento de decenas
    } else {
        isArduinoOn = 1; // Encender Arduino
        motorIsOn = 0;   // Apagar motor
        if (isArduinoOn == 1) {
            // Controlar el motor
            if (!motorIsOn) {
                analogWrite(MOTOR_PIN, 150); // Encender motor
                motorIsOn = 1;
            }
            int interruptor = keypressed(); // Comprobar si el interruptor está presionado
            printDigit(countDigit); // Mostrar el dígito actual en el display
            if (interruptor == APAGADO) {
                countDigit++; // Incrementar el contador de dígitos
                if (countDigit > 99) {
                    countDigit = 0; // Volver a cero cuando se llega a 99
                }
                delay(TIMEDISPLAYON);
            } else {
                for (int i = 0; i < 100; i++) {
                    if (esPrimo(i)) {
                        countDigit = i;
                        printDigit(countDigit);
                        delay(TIMEDISPLAYON);
                    }
                }
            }
            Serial.print("Temperatura: ");
            Serial.print(temperatureC);
            Serial.println(" °C");
        }
    }
}

// Función para mostrar un dígito en el display de 7 segmentos
void printDigit(int number) {
    int decena = number / 10;
    int unidad = number % 10;

    digitalWrite(UNIDAD, LOW);
    digitalWrite(DECENA, LOW);
    display(decena);
    digitalWrite(DECENA, HIGH);
    delay(150);

    digitalWrite(UNIDAD, LOW);
    digitalWrite(DECENA, LOW);
    display(unidad);
    digitalWrite(UNIDAD, HIGH);
    delay(150);
}

// Función para controlar los segmentos del display de 7 segmentos
void display(int digit) {
    switch (digit) {
        case 0:
            digitalWrite(A, LOW);
            digitalWrite(B, LOW);
            digitalWrite(C, LOW);
            digitalWrite(D, LOW);
            digitalWrite(E, LOW);
            digitalWrite(F, LOW);
            digitalWrite(G, HIGH);
            break;
        case 1:
            digitalWrite(A, HIGH);
            digitalWrite(B, LOW);
            digitalWrite(C, LOW);
            digitalWrite(D, HIGH);
            digitalWrite(E, HIGH);
            digitalWrite(F, HIGH);
            digitalWrite(G, HIGH);
            break;
        case 2:
            digitalWrite(A, LOW);
            digitalWrite(B, LOW);
            digitalWrite(C, HIGH);
            digitalWrite(D, LOW);
            digitalWrite(E, LOW);
            digitalWrite(F, HIGH);
            digitalWrite(G, LOW);
            break;
        case 3:
            digitalWrite(A, LOW);
            digitalWrite(B, LOW);
            digitalWrite(C, LOW);
            digitalWrite(D, LOW);
            digitalWrite(E, HIGH);
            digitalWrite(F, HIGH);
            digitalWrite(G, LOW);
            break;
        case 4:
            digitalWrite(A, HIGH);
            digitalWrite(B, LOW);
            digitalWrite(C, LOW);
            digitalWrite(D, HIGH);
            digitalWrite(E, HIGH);
            digitalWrite(F, LOW);
            digitalWrite(G, LOW);
            break;
        case 5:
            digitalWrite(A, LOW);
            digitalWrite(B, HIGH);
            digitalWrite(C, LOW);
            digitalWrite(D, LOW);
            digitalWrite(E, HIGH);
            digitalWrite(F, LOW);
            digitalWrite(G, LOW);
            break;
        case 6:
            digitalWrite(A, LOW);
            digitalWrite(B, HIGH);
            digitalWrite(C, LOW);
            digitalWrite(D, LOW);
            digitalWrite(E, LOW);
            digitalWrite(F, LOW);
            digitalWrite(G, LOW);
            break;
        case 7:
            digitalWrite(A, LOW);
            digitalWrite(B, LOW);
            digitalWrite(C, LOW);
            digitalWrite(D, HIGH);
            digitalWrite(E, HIGH);
            digitalWrite(F, HIGH);
            digitalWrite(G, HIGH);
            break;
        case 8:
            digitalWrite(A, LOW);
            digitalWrite(B, LOW);
            digitalWrite(C, LOW);
            digitalWrite(D, LOW);
            digitalWrite(E, LOW);
            digitalWrite(F, LOW);
            digitalWrite(G, LOW);
            break;
        case 9:
            digitalWrite(A, LOW);
            digitalWrite(B, LOW);
            digitalWrite(C, LOW);
            digitalWrite(D, LOW);
            digitalWrite(E, HIGH);
            digitalWrite(F, LOW);
            digitalWrite(G, LOW);
            break;
        default:
            digitalWrite(A, HIGH);
            digitalWrite(B, HIGH);
            digitalWrite(C, HIGH);
            digitalWrite(D, HIGH);
            digitalWrite(E, HIGH);
            digitalWrite(F, HIGH);
            digitalWrite(G, HIGH);
            break;
    }
}

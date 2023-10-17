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

int countDigit = 1; // Contador para los dígitos

// Función para verificar si un número es primo
int esPrimo(int numero) {
    // Si el número es menor o igual a 1, no es primo
    if (numero <= 1) {
        return 0;
    }
    // Comprueba si el número es divisible por cualquier número menor o igual a la raíz cuadrada del número
    for (int i = 2; i * i <= numero; i++) {
        if (numero % i == 0) {
            return 0;
        }
    }
    // Si no es divisible por ningún número menor o igual a la raíz cuadrada, es primo
    return 1;
}

// Función para verificar si se presionó una tecla
int keypressed() {
    int interruptor = digitalRead(CLAVIJA);
    delay(10);
    if (interruptor == 1) {
        return interruptor;
    }
    // Si no se presionó la tecla, retorna el valor APAGADO (0)
    return APAGADO;
}

void setup() {
    // Configura los pines como salidas
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(UNIDAD, OUTPUT);
    pinMode(DECENA, OUTPUT);
    // Inicializa el display con un 0
    printDigit(0);
}

void loop() {
    // Verifica si se presionó una tecla
    int interruptor = keypressed();
    // Muestra el dígito actual
    printDigit(countDigit);
    if (interruptor == APAGADO) {
        // Si no se presionó la tecla, incrementa el contador de dígitos
        countDigit++;
        // Si el contador supera 99, reinicia a 0
        if (countDigit > 99) {
            countDigit = 0;
        }
        // Espera un tiempo para mostrar el siguiente dígito
        delay(TIMEDISPLAYON);
    } else {
        // Si se presionó la tecla, muestra los números primos del 0 al 99
        for (int i = 0; i < 100; i++) {
            if (esPrimo(i)) {
                countDigit = i;
                printDigit(countDigit);
                // Espera un tiempo para mostrar el siguiente número primo
                delay(TIMEDISPLAYON);
            }
        }
    }
}

// Función para mostrar un dígito en el display de 7 segmentos
void printDigit(int number) {
    int decena = number / 10;
    int unidad = number % 10;
    // Apaga los pines de unidades y decenas
    digitalWrite(UNIDAD, LOW);
    digitalWrite(DECENA, LOW);
    // Muestra la decena actual
    display(decena);
    digitalWrite(DECENA, HIGH);
    // Espera un tiempo antes de mostrar la unidad
    delay(250);
    // Apaga los pines de unidades y decenas
    digitalWrite(UNIDAD, LOW);
    digitalWrite(DECENA, LOW);
    // Muestra la unidad actual
    display(unidad);
    digitalWrite(UNIDAD, HIGH);
    // Espera un tiempo antes de continuar
    delay(250);
}

// Función para mostrar un dígito en el display de 7 segmentos
void display(int digit) {
  // Configuración de los pines para mostrar cada dígito
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
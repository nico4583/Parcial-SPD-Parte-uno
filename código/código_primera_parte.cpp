// Definiciones de pines para los segmentos del display de 7 segmentos
#define A 10
#define B 11
#define C 5
#define D 6
#define E 7
#define F 9
#define G 8

// Definiciones de pines para los botones
#define SUBE 4
#define BAJA 3
#define RESET 2

// Definiciones de pines para los dígitos
#define UNIDAD A5
#define DECENA A4

int countDigit = 0;     // Variable para almacenar el contador
int displayState = UNIDAD;  // Variable para alternar entre los dígitos

void setup() {
  pinMode(SUBE, INPUT_PULLUP);
  pinMode(BAJA, INPUT_PULLUP);
  pinMode(RESET, INPUT_PULLUP);

  // Configuración de pines de salida para los segmentos del display y los dígitos
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  
  pinMode(UNIDAD, OUTPUT);
  pinMode(DECENA, OUTPUT);
  
  printDigit(countDigit); // Inicialmente, muestra el valor 0 en el display
}

void loop() {
  int pressed = keypressed(); // Verifica si se presionó algún botón

  // Incrementa el contador cuando se presiona el botón "SUBE"
  if (pressed == SUBE) {
    countDigit++;
    if (countDigit > 99) {
      countDigit = 0;
    }
    printDigit(countDigit); // Actualiza el display con el nuevo valor
    delay(250); // Retardo para evitar múltiples lecturas con un solo botón
  }

  // Decrementa el contador cuando se presiona el botón "BAJA"
  if (pressed == BAJA) {
    countDigit--;
    if (countDigit < 0) {
      countDigit = 99;
    }
    printDigit(countDigit); // Actualiza el display con el nuevo valor
    delay(250); // Retardo para evitar múltiples lecturas con un solo botón
  }

  // Reinicia el contador a 0 cuando se presiona el botón "RESET"
  if (pressed == RESET) {
    countDigit = 0;
    printDigit(countDigit); // Actualiza el display con el valor 0
    delay(250); // Retardo para evitar múltiples lecturas con un solo botón
  }
}

int keypressed() {
  // Verifica el estado de los botones y devuelve el valor correspondiente
  if (digitalRead(SUBE) == LOW) {
    return SUBE;
  }
  if (digitalRead(BAJA) == LOW) {
    return BAJA;
  }
  if (digitalRead(RESET) == LOW) {
    return RESET;
  }
  return 0; // Si ningún botón está presionado
}

void printDigit(int number) {
  int decena = number / 10;
  int unidad = number % 10;

  // Alterna entre los dígitos para mostrar el número completo
  digitalWrite(UNIDAD, displayState == UNIDAD ? LOW : HIGH);
  digitalWrite(DECENA, displayState == DECENA ? LOW : HIGH);
  
  displayState = (displayState == UNIDAD) ? DECENA : UNIDAD;

  // Llama a la función display() para mostrar los segmentos del dígito actual
  display(unidad);
  delay(2); // Retardo para mostrar el dígito

  // Alterna entre los dígitos nuevamente
  digitalWrite(UNIDAD, displayState == UNIDAD ? LOW : HIGH);
  digitalWrite(DECENA, displayState == DECENA ? LOW : HIGH);
  
  displayState = (displayState == UNIDAD) ? DECENA : UNIDAD;
  
  display(decena); // Llama a la función display() para mostrar los segmentos del dígito actual
  delay(2); // Retardo para mostrar el dígito
}

void display(int digit) { switch (digit) {
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
    case 10:
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

#define A 12
#define B 13
#define C 7
#define D 8
#define E 9
#define F 11
#define G 10
#define SUBE 5
#define BAJA 4
#define RESET 3
int i=0;
int j=0;


void setup()
{
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(E,OUTPUT);
  pinMode(F,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(5, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  
  pinMode(A4, OUTPUT);//Segundo Display
  pinMode(A5, OUTPUT);//Pirmer Display
}

void loop()
{
  if(!digitalRead(SUBE)){
    i++;
    delay(200);
    if(i>9){
      i=0;
      j++;
    }else if(j>9){
      j=0;
    }
  }
  if(!digitalRead(BAJA)){
  	i--;
    delay(200);
    if(i<0){
      i=9;
      j--;
    } else if(j<0){
      j=9;
    }
  }
  if(!digitalRead(RESET)){
  	i=0;
    j=0;
  }
  changeDigit(j,i);
}

void changeDigit(int primerDisplay, int segundoDisplay){
  displayNumber(primerDisplay);
  turnOnDisplay(0,1);
  delay(10);
  displayNumber(segundoDisplay);
  turnOnDisplay(1,0);
  delay(10);
}

void displaySegment(int segmnt_a, int segmnt_b, int segmnt_c, int segmnt_d, int segmnt_e, int segmnt_f, int segmnt_g)
{
  digitalWrite(A, segmnt_a);
  digitalWrite(B, segmnt_b);
  digitalWrite(C, segmnt_c);
  digitalWrite(D, segmnt_d);
  digitalWrite(E, segmnt_e);
  digitalWrite(F, segmnt_f);
  digitalWrite(G, segmnt_g);
}

void displayNumber(int num){
  switch(num){
    case 0:{displaySegment(1,1,1,1,1,1,0);break;}
    case 1:{displaySegment(0,1,1,0,0,0,0);break;}
    case 2:{displaySegment(1,1,0,1,1,0,1);break;}
    case 3:{displaySegment(1,1,1,1,0,0,1);break;}
    case 4:{displaySegment(0,1,1,0,0,1,1);break;}
    case 5:{displaySegment(1,0,1,1,0,1,1);break;}
    case 6:{displaySegment(1,0,1,1,1,1,1);break;}
    case 7:{displaySegment(1,1,1,0,0,0,0);break;}
    case 8:{displaySegment(1,1,1,1,1,1,1);break;}
    case 9:{displaySegment(1,1,1,1,0,1,1);}break;
  }
}

void turnOnDisplay(int display1, int display2){
  digitalWrite(A5, display1);
  digitalWrite(A4, display2);
}

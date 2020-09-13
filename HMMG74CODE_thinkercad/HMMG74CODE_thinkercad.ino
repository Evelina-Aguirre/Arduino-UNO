//https://www.tinkercad.com/things/1oSJFG0z4AH

#define P1 6
#define P2 7
#define D3 8
#define P4 9
#define D5 10
#define D6 11
#define D7 12

int dato3;
int dato5;
int dato6;
int dato7;
int paridad1;  
int paridad2;
int paridad4;

void setup()
{
  pinMode(P1, OUTPUT);
  pinMode(P2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(P4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(A2, INPUT_PULLUP);
  pinMode(A3, INPUT_PULLUP);
  pinMode(A4, INPUT_PULLUP);
  pinMode(A5, INPUT_PULLUP);
  
  
}

void loop()
{
  
  dato7=digitalRead(A2);
  dato6=digitalRead(A3);
  dato5=digitalRead(A4);
  dato3=digitalRead(A5);
  
  paridad1=(dato3+dato5+dato7)%2;
  paridad2=(dato3+dato6+dato7)%2;
  paridad4=(dato5+dato6+dato7)%2;
  
  ledsOnOff(12,dato7);
  ledsOnOff(11,dato6);
  ledsOnOff(10,dato5);
  ledsOnOff(9,paridad4);
  ledsOnOff(8,dato3);
  ledsOnOff(7,paridad2);
  ledsOnOff(6,paridad1);
  
}

int ledsOnOff(int pin,int estadoLed)
{
switch(estadoLed)
  {
  case 0:
    digitalWrite(pin,HIGH);
    break;
  case 1:
    digitalWrite(pin,LOW);
    break;
  }
}
  

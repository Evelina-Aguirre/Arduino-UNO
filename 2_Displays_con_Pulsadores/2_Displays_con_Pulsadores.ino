//https://www.tinkercad.com/things/8VSBqx0aXSe
#define A 12
#define B 13
#define C 7
#define D 8
#define E 9
#define F 11
#define G 10
#define DECENA A5
#define UNIDAD A4
#define TIME 10
#define botonMas 5
#define botonMenos 4
#define botonReset 3


int conmutador=0;           
int contador=0;          
int sube=1;
int subePrevia=1;
int baja=1;
int bajaPrevia=1;
int reset=1;
int resetPrevia=1;

void setup()
{
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(5, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
digitalWrite(UNIDAD,0);
  digitalWrite(DECENA,0);
  conteo(0);
}

void loop()   
{
  int pressed = keypressed();

  if(pressed==botonMas)
    {
      contador++;
      if(contador>99)
        contador=0;
    }
    else if(pressed==botonMenos)
    {
      contador--;
      if(contador<0)
      contador=99;

    }
    else if(pressed==botonReset)
    {
     contador=0;
    }

 quienSePrendeConQueNumero(contador); 
   
}//FIN LOOP
//----------------------------------------
    
void quienSePrendeConQueNumero(int contador) 
{
    onOFF(2);
  conteo(contador/10);
    onOFF(1);
    onOFF(2);
  conteo(contador- 10*((int)contador/10));
    onOFF(0); 
}

    
//--------------------------------------------
void onOFF(int conmutador)
{ if(conmutador==0)
{
  digitalWrite(UNIDAD,LOW);   
  digitalWrite(DECENA,HIGH); 
  delay(TIME);
  
}
else if(conmutador==1)
{
 
  digitalWrite(UNIDAD,HIGH);   
  digitalWrite(DECENA,LOW);   
  delay(TIME);
} 
else
{
  digitalWrite(UNIDAD,HIGH);   
  digitalWrite(DECENA,HIGH);  
}

}
 
 
//--------------------------------------------  
int conteo(int numero)
{
  digitalWrite(A, LOW);
  digitalWrite(B, LOW);
  digitalWrite(C, LOW);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
  
    switch(numero)
    {
 case 0:
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, LOW);
     break;
 case 1:
    digitalWrite(A, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
   break;

case 2:

    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, LOW);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, LOW);
    digitalWrite(G, HIGH);
    break;

case 3:
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, HIGH);
    break;

 case 4:
    digitalWrite(A, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    break;
      
 case 5:
    digitalWrite(A, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, LOW);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    break;

 case 6:
    digitalWrite(A, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    break;
      
 case 7:
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
    break;
      
 case 8:
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    break;
      
case 9:
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, LOW);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    break;
    }
    
}

int keypressed(void)
{ 
  
    sube = digitalRead(botonMas); //0 si presiono, 1 si no preciono
    baja = digitalRead(botonMenos);
  reset = digitalRead(botonReset);
    if (sube== 1)    
      subePrevia =1; 
    if (baja)
      bajaPrevia =1;
    if(reset)
      resetPrevia =1;
  
      
      if(sube==0 && sube != subePrevia)
        {
          subePrevia = sube;
        return botonMas;
        }
  
      if(baja==0 && baja != bajaPrevia)
        {
          bajaPrevia = baja;
        return botonMenos;
        }
  
        if(reset==0 && reset != resetPrevia)
        {
          resetPrevia = reset;
        return botonReset;
        }
 return 0;
 
}

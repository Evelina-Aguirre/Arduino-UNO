https://www.tinkercad.com/things/a1YjUiYiZJ6
#define A 12
#define B 13
#define C 7
#define D 8
#define E 9
#define F 11
#define G 10
#define UNIDAD A3
#define DECENA A4
#define CENTENA A5
#define TIME 10

int conmutador=0;           
int unidad;
int decena;
int centena;
//--------------------------------------------  

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
  pinMode(A3, OUTPUT);
 
}
//--------------------------------------------  

void loop()   
{
  int temp = map(analogRead(A0), 20, 358, -40, 125);
  unidad = (temp - 10*((int)temp/10));
  decena = (temp/10);
  centena = 0;
  
  if(unidad < 0 || decena < 0) 
  {
    unidad = (unidad * (-2)) / 2;
   decena = (decena * (-2)) / 2;
    centena = -1;
  }
  else if(decena > 9 ){
    decena = (decena - 10*((int)decena/10));
    centena = 1;
  }   

 quienSePrendeConQueNumero(unidad,decena,centena); 
   
}

//----------------------------------------
    
void quienSePrendeConQueNumero(int unidad, int decena, int centena) 
{
    onOFF(3);//3 apagado
  conteo(centena);
    onOFF(2);//2 prende centena
    onOFF(3);//3 apagado
  conteo(decena);
    onOFF(1);//1 prende decena 
    onOFF(3);//3 apagado
    conteo(unidad);
    onOFF(0);//0 prende unidad
    onOFF(3);//3 apagado
    
}

    
//--------------------------------------------
void onOFF(int conmutador)
{ if(conmutador==0)//0 prende unidad
{
  digitalWrite(UNIDAD,LOW);   
  digitalWrite(DECENA,HIGH);
  digitalWrite(CENTENA,HIGH);   
  delay(TIME);
  
}
else if(conmutador==1)//1 prende decena
{
 
  digitalWrite(UNIDAD,HIGH);   
  digitalWrite(DECENA,LOW); 
  digitalWrite(CENTENA,HIGH); 
  delay(TIME);
} 
else if(conmutador==2)//2 prende centena
{
 
  digitalWrite(UNIDAD,HIGH);   
  digitalWrite(DECENA,HIGH);  
  digitalWrite(CENTENA,LOW); 
  delay(TIME);
}  
else //3 apagados     
{ 
  digitalWrite(UNIDAD,HIGH);   
  digitalWrite(DECENA,HIGH); 
  digitalWrite(CENTENA,HIGH);
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
  
case -1:
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, HIGH);
    break;  
    }
    
}

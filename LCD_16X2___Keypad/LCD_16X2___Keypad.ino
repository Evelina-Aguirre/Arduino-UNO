//Diseño y simulador --> https://www.tinkercad.com/things/fg1RjoNARX1
#include <LiquidCrystal.h>
LiquidCrystal lcd(A0, 2, A2, A3, A4, A5);

const char keypad[4][4]={'1','2','3','A',
             '4','5','6','B',
               '7','8','9','C',
               '*','0','#','D'};

char lcdLine[17];
//------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------

void setup()
{

  lcd.begin(16, 2);
  
  pinMode(3, INPUT_PULLUP);//PINES DE ENTRADA(FILAS)
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, OUTPUT);//PINES DE SALIDA (COLUMNA)
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

}

//------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------

void loop()
{

    lcd.setCursor(0,0);//SETEO POSICIÓN COLUMNA 0, FILA 0

  char k = keyPressed();
  
    if (k)//LLAMO FUNCIÓN PRINCIPAL, PREGUNTO QUIÉN ESTÁ PRESIONADO Y LO IMPRIMO
    {
        sprintf(lcdLine,"Presionaste: %c",k);
      lcd.print(lcdLine);

    }

}

//------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------
void statusChange(int outputPin)//SE USA DENTRO DE KEYPRESSED
{
  digitalWrite(7,HIGH);//LEVANTA LAS FILAS
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(outputPin,LOW);//BAJA COLUMNAS - DEL 7 AL 10 QUE MAPEA MÁS ABAJO CON KEYPRESSED -
    return;
};

//------------------------------------------------------------------------------------------------------------

int readPin(int inputPin)//LEE PIN DE ENTRADA - FILA -
{                     
  int retorno;
    retorno = digitalRead(inputPin);
    return retorno;      //RETORNA PIN FILA LEÍDO
};

//------------------------------------------------------------------------------------------------------------
char keyPressed()
{
  int row,col;
    int inputPin, outputPin;

    for(outputPin=7;outputPin<11;outputPin++)//RECORRE PINES COLUMNA
      {
          statusChange(outputPin);//SUBE PINES DE ENTRADA (FILA), BAJA PINES SALIDA(COLUMNA)
          for (inputPin=3;inputPin<7;inputPin++)// RECORRE LOS PINES FILA ....
          {

              if ( readPin(inputPin) == 0 )//SI ALGÚN PIN FILA ESTÁ PRESIONADO....
              {

                  row = map(inputPin,6,3,0,3);//3 A 6 FILA, PORQUÉ 0 Y 3 SEPA DIOS, FUNCIONA ASÍ
                  col = map(outputPin,10,7,0,3);//7 AL 10 COLUMNA
                                
                  return keypad[col][row];//RETORNA PRESIONADO

              }
          }
      }
  delay(100);
      return 0;
}

//------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------

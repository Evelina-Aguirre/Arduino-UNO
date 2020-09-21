//Diseño y simulador -> https://www.tinkercad.com/things/5qOUibJIclN
#include <LiquidCrystal.h>
LiquidCrystal lcd(A0, 2, A2, A3, A4, A5);
char lcdLine[17];//LCD


//SIEMPRE CON ESTE TECLADO 
//*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*//
#include <Keypad.h>

const byte ROWS=4;
const byte COLS=4;
char keys[ROWS][COLS]={'1','2','3','A',
             '4','5','6','B',
               '7','8','9','C',
               '*','0','#','D'};

byte rowPins[ROWS]={10,9,8,7};//PINES FILA
byte colPins[COLS]={6,5,4,3};//PINES COLUMNA

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );//MAPEO
//*/*/*//*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*//


//------------------------------------------------------------------------------------------------------------

void setup()
{
  lcd.begin(16, 2);//LE INDICO TAMAÑO DEL LCD
}

//------------------------------------------------------------------------------------------------------------

void loop()
{
  //TECLADO
  char key=keypad.getKey();//GETEO QUÉ SE ESTÁ PRESIONANDO
  
  //Serial.println(key); --> Si es necesario prueba por consola
  
  //LCD
    if(key != NO_KEY)
    {
      lcd.setCursor(0,0);//SETEO POSICIÓN COLUMNA 0, FILA 0
      sprintf(lcdLine,"Presionaste: %c", key);//CARGO EN LCDLINE LO QUE DEBE IMPRIMIR
      lcd.print(lcdLine);//IMPRIMO
      
    }

}
//AAAAND DONE!

//------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------

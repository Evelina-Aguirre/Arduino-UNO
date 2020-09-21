//Diseño y simulador -->https://www.tinkercad.com/things/hX7dGQDMUuT
#include <LiquidCrystal.h>
LiquidCrystal myLcd(8,9,4,5,6,7);


char lcdLine[20];
int temp=0;

void setup()
{
  myLcd.begin(16,2);
 /* myLcd.setCursor(0,0);
  sprintf(lcdLine,"Hola ");
  myLcd.print(lcdLine);*/

}

void loop()
{
  temp = map(analogRead(A0),20,358,-40,125);
    myLcd.setCursor(0,0);
    sprintf(lcdLine,"Temperatura %d",temp);
    myLcd.print(lcdLine);
  
}

//Diseño y Simulación -->https://www.tinkercad.com/things/5CndQvO0D4m
int brillo;
int posicion;
void setup()
{
 
}

void loop()
{
  posicion=analogRead(A0); 
  brillo=map(posicion,0,1023,0,255);
  analogWrite(5,brillo);
  
   
}

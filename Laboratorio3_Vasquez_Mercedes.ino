
/*
 * LABORATORIO 3
 * JUEGO ATARI
*/

int dato;

void setup() {
  Serial.begin(9600);
  pinMode(7,INPUT);
  pinMode(6,INPUT);
  pinMode(5,INPUT);
  pinMode(4,INPUT);
  

}

void loop() {
// dato=analogRead(0);
// Serial.write(dato/4);// no envio tipo de dato solo valor en bits
// delay(1000);
if(digitalRead(7)==LOW){
  delay(250);
  Serial.print("A");
  }
if(digitalRead(6)==LOW){
  delay(250);
  Serial.print("B");
  }
if(digitalRead(5)==LOW){
  delay(250);
  Serial.print("C");
  }
if(digitalRead(4)==LOW){
  delay(250);
  Serial.print("D");
  }

}

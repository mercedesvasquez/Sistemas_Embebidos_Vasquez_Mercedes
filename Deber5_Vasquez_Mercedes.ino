/*
 *  
DEBER 5
Realizar un programa que mediante interrupciones tenga 3 modos: Inicio del sistema, giro de motor y fin de programa.
El giro debe ser ingresado por comunicación serial. 
 */
#include<Servo.h>//libreria para el servo
Servo servo;
String datos;
int giro=0;
int modo;
int casos=0;
void setup() {
  servo.attach(6);
  Serial.begin(9600);
  attachInterrupt(0,interrupciones,LOW);

}

void loop() {
  if(casos==2){
    delay(200);
    if(Serial.available()>0){
      datos=Serial.readString();//cargar informacion dato en string
      giro=datos.toInt();//convierto dato a int
      
     }
     if(giro<180){
      servo.write(giro);
     }
     else{
      Serial.println(" ");
      Serial.println("Digito Incorrecto");
      delay(20);
      }
  }
}
void interrupciones(){
  switch(casos){
    case 0:
    Serial.println("Iniciando Sistema");
    casos++;
    break;
    case 1:
    Serial.println("Ingrese un valor del 0 al 180");
    
      casos++;
    break;
    case 2:
    Serial.println("");
    Serial.println("Fin de programa");
    casos=0;
    break;
    
  }
  
}

/*
 * LABORATORIO 2
 * Se tiene un reloj visualizado en una LCD donde se observa el horero y minutero. Sin embargo, por
razones de simulaci´on, el minutero cambia su valor cada segundo y el horero en consecuencia, cada
minuto.

 */
#include<LiquidCrystal.h>
#include<TimerOne.h>// libreria para el reloj
#include<MsTimer2.h>
LiquidCrystal lcd(53,51,49,46,45,42);
const int leds[4]={4,5,6,7};
const int sensores[4]={22,23,24,25};
int va[4];
int prender=0;//interrupcciones
int modo;
int cont=0,minu=-1,h=0;
int cs=0;
int datos=0,datos1;
int i,j=0,k,n;
long Led1r,Led2r;
void setup() {
 for(i=0;i<4;i++){
  pinMode(leds[i],OUTPUT);
 }
 for(k=0;k<4;k++){
  pinMode(sensores[k],INPUT);
 }
 i=0;
 Serial.begin(9600);
 lcd.begin(16,2);
 attachInterrupt(2,encederApagar,LOW);
 attachInterrupt(3,modos,LOW);
 

}

void loop() {
  if(modo==2){
    lcd.setCursor(0,1);
    lcd.print("            ");
    datos=analogRead(0);
    datos=map(datos,0,1023,0,60);
    datos1=analogRead(1);
    datos1=map(datos1,0,1023,0,24);
    minu=datos;
    h=datos1;
    Serial.println(datos);
    Serial.println(datos1);
    
    //Reloj
    minu++;
    if(minu==60){
      minu=1;
      h++;
      if(h==24){
        h=0;
      }
      }
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(String("RELOJ:")+String(h)+String(":")+String(minu)); 
  }
  
}

void reloj(){
   minu++;
    if(minu==60){
      minu=1;
      h++;
      if(h==24){
        h=0;
      }
      }
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(String("RELOJ: ")+String(h)+String(":")+String(minu));  
 
}
void encederApagar(){
  switch(prender){
    case 0:
    Timer1.initialize(1000000);
    Timer1.attachInterrupt(reloj);
    prender++;
    break;
    case 1:
    lcd.setCursor(0,1);
    lcd.print("MODOS");
    prender++;
    break;

    case 2:
    Timer1.detachInterrupt();
    MsTimer2::stop();
    lcd.clear();
    for(i=0;i<4;i++){
      digitalWrite(leds[i],LOW);
    }
    prender=0;
    modo=0;
    cont=0;
    i=0;
    j=0;
    minu=-1;
    h=0;
    break;
    default:
    prender=0;
    break;
    
  }
}
void modos(){
  if(prender==2){
    switch(modo){
      case 0:
      
      MsTimer2::set(1000,prenderleds);
      MsTimer2::start();// inicio
      modo++;
      break;
      case 1:
      cont=0;
      MsTimer2::stop();
      Timer1.detachInterrupt();
      modo++;
      break;
      case 2:
      Timer1.initialize(1000000);
      Timer1.attachInterrupt(reloj);
      modo++;
      break;
      case 3:

      MsTimer2::set(1000,activosensores);
      MsTimer2::start();
      modo=0;
      break;      default:
      modo=0;
      break;
      
    }
  }
  
}

void prenderleds(){
  if(cont<20){
    Serial.println("LEDS FUNCIONANDO");
    lcd.setCursor(0,1);
    lcd.print("LEDS EN FUNCION");
    cont++;
    Led1r = random(0,4);
    Led2r  = random (0,4);
        digitalWrite(leds[Led1r], HIGH);
        digitalWrite(leds[Led2r], LOW);   
    Serial.println(Led1r);
    Serial.println(Led2r);
  if(cont==20){
    cont=20;
    for(j=0;j<cont;j++){
      for(i=0;i<4;i++){
        digitalWrite(leds[i], LOW);
        delay(500);
       }
    }
   lcd.setCursor(0,1);
   lcd.print("                "); 
  }
 //Serial.println(String(cont));
}
}
void activosensores(){
  //Serial.println("MODO 4 ACTIVACION DE SENSORES");
  for(n=0;n<4;n++){
    va[n]=digitalRead(sensores[n]);
    
    if(va[n]==LOW){
      Serial.println("Sensor Activado"+String(n));
    }
  }
 }

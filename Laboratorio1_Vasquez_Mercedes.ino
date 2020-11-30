/*
 * UNIVERSIDAD T[ECNICA DEL NORTE
 * FICA-CITEL
 * LABORATORIO UNO
 */

#include<LiquidCrystal.h>
String cd1="ca900813";
String cd2="aj881112";
String cd3="ja890109";
String alm; //donde se almacena
String n1="Bienvenido Carlos Arias";
String n2="Bienvenido Andres Juarez";
String n3="Bienvenido Javier Andrade";
String n4="Usuario Incorrecto";
int i=0;
String compr1,compr2,compr3;
int com1=0,com2=0,com3=0;
const int rs=13, en=12, d4=11, d5=10,d6=9,d7=8;
int bt=7,C=6,IN=5;

LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
void setup() {
  pinMode(bt,INPUT);
  pinMode(C,OUTPUT);
  pinMode(IN,OUTPUT);
  Serial.begin(9600);
  Serial.println("Ingrese credenciales: ");
  lcd.begin(16,2);

}

void loop() {
  if(Serial.available()>0){ 
    alm=Serial.readString();
    if(alm==cd1){
      com1=1;
      Serial.println("  Bienvenido : Carlos Arias ");
      digitalWrite(C,HIGH);
      delay(2000);
      digitalWrite(C,LOW);
      for(i=15;i>=-7;i--)
      {
      lcd.clear();
      lcd.setCursor(i, 1);
      lcd.print(n1);
      delay(500);
      }

    }
    else
      if(alm==cd2){
        com2=1;
      Serial.println("  Bienvenido :  Andres Juarez ");
      digitalWrite(C,HIGH);
      delay(2000);
      digitalWrite(C,LOW);
      for(i=14;i>=-8;i--)
      {
      lcd.clear();
      lcd.setCursor(i, 1);
      lcd.print(n2);
      delay(500);
      }
    }
    else
    
      if(alm==cd3){
        com3=1;
      Serial.println("  Bienvenido : Javier Andrade ");
      digitalWrite(C,HIGH);
      delay(2000);
      digitalWrite(C,LOW);
      for(i=18;i>=-9;i--)
      {
      lcd.clear();
      lcd.setCursor(i, 1);
      lcd.print(n3);
      delay(500);
      }
    }
    
    else
    {
      Serial.println("Usuario Incorrecto");
       digitalWrite(IN,HIGH);
      delay(2000);
      digitalWrite(IN,LOW);
      for(i=12;i>=-10;i--)
      {
      lcd.clear();
      lcd.setCursor(i, 1);
      lcd.print(n4);
      delay(500);
      }
      }
    
  }

     if(digitalRead(bt)==LOW){
      delay(250);
       Serial.println(" ");
       Serial.println("  REGISTRO DE ASISTENTES ");
      if(com1==1)
      {
        compr1="Usuario Carlos Arias ingreso";
        com1=0;
      }
      else
      compr1="Usuario Carlos Arias no ingreso";
      if(com2==1){
        compr2="Usuario Andres Juarez ingreso";
        com2=0;
      }
      else
      compr2="Usuario Andres Juarez no ingreso";
      if(com3==1){
        compr3="Usuario Javier Andrade ingreso";
        com3=0;
      }
      else
      compr3="Usuario Javier Andrade no ingreso";
     
     Serial.println("");
     Serial.println(compr1);
     Serial.println(compr2);
     Serial.println(compr3);
  }
}
    

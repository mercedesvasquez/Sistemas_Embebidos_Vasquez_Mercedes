
/*
 * Realizar un reloj con alarma ingresada por comunicación serial
 */

#include<MsTimer2.h>
#include<LiquidCrystal.h>
LiquidCrystal lcd (13,12,11,10,9,8);
int s=0,m=0,h=0,am=0,ah=0;
int pdr=0,apr=0,grd=1,grda=1;
int num;
String val;
const int ld=7;
void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(ld,OUTPUT);
  attachInterrupt(0,alarma,LOW);
  Serial.println("Minuto: ");
  MsTimer2::set(1000,reloj);
  MsTimer2::start();
  
  
}
void loop(){
  if(grd==1){
    if(Serial.available()>0){
      switch(pdr){
        case 0:
        Serial.println("Ingrese la hora del reloj");
        val=Serial.readString();
        num=val.toInt();
        m=num;
        pdr++;
        break;
        case 1:
        val=Serial.readString();
        num=val.toInt();
        h=num;
        pdr++;
        grd=0;
        break;
      }
    }
  }
  if(grda==0){
    if(Serial.available()>0){
      switch(apr){
        case 0:
        Serial.println("Ingrese la hora de la alarma");
        val=Serial.readString();
        num=val.toInt();
        am=num;
        apr++;
        break;
        case 1:
        val=Serial.readString();
        num=val.toInt();
        ah=num;
        pdr++;
        grda=1;
        break;
      }
    }
  }
  
}
void alarma(){
  Serial.println("Ingrese alarma minuto");
  grda=0;
  apr=0;
}
void reloj(){
  if(s<59){
    s++; 
  }
  else{
    s=0;
    if(m<59){
      m++;
    }
    else{
      m=0;
      if(h<23){
        h++;
      }
      else{
        h=0;
      }
    }
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Reloj:"+String(h)+String(":")+String(m)+String(":")+String(s));
  lcd.setCursor(0,1);
  lcd.print("Alarm:"+String(ah)+String(":")+String(am));
  if(h==ah){
    if(m==am){
      digitalWrite(ld,HIGH);
    }
    else{
      digitalWrite(ld,LOW);
    }
  }
  
}

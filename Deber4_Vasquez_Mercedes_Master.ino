/*
 * MASTER
 * Realice un sistema que codifique las vocales en palabras ingresadas por comunicación serial. Este mensaje se ingresa por comunicación serial en el master, este envía al esclavo para que realice la codificación por comunicación I2C. Luego, lo envía al master por el mismo medio y se muestra el resultado en una LCD en el master. La codificación es:

a=@

e=#

i= !

o = *

u= $

 

Ejemplo: CARRO = C@RR*
 */



#include<LiquidCrystal.h>
#include <Wire.h>
const int rs=13,en=12, d4=11, d5=10,d6=9,d7=8;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
int cont =0; 
String alm;
int guardar;
int tam;
char mensaje[15];
void setup() {
  Serial.begin(9600); 
   Serial.println("MASTER");
  Wire.begin();  
  lcd.begin(16,2);      
 
}

void loop() {
    if(Serial.available()>0){
        alm=Serial.readString();     
        tam=alm.length()+1;        
        char vect[tam];          
        alm.toCharArray(vect,tam);   
        Wire.beginTransmission(4);  
    Wire.write(vect);      
    Wire.endTransmission();  
   delay(1000);
   Wire.requestFrom(4,15);  
   while(Wire.available()>0)   {
    Serial.println(" ");
    Serial.println("Mensaje Recibido");
    char dato = Wire.read(); 
    if (dato != '\0')   {
        mensaje[guardar] = dato;
        guardar++;
    }
    else
        break;
      lcd.setCursor(0,0);           
      for(int a;a<19;a++){
      lcd.print(String(mensaje[a]));      
    }
  }
    
   }
} 

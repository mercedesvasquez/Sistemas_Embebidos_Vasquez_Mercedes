/*
 * Esclavo
 * 
 */
#include <Wire.h>
#include<LiquidCrystal.h>
const int rs=13,en=12, d4=11, d5=10,d6=9,d7=8;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
int guardar;
int tam;
String alm;
char mensaje[20];
String esclavo;
void setup() {
  Serial.begin(9600);
  Serial.println("ESCLAVO");
  Wire.begin(4);
  Wire.onReceive(Esclavo); 
  lcd.begin(16,2);
}

void loop() {
  delay(100) ;
}


void Esclavo()
{
 guardar=0;
  while(Wire.available()>0)   {
    char dato = Wire.read(); 
    if (dato != '\0')   {
        mensaje[guardar] = dato;
        guardar++;
    }
    else
        break;
  }
  for(byte i=0;i<=14;i++){
    lcd.setCursor(i, 1);
      lcd.print(mensaje[i]);
      delay(500);
    Serial.print(mensaje[i]);
  }
      for(int i=0;i<=14;i++){
        switch(mensaje[i]){
        case 'a':
        esclavo=esclavo+" @";  
        break;
        case 'e':
        esclavo=esclavo+" #"; 
        break;
        case 'i':
        esclavo=esclavo+" !";  
        break;
        case 'o':
        esclavo=esclavo+" *";  
        break;
        case 'u':
        esclavo=esclavo+" $"; 
        break;
        default: 
        esclavo=esclavo+" "+mensaje[i];
        }
    }
    Serial.println(" ");
    Serial.println(String(esclavo));
    alm=esclavo;
    tam=alm.length()+1;       
    char vect[tam];          
    alm.toCharArray(vect,tam);   
    Wire.write(vect);
    Serial.println(" ");
    Serial.println("Mensaje Enviado");
  
}

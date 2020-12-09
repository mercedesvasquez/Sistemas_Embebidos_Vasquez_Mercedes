/*
 * Realiza un programa que valide y actualice una contraseña almacenada en la memoria EEPROM. 
 * Como estado inicial, la contraseña es de 4 dígitos que son: 4563.
 */
#include <EEPROM.h>
 int prender=0;   
 int cont=0;    
 int contra;     
 int grd;     
int contra1 = 4563;    
 String alm;       
void setup() {
contra=EEPROM.read(0);         
EEPROM.update(0,4563);        
Serial.begin(9600);           
attachInterrupt(0,inicio,LOW);      
attachInterrupt(1,actualizar,LOW);       
}
void loop() {
    if(prender==2){                    
      if(cont==1){              
        if(Serial.available()>0){              
          alm=Serial.readString();                       
          contra=alm.toInt();              
          EEPROM.update(0,contra);             
          Serial.println("Se Guardo");           
        }
      }
      if(cont==0){              
        if(Serial.available()>0){              
          alm=Serial.readString();              
          grd=alm.toInt();             
          if(contra==grd){              
            Serial.println("Correcto");               
          }else{
            Serial.println("Incorrecto");              
          }
        }
      }
    }
}
void inicio(){                    
  switch(prender){                         
    case 0: 
    Serial.println("INICIO");     
    Serial.println("");             
    prender++;     
    break;
    case 1:
      switch(cont){
        case 1:
          Serial.println("Ingrese nueva contrasena");            
        break;
        case 0:
          Serial.println("Ingrese contrasena para verificar");             
        break;
        }
    prender++;               
    break;
    case 2:          
    cont=0;              
    prender=0;              
    break;
  }
}
void actualizar(){        
  if(prender==1){            
    switch(cont){
      case 0:
        Serial.println("Actualizar contrasena");              
        cont=1;               
      break;
       case 1:
       Serial.println("Verificar contrasena");              
        cont=0;               
       break;
    }
  }
}

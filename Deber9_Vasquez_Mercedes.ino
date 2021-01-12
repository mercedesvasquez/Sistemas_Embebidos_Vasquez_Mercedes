/*
 * UNIVERSIDAD TÉCNICA DEL NORTE 
 * Mercedes Vásquez
 * Deber 9:Realice un programa que mediante un conversor 
 * análogo-digital se configure el tiempo de reinicio del 
 * perro guardián (tiempos seleccionados por el usuario). 
 * Envíe mensajes por comunicación serial validando todo 
 * el proceso. 
*/
#include <avr/wdt.h>
#include<MsTimer2.h>

int cont = 0,boton,aux,modo=0;

void setup(){
  Serial.begin(9600);
  MsTimer2::set(1000,reloj);
  attachInterrupt(0,encender,LOW);
}

void loop() {

 if(encender==1){
  receteo();
 }

}

void encender(){
  switch(modo){
    case 0:
      Serial.println("Encendido");
      Serial.println("Gire el potenciometro para recetear");
      modo++;
    break;

    case 1:
      MsTimer2::start();
      modo++;
    break;

    case 2:
      Serial.println("Apagado");
      modo=0;
      MsTimer2::stop();
    break;
    }
  }
void receteo (){
       boton=analogRead(0);
       boton=map(boton,0,1023,0,100);
       aux=boton;
       Serial.println(" ");
       Serial.println(String("Proceso receteado en: ")+String(aux)+String(" seg"));
       delay(1000);
       Serial.println(" ");
    
}
void reloj() {
  cont++;
 Serial.println(String("Conteo: ")+String(cont));
  if (cont>=aux){
  wdt_disable();
  wdt_enable(WDTO_250MS); 
  }
}

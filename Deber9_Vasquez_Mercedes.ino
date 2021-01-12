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

int cont = 0;
int encender = 0;
int analog = 0;
int t=0;
int aux=1;

void setup(){
  Serial.begin(9600);
  Serial.println("INICIO");
  MsTimer2::set(1000, reloj);
  attachInterrupt(0,reset,LOW);
}

void loop() {
  if(encender==1){
    analog = analogRead(0);
    t = map(analog, 0, 1023, 0, 60);
    delay(50);
    if (aux!=t){
      Serial.println(String("Tiempo: ")+String(t));  
    }
    aux = t;
  }
}

void reloj() {
  cont++;
  if (cont==t){
  wdt_disable();
  wdt_enable(WDTO_500MS);
  }
}

void reset() {
  switch(encender){
    case 0:
      Serial.println("Iniciado");
      Serial.println("Gire el potenciometro para resetear");
      encender++;
    break;
    
    case 1:
      Serial.println(String("Reseteo en: ")+String(t)+String(" segundos"));
      MsTimer2::start();
      encender=0;
    break;
  }
}

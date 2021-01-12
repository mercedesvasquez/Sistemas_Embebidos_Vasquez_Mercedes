/*
 * UNIVERSIDAD TÉCNICA DEL NORTE 
 * Mercedes Vásquez
 * Deber 8: Realizar un código que el sistema se reinicia cada minuto 
 * active el conversor análogo-digital realice una lectura y 
 * vuelve el sistema a un modo sleep.
*/
#include<avr/power.h>
#include<avr/sleep.h>
#include<avr/wdt.h>
#include<MsTimer2.h>

int modos=0; // modos del sistema
int tiempo=0; //tiempo de toma de datos
int cont=0; // conteo de timer

void setup(){
Serial.begin(9600);
MsTimer2::set(1000,reloj);
attachInterrupt(0,encender, LOW);

}

void loop() {
delay(1000);
}
void encender(){
  switch(modos){
    case 0:
    tiempo=60;
    Serial.println("Encendido");
    MsTimer2::start();
    modos++;
    break;

    case 1:
    Serial.println("Apagado");
    tiempo=0;
    modos=0;
    cont=0;
    MsTimer2::stop();
    power_adc_disable();
    break;
    
    }
  }
void reloj(){
  if (cont != 1){
    power_adc_disable();
    }
    else
    {
      power_adc_enable();
      delay(50);
      Serial.println(String("lectura en:")+String(analogRead(0)));
    }
    if (cont==60){
      cont=0;
      }
      cont++;
      power_adc_disable();
}
  

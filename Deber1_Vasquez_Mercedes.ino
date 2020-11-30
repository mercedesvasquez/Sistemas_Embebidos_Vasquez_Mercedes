/*
 * DEBER #1
 * Estimados estudiantes, realizar el siguiente codigo y solo adjuntar en enlace de su repositorio en GitHub.

Realizar un programa que accione mediante 4 switchs a un juego de luces diferente. Es decir.

sw3   sw2  sw1  sw0

0        0       0        1            Juego 1

0        0       1        0            Juego 2

0        1       0        0            Juego 3

1        0       0        0            Juego 4

 

Juego #1

Se usan 6 leds, de los cuales se encienden los pares por 10 ocasiones

Juego #2

Se usan 6 leds, de los cuales se encienden los impartes por 10 ocasiones

Juego #3

Se encienden secuencialmente cada uno ellos (flexible a su criterio)

Juego #4

Su propio diseño de juego. 

 
 */
 const int ld1=8;
 const int ld2=9;
 const int ld3=10;
 const int ld4=11;
 const int ld5=12;
 const int ld6=13;
 const int sw1=7;
 const int sw2=6;
 const int sw3=5;
 const int sw4=4;
 int a=0;
 int b=0;
 int c=0;
 int d=0;
void setup() {
  // put your setup code here, to run once:
   pinMode(ld1,OUTPUT);//8
   pinMode(ld2,OUTPUT);//9
   pinMode(ld3,OUTPUT);//10
   pinMode(ld4,OUTPUT);//11
   pinMode(ld5,OUTPUT);//12
   pinMode(ld6,OUTPUT);//13

   // Para los switch 
    pinMode(sw1,INPUT);//7
    pinMode(sw2,INPUT);//6
    pinMode(sw3,INPUT);//5
    pinMode(sw4,INPUT);//4

}

void loop() {
  // put your main code here, to run repeatedly:
  //Juego 1
  if (digitalRead(sw1)==HIGH){
    if(a<10){
      digitalWrite(ld2,HIGH);
      digitalWrite(ld4,HIGH);
      digitalWrite(ld6,HIGH);
      delay(700);
      
      digitalWrite(ld2,LOW);
      digitalWrite(ld4,LOW);
      digitalWrite(ld6,LOW);
      delay(700);
      a++;
    }
    
  }
  else
  {
    digitalRead(sw2&&sw3&&sw4)==LOW;
  }

//Segundo Juego
   if (digitalRead(sw2)==HIGH){
    if(b<10){
      digitalWrite(ld1,HIGH);
      digitalWrite(ld3,HIGH);
      digitalWrite(ld5,HIGH);
      delay(700);
      
      digitalWrite(ld1,LOW);
      digitalWrite(ld3,LOW);
      digitalWrite(ld5,LOW);
      delay(700);
      b++;
    }
    
  }
  //Tercer Juego
  if (digitalRead(sw3)==HIGH){
    if(c<15){
      digitalWrite(ld1,HIGH);
      delay(500);
      digitalWrite(ld2,HIGH);
      delay(500);
      digitalWrite(ld3,HIGH);
      delay(500);
      digitalWrite(ld4,HIGH);
      delay(500);
      digitalWrite(ld5,HIGH);
      delay(500);
      digitalWrite(ld6,HIGH);
      delay(500);
      
      digitalWrite(ld6,LOW);
      delay(500);
       digitalWrite(ld5,LOW);
      delay(500);
      digitalWrite(ld4,LOW);
      delay(500);
       digitalWrite(ld3,LOW);
      delay(500);
      digitalWrite(ld2,LOW);
      delay(500);
       digitalWrite(ld1,LOW);
      delay(500);
      c++;
    }
    
  }  

  // Cuarto Juego
 if (digitalRead(sw4)==HIGH){
    if(d<50){
      digitalWrite(ld1,HIGH);
      delay(200);
      digitalWrite(ld1,LOW);
      delay(200);
      
      digitalWrite(ld6,HIGH);
      delay(150);
     
      digitalWrite(ld6,LOW);
      delay(150);

      digitalWrite(ld3,HIGH);
      digitalWrite(ld4,HIGH);
    
      delay(300);
      
      digitalWrite(ld4,LOW);
      digitalWrite(ld3,LOW);
      delay(300);

      digitalWrite(ld2,HIGH);
      delay(150);
      digitalWrite(ld2,LOW);
      delay(150);
     
      digitalWrite(ld5,HIGH);
      delay(200);
      digitalWrite(ld5,LOW);
      delay(200);
      
      
      d++;
    }
    
  }  
  

}

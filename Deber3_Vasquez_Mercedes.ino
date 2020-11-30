/*
 * DEBER 3
 * Realizar un programa de juego de preguntas. Se debe tener mínimo 8 preguntas que deben observarse en orden aleatorio. La forma de visualización es por medio de comunicación serial. Su respuesta solo debe ser "SI" y "NO" ingresadas de la misma forma por comunicación serial.

Al final de mostrar solo 5 de las 8 preguntas. Se presentan el puntaje (respuestas acertadas) en un display.

 
 */
const int A= 8; // pin 8 conectado a decodificador
const int B= 9; // pin 9 conectado a decodificador
const int C=10; // pin 10 conectado a decodificador
const int D=11; // pin 11 conectado a decodificador
String p1="1+3 es 4?";
String p2="Quito es la capital de Ecuador";
String p3="America fue descubierta en 1592";
String p4=" El cuerpo humano tiene 196 huesos";//
String p5="La formula del agua es H2O";
String p6="El hidrogeno es el elemento mas abundante";
String p7="La intensidad de una corriente eléctrica se mide por el amperio";
String p8="Mark Zuckerberg invento Instagram";
String pp1="1",pp2="2",pp3="3",pp4="4",pp5="5",pp6="6",pp7="7",pp8="8";
int ppp1=0,ppp2=0,ppp3=0,ppp4=0,ppp5=0,ppp6=0,ppp7=0,ppp8=0;
 int resultado =0;

String alm,alm2;

void setup() {
 Serial.begin(9600);
  pinMode(A,OUTPUT); // pin8 declarado como salida
  pinMode(B,OUTPUT); // pin9 declarado como salida
  pinMode(C,OUTPUT); // pin10 declarado como salida
  pinMode(D,OUTPUT); // pin11 declarado como salida
 Serial.println("JUEGO DE PREGUNTAS ");


}

void loop() {
 

    alm=Serial.readString();
   
    if (alm==pp1){
      Serial.println(" ");
      Serial.println(p1);
      delay(3000);
     if (Serial.available()>0){
      alm2=Serial.readString();
      if (alm2=="si"){
        
        Serial.println("\n Muy bien");
        ppp1=1;
        
      }else{
        Serial.println("\nIncorrecto");}
      
     }
      
      
    }

    //
      if (alm==pp2){
      Serial.println(" ");
      Serial.println(p2);
      delay(3000);
     if (Serial.available()>0){
      alm2=Serial.readString();
      if (alm2=="si"){
        
        Serial.println("\n Muy bien");
        ppp2=1;
        
      }else{
        Serial.println("\nIncorrecto");}
      
     }
      
      
    }
    if (alm==pp3){
      Serial.println(" ");
      Serial.println(p3);
      delay(3000);
     if (Serial.available()>0){
      alm2=Serial.readString();
      if (alm2=="no"){
        
        Serial.println("\nMuy bien");
        ppp3=1;
      }else{
        Serial.println("\nIncorrecto");}
      
     }
      
      
    }

    if (alm==pp4){
      Serial.println(" ");
      Serial.println(p4);
      delay(3000);
     if (Serial.available()>0){
      alm2=Serial.readString();
      if (alm2=="no"){
        
        Serial.println("\n Muy bien");
        ppp4=1;
        
      }else{
        Serial.println("\nIncorrecto");}
      
     }
 
    }

    if (alm==pp5){
      Serial.println(" ");
      Serial.println(p5);
      delay(3000);
     if (Serial.available()>0){
      alm2=Serial.readString();
      if (alm2=="si"){
        
        Serial.println("\n Muy bien");
        ppp5=1;
      }else{
        Serial.println("\nIncorrecto");}
      
     }

    }
    if (alm==pp6){
      Serial.println(" ");
      Serial.println(p6);
      delay(3000);
     if (Serial.available()>0){
      alm2=Serial.readString();
      if (alm2=="si"){
        
        Serial.println("\n Muy bien");
        ppp6=1;
      }else{
        Serial.println("\nIncorrecto");}
      
     }
      
      
    }

    if (alm==pp7){
      Serial.println(" ");
      Serial.println(p7);
      delay(3000);
     if (Serial.available()>0){
      alm2=Serial.readString();
      if (alm2=="si"){
        
        Serial.println("\n Muy bien");
        ppp7=1;
        
      }else{
        Serial.println("\nIncorrecto");}
      
     }
      
      
    }
    if (alm==pp8){
      Serial.println(" ");
      Serial.println(p8);
      delay(3000);
     if (Serial.available()>0){
      alm2=Serial.readString();
      if (alm2=="no"){
        
        Serial.println("\n Muy bien");
        ppp8=1;
      }else{
        Serial.println("\nIncorrecto");}
      
     }
      
      
    }
    resultado=ppp1+ppp2+ppp3+ppp4+ppp5+ppp6+ppp7+ppp8;
    if(resultado==0){
          digitalWrite(A,LOW); //Envía 0 voltios a pin 8
          digitalWrite(B,LOW); //Envía 0 voltios a pin 9
          digitalWrite(C,LOW); //Envía 0 voltios a pin 10
          digitalWrite(D,LOW); //Envía 0 voltios a pin 11
      }
    if(resultado==1){
          digitalWrite(A,HIGH); //Envía 5 voltios a pin 8
          digitalWrite(B,LOW);  //Envía 0 voltios a pin 9
          digitalWrite(C,LOW);  //Envía 0 voltios a pin 10
          digitalWrite(D,LOW);  //Envía 0 voltios a pin 11
      }
        if(resultado==2){
          digitalWrite(A,LOW);  //Envía 0 voltios a pin 8
          digitalWrite(B,HIGH); //Envía 5 voltios a pin 9
          digitalWrite(C,LOW);  //Envía 0 voltios a pin 10
          digitalWrite(D,LOW);  //Envía 0 voltios a pin 11
      }
        if(resultado==3){
          digitalWrite(A,HIGH); //Envía 5 voltios a pin 8
          digitalWrite(B,HIGH); //Envía 5 voltios a pin 9
          digitalWrite(C,LOW);  //Envía 0 voltios a pin 10
          digitalWrite(D,LOW);  //Envía 0 voltios a pin 11
      }
        if(resultado==4){
          digitalWrite(A,LOW);  //Envía 0 voltios a pin 8
          digitalWrite(B,LOW);  //Envía 0 voltios a pin 9
          digitalWrite(C,HIGH); //Envía 5 voltios a pin 10
          digitalWrite(D,LOW);  //Envía 0 voltios a pin 11
      }
        if(resultado==5){
          digitalWrite(A,HIGH); //Envía 5 voltios a pin 8
          digitalWrite(B,LOW);  //Envía 0 voltios a pin 9
          digitalWrite(C,HIGH); //Envía 5 voltios a pin 10
          digitalWrite(D,LOW);  //Envía 0 voltios a pin 11
      }
        if(resultado==6){
          digitalWrite(A,LOW);  //Envía 0 voltios a pin 8
          digitalWrite(B,HIGH); //Envía 5 voltios a pin 9
          digitalWrite(C,HIGH); //Envía 5 voltios a pin 10
          digitalWrite(D,LOW);  //Envía 0 voltios a pin 11
      }
        if(resultado==7){
          digitalWrite(A,HIGH); //Envía 5 voltios a pin 8
          digitalWrite(B,HIGH); //Envía 5 voltios a pin 9
          digitalWrite(C,HIGH); //Envía 5 voltios a pin 10
          digitalWrite(D,LOW);  //Envía 0 voltios a pin 11
      }

        if(resultado==8){
          digitalWrite(A,LOW); //Envía 0 voltios a pin 8
          digitalWrite(B,LOW); //Envía 0 voltios a pin 9
          digitalWrite(C,LOW); //Envía 0 voltios a pin 10
          digitalWrite(D,HIGH); //Envía 5 voltios a pin 11
      }



}

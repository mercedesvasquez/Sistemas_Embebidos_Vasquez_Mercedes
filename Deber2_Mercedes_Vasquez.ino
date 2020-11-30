/* Deber 2
 * Estimados estudiantes, realizar el siguiente código y solo adjuntar su enlace al repositorio de su cuenta GitHub.

Realizar un programa que al presionar el pulsador cada vez, se visualiza a cada número primo hasta el 99. 
 */

 const int  A= 8; // pin 8 decodificador 7447
 const int  B= 9; // pin 9 decodificador
 const int  C=10; // pin 10 decodificador
 const int  D=11; // pin 11 decodificador
 const int  display1=12; // display unidades
 const int  display2=13; // display decenas
 const int  b=7; //pin 7 
 int unidades=0;
 int decenas=0;
 int cont=0; 

void setup() {
  pinMode(A,OUTPUT); // pin8 
  pinMode(B,OUTPUT); // pin9 
  pinMode(C,OUTPUT); // pin10 
  pinMode(D,OUTPUT); // pin11 
  pinMode(display1,OUTPUT); 
  pinMode(display2,OUTPUT); 
  pinMode(b,INPUT);  

}

void loop() {
  if(digitalRead(b)==HIGH){
  delay(500);

  for(cont=2;cont<=99;cont++){              
  
    bool np=true;// variable número primo
    for(int n=2;n<cont&& np== true; n++) {
    if(cont % n == 0)  {
      np=false;
      }              
    }
    if(np){
       if(cont<10){             
      unidades=cont;
    decenas=0;              
      }
      else{                  
       decenas=cont/10;          
       unidades=cont-decenas*10;      
       }
        digitalWrite(display1,HIGH);   
        digitalWrite(display2,LOW);   
        deco(unidades);            
        delay(500);                
        digitalWrite(display1,LOW);    
        digitalWrite(display2,HIGH);   
        deco(decenas);            
        delay(500);
                     
    }

    }
                 
  }     

}

//Crear método para que se impriman los números
void deco (int imprimir){
   switch(imprimir){
        case 0:
          digitalWrite(A,LOW); 
          digitalWrite(B,LOW); 
          digitalWrite(C,LOW); 
          digitalWrite(D,LOW); 
        break;
        case 1:
          digitalWrite(A,HIGH); 
          digitalWrite(B,LOW);  
          digitalWrite(C,LOW);  
          digitalWrite(D,LOW);  
        break;
        case 2:
          digitalWrite(A,LOW);  
          digitalWrite(B,HIGH); 
          digitalWrite(C,LOW);  
          digitalWrite(D,LOW);  
        break;
        case 3:
          digitalWrite(A,HIGH); 
          digitalWrite(B,HIGH); 
          digitalWrite(C,LOW);  
          digitalWrite(D,LOW);  
        break;
        case 4:
          digitalWrite(A,LOW);  
          digitalWrite(B,LOW);  
          digitalWrite(C,HIGH); 
          digitalWrite(D,LOW);  
        break;
        case 5:
          digitalWrite(A,HIGH); 
          digitalWrite(B,LOW);  
          digitalWrite(C,HIGH); 
          digitalWrite(D,LOW);  
        break;
        case 6:
          digitalWrite(A,LOW);  
          digitalWrite(B,HIGH); 
          digitalWrite(C,HIGH); 
          digitalWrite(D,LOW);  
        break;
        case 7:
          digitalWrite(A,HIGH); 
          digitalWrite(B,HIGH); 
          digitalWrite(C,HIGH); 
          digitalWrite(D,LOW);  
        break;
        case 8:
          digitalWrite(A,LOW); 
          digitalWrite(B,LOW); 
          digitalWrite(C,LOW); 
          digitalWrite(D,HIGH); 
        break;
        case 9:
          digitalWrite(A,HIGH); 
          digitalWrite(B,LOW);  
          digitalWrite(C,LOW);  
          digitalWrite(D,HIGH); 
        break;
      }
  }

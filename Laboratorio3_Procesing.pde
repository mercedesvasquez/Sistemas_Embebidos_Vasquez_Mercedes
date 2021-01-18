/*
LABORATORIO 3
JUEGO Ping Pong
Mercedes Vásquez
*/


import processing.serial.*;
import ddf.minim.*;
Minim pacman;
AudioPlayer play1;
PImage img; 
Serial port;
int pY=350;//posicion
int pdY=350;//posicion der
// posicion inicial de la elipse en el medio
float ellx=width/2;
float elly=height/2;

// Movimientos
boolean movArriba=true;
boolean movAbajo=true;

float velLado=3;//velocidad de lado
float velVertical=4;

int punDer=0; // puntaje para el lado derecho
int puntIzq=0; // puntaje para el lado izquierdo

String dato;
PFont font;
int y,x;//imagen
void setup(){
  size(700,700);
  background(0);//color
  font= loadFont("lab.vlw");
  pacman=new Minim(this);
  play1=pacman.loadFile("pacman.wav");
  img=loadImage("pong.png");//pegar imagen
  
  port= new Serial(this, "COM10",9600);
}

void draw(){
  background(#CFFAEA);// color fondo
  textFont(font);
  image(img,180,15,45,45);
  if(play1.isPlaying()){
  }
  else{
   play1.rewind();
   play1.play();
  }
  
  stroke(255,255,255);
  strokeWeight(5);
  line(350,60,350,699);//punto de inicio, punto de fin
  //
  noStroke();
  fill(79,229,245);
  ellipse(ellx,elly,50,50);
  text("Ping Pong",250,40);
  
  fill(227,119,240);
  rect(20,pY,30,100);
  text(puntIzq,100,50);
  
  fill(255,213,106);
  rect(630,pdY,30,100);
  text(punDer,600,50);
  while (port.available() > 0) {
    dato=port.readString();
 //A-> IZQ
 //B->DER
 //C-> UP
 //D-> DOWN
 
 switch (dato){
   case "A":
   pY=pY-50;// lado izquierdo el valor de la velocidad no tenemos que cambiarlo tanto
   break;
   case "B":
   pdY=pdY+50;
   break;
   case "C":
   pdY=pdY-50;
   break;
   case "D":
   pY=pY+50;//lado izquierdo
   break;
 }
 
  }

  // mover
  
  if(movArriba == true){
    ellx=ellx+velLado;
  }
  else{
    ellx=ellx-velLado;
  }
  if(movAbajo == true){
    elly=elly+velVertical;
  }
  else{
    elly=elly-velVertical;
  }
  
  if(elly <= 10){
    movAbajo = true;
    velLado=random(3,6);
  }
  if(elly >= 690){
    movAbajo = false;
    velLado=random(3,6);
  }
  if(ellx >= 690){
    puntIzq++;
    ellx=width/2;
    elly=width/2;
    velLado=random(3,6);
  }
  if(ellx <= 10){
    punDer++;
    ellx=width/2;
    elly=width/2;
    velLado=random(3,6);
  }
  
  if(ellx>=615 && elly > pdY && elly < (pdY+100)){
    movArriba=false;
    velLado=random(3,6);
  }
  if(ellx <= 75 && elly > pY && elly < (pY+100)){
    movArriba=true;
    velLado=random(3,6);
  }
  
}

/*
Laboratorio 4
Mercedes Vasquez
Realizar un interfaz donde se evidencie el proceso de aprendizaje de m´aquina realizado por el sistema
embebido
*/
import processing.serial.*;
Serial port; // objeto para puerto COM
float datoes; //dato estatura
int d;
float dato,estatura,peso;//
void setup(){
size(1000,900);
background(#FBFCDE);
port= new Serial(this, "COM10",9600);
textSize(20);
  fill(0);
  text("0",85,750);
  text("10",70,700);
  text("20",70,650);
  text("30",70,600);
  text("40",70,550);
  text("50",70,500);
  text("60",70,450);
  text("70",70,400);
  text("80",70,350);
  fill(#6DF5C8);
  text("Peso",35,300);
  
  //horizontal
  fill(0);
  text("155",75,775);
  text("160",185,775);
  text("165",280,775);
  text("170",380,775);
  text("175",480,775);
  text("180",580,775);
  text("185",680,775);
  fill(#6DF5C8);
  text("Altura",750,775);
  textSize(25);
  fill(0);
  text("Laboratorio 4",400,50);
  text("Ecuación y=-133.39+1.18x",50,100);
  text("Regresión Lineal, con tendencia lineal",250,150);
  text("Mercedes Vásquez",50,850);
  text("Datos de entrenamiento",50,200);
  text("Datos ingresados por comunicación serial(pruebas)",50,250);
  stroke(#FF5281);
  fill(#FF5281);
  ellipse(370,195,20,20);
  stroke(#4334D6);
  fill(#4334D6);
  ellipse(695,240,20,20);
}

void draw (){
  //datos de estatura y peso
  stroke(#244274);
  strokeWeight(1);
  noFill();
  rect(100,300,600,450);// rectangulo cuadricula
  for(int i=0;i<7;i++){
    stroke(#244274);
    strokeWeight(1);
    line(100+i*100,300,100+i*100,750);//x,y,xf,yf // verticales x es igual
  }
  for(int j=0;j<9;j++){
    stroke(#244274);
    strokeWeight(1);
    line(100,300+j*50,700,300+j*50);// horizontales y es igual
  }
  
  stroke(#FF5281);
  fill(#FF5281);
  strokeWeight(3);
  ellipse(100+(170-155)*(600/30),750-(67-0)*450/90,5,5);// x*para escala,y,ancho,altura
  ellipse(100+(180-155)*(600/30),750-(80-0)*450/90,5,5);
  ellipse(100+(170-155)*(600/30),750-(65-0)*450/90,5,5);
  ellipse(100+(178-155)*(600/30),750-(75-0)*450/90,5,5);
  ellipse(100+(160-155)*(600/30),750-(55-0)*450/90,5,5);
  ellipse(100+(163-155)*(600/30),750-(60-0)*450/90,5,5);
  ellipse(100+(165-155)*(600/30),750-(63-0)*450/90,5,5);
  ellipse(100+(170-155)*(600/30),750-(70-0)*450/90,5,5);
  ellipse(100+(164-155)*(600/30),750-(62-0)*450/90,5,5);
  ellipse(100+(176-155)*(600/30),750-(77-0)*450/90,5,5);
  ellipse(100+(164-155)*(600/30),750-(60-0)*450/90,5,5);
  ellipse(100+(170-155)*(600/30),750-(76-0)*450/90,5,5);
  ellipse(100+(170-155)*(600/30),750-(56-0)*450/90,5,5);
  ellipse(100+(168-155)*(600/30),750-(60-0)*450/90,5,5);
  //la formula de la ecuacion y=-133.39+1.18x
  stroke(#ABFF8B);
  strokeWeight(1);
  line(100+(160-155)*(600/30),750-(55-0)*450/90,100+(180-155)*(600/30),750-(80-0)*450/90);
  
  
  
  //imprimir nuevos datos enviados por serial
 
 
  
  if(port.available()>0){
    while(d==0){
    dato=port.read();
    estatura=int(dato); //Convertir de string a int
    println("Dato1");
    println(dato);
    d++;
    }
    while(d==1){
    peso=port.read();
    println("Dato2");
    println(peso);
    d=0;
    }
  
  }
  //graficar
  stroke(#4334D6);
  fill(#4334D6);
  strokeWeight(3);
  ellipse(100+(estatura-155)*(20),750-(peso-0)*(5),5,5);
  

  
}

/*
*********Universidad Técnica del Norte********
*******************FICA-CITEL*****************
***************SISTEMAS EMBEBIDOS*************
Mercedes Vásquez
********************DEBER 10******************
Realice una interfaz que permita mover una esfera por toda la pantalla mediante teclas.
Teclas 37 flecha izq, 38 flecha arriba, 39 flecha derecha, 40 flecha abajo
*/

int x=450, y=300;//450 centro
int mov=10;
int r=100;

void setup(){
  size(900,600);
  background(209,250,233);//color de fondo RGB
}
void draw(){
  background(209,250,233);//borrar figura movimiento
  fill(#EAA6D4);
  ellipse(x,y,r,r);
  if(x>=850)
  x= 850;
  if(x<=50) 
  x=50;
  if(y>=550) 
  y=550;
  if(y<=50) 
  y=50;
}
void keyPressed(){
switch(keyCode){
      case 37: 
          x=x-mov;
      break;
      case 38: 
          y=y-mov;
 
      break;
      case 39: 
          x=x+mov;
      break;
      case 40: 
          y=y+mov;
      break;
      default:
      break;
    }
  
}

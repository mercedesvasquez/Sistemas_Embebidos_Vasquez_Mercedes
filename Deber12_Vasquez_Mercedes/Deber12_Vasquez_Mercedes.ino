/*
 * Deber 12
 * Bayesiano
 */


#include <ListLib.h>
#include "datos.h" // datos filtrados, aire puro aire contaminado
#include "prueba.h" // datos de prueba, aire puro, aire contaminado
int resultado;
int eti = 2;
int col = 3;
int fil = 182; 
float radio = 0.3;
int i=0; // variable de recorrido en matriz
int j=0; // variable de recorrido en matriz
int k=0; // variable de recorrido en matriz
int t=0; // variable de recorrido en matriz
float p_x=0.0; // probabilidad marginal
float distancia=0.0; 
float sumatoria=0.0;
float normalizador=0.0;
float dist_mayor=0.0001;
float aux=0; 
int var = 0;
List <int> list; 
float datos_prueba[3]={232.56,90.44,1};// datos de prueba
//float datos_prueba[3]={matriz1[var][0],matriz1[var][1],matriz1[var][2]}; 
void setup() {
Serial.begin(9600);
Serial.println("Ingrese la fila del valor a realizar");
}
void loop() {
//  if (Serial.available() > 0) {
//    var = int(Serial.read());
//    float datos_prueba [3]={matriz1[var][0],matriz1[var][1],matriz1[var][2]}; 
//    Serial.println(matriz1[var][0]);
//    Serial.println(matriz1[var][1]);
//    Serial.println(matriz1[var][2]);
//    delay(500);
     bayes(); // llamada al metodo 
//  }
  
}
void bayes(){
   float prob [4][eti];
    for(i=0;i<4;i++){
       for(j=0;j<eti;j++){  
          prob[i][j]=0;            
          if(i==0)                 
          prob[i][j]=j+1;         
        }
      }
    for(i=0;i<eti;i++){               
        for(j=0;j<fil;j++){               
          if(matriz[j][col-1]==i+1)    
            prob[1][i]++;                  
          }
      }
    for(i=0;i<fil;i++){
       for(j=0;j<col-1;j++){
         sumatoria=sumatoria+pow(matriz[i][j]-datos_prueba[j],2); 
        }
        distancia=sqrt(sumatoria); 
        sumatoria=0;
        if(distancia>dist_mayor)
          dist_mayor=distancia; 
      }
      distancia=0; 
    for(i=0;i<fil;i++){
       for(j=0;j<col-1;j++){
         sumatoria=sumatoria+pow(matriz[i][j]-datos_prueba[j],2);
       }
        distancia=sqrt(sumatoria); 
        sumatoria=0;
        normalizador=distancia/dist_mayor; 
        if(normalizador<radio)
            list.Add(i); 
    }
    // sumar por etiqueta a todos los datos que se encuentran en la circuferencia
    for(i=0;i<list.Count();i++){                         
      for(j=0;j<eti;j++){                           
          if(matriz[list[i]][col-1]==prob[0][j])    
            prob[2][j]++;                                 
        }
      }
      p_x=float(list.Count())/float(fil); 
   for(i=0;i<eti;i++){  // encontrar la probabilidad por etiqueta
      prob[3][i]=((prob[1][i]/fil)*(prob[2][i]/prob[1][i]))/p_x;
    }
      for(i=0;i<eti;i++){
         if(prob[3][i]>aux){
           resultado=int(prob[0][i]);
           aux=prob[3][i];
          }   
        }
  Serial.println(resultado);
  switch(resultado){
    case 1:
      Serial.println("Aire Puro"); 
    break;
    case 2:
    Serial.println("Aire Contaminado");
    break;
    }
    //if(matriz1[cont][2]==resultado){
    //porcent++;
}

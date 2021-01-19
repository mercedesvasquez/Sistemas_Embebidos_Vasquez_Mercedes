/*
 * Deber 11
 * EXPONENCIAL 
 * Y=Ae^Bx ^
 * DEBER 11: Realice la regresión lineal exponencial dentro del entorno de Arduino con el conjunto de datos estatura-peso. 
   Con esto, ingrese por comunicación serial los nuevos datos de estatura e imprima el pronóstico del peso.
*/

// matriz de datos
int matriz[14][2]={
  {170,67},
  {180,80},
  {170,65},
  {178,75},
  {160,55},
  {163,60},
  {165,63},
  {170,70},
  {164,62},
  {176,77},
  {164,60},
  {170,76},
  {170,56},
  {168,60},
};

int col=0; //moverse en columnas
int fil=0; //moverse en filas
int Ex=0; //sumatoria x
long int Exy=0; //sumatoria x*y
long int Ex2=0; //sumatoria x^2
long int Ex_2=0; //sumatoria (Ex)^2
int n= 14; //tamano de muestras
float B; //ordenada en el origen(n(EXY')-(Ex)(EY')/nEx^2-(EX)^2)
float A; // (e^A'x)-> A'=MEDIA Y'-B(MEDIAX)
float Ap;
float Exyp=0;// xy'
float Eyp=0;//sumatoria y'
String dato; //recibir estatura
int estatura; //convertir dato
float peso;
float n1=0;


void setup() {
  //Generar modelo
  Serial.begin(9600);
  for(;fil<n;fil++){
    Ex=Ex+matriz[fil][0];//sumatoria x
    Eyp=Eyp+log(matriz[fil][1]);//sumatoria de y'
    Exyp=Exyp+(matriz[fil][0]*log(matriz[fil][1]));
    Ex2=Ex2+pow(matriz[fil][0],2);
  }
  Ex_2=pow(Ex,2);
  B=(float(n*(Exyp))-float(Ex*Eyp))/(float(n*Ex2-Ex_2));
  Ap=(Eyp/n)-B*(Ex/n);
  A=exp(Ap);
  
  Serial.println("El modelo exponencial es: ");
  Serial.println(String("y= ")+String(A)+String("*e^")+String(B)+String("x"));
  Serial.println("Ingrese su estatura: ");
}

  


void loop() {
  if(Serial.available()>0){
    dato=Serial.readString();
    estatura=dato.toInt();
    peso=A*exp(B*estatura);
    Serial.println("");
    Serial.println(String("Su peso es: ")+String(peso)+String("Kg"));
    Serial.println("Ingrese su estatura: ");
   
  }

}

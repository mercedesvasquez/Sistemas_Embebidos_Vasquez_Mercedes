//Suavizado de la senal


#define tam_sig 74 //tamaño de la señal

//Import signal to another .h file
extern double co[tam_sig];
//extern double Impulse_response[tam_imp];

//double output[tam_sig+tam_imp]; //vector de salida
double output_signal[tam_sig];
double SNR[tam_sig];
//void convolucion(double *sig_in,double *sig_out, double *imp, int sig_tam, int imp_tam);// definir funcion
void mediana (double *sig_in, double *output_signal, int sig_tam, int filter);
void plot_signal(void);

void setup() {
  Serial.begin(9600);

}

void loop() {
  mediana ((double *)&co[0], (double *)&output_signal[0], (int) tam_sig,5);
  SNRs();
  plot_signal();
  delay(100);

}

//////////////////////FILTROS FIR/////////////7


//////SUAVIZADO DE  LA SEÑAL Mediana ////////////////////////////
void mediana (double *sig_in, double *output_signal, int sig_tam, int filter){
  int i,j,val,num,alm;
  double filtrado[filter];
  for(val=0;val<sig_tam;val++){
    
    for(num=0;num<filter;num++){
      filtrado[num]=sig_in[val+num];
    }
    for(i=0;i<(filter-3);i++){
      for(j=i+1;j<filter-1-i;j++){
        if(filtrado[j]<filtrado[i]){
          alm=filtrado[j];
          filtrado[j]=filtrado[i];
          filtrado[i]=alm;
        }
      }
    }
   output_signal[val]=filtrado[1];
  }
  
    
  }
void SNRs(){
  double snr[tam_sig];
  double snr2[tam_sig];
  for(int i=0;i<tam_sig;i++){
    snr[i]=pow(co[i],2);
    snr2[i]=pow((co[i]-output_signal[i]),2);
    SNR[i]=10*log(snr[i]/snr2[i]);
    
  }
}
void plot_signal(void){ //puede ir sin void pero se pone para una manera mejor estrutura 
  int i;
  for(i=0;i<tam_sig;i++){
    Serial.print(co[i]+1000);
    Serial.print(",");
    Serial.print(output_signal[i]+5);
    Serial.print(",");
    Serial.println(SNR[i]);
    delay(5);
  }
}

//Suavizado de la senal


#define tam_sig 74 //tamaño de la señal

//Import signal to another .h file
extern double co[tam_sig];
//extern double Impulse_response[tam_imp];

//double output[tam_sig+tam_imp]; //vector de salida
double output_signal[tam_sig];
double SNR[tam_sig];
//void convolucion(double *sig_in,double *sig_out, double *imp, int sig_tam, int imp_tam);// definir funcion
void media (double *sig_in, double *output_signal, int sig_tam, int filter);
void plot_signal(void);

void setup() {
  Serial.begin(9600);

}

void loop() {
  media ((double *)&co[0], (double *)&output_signal[0], (int) tam_sig,5);
  SNRs();
  plot_signal();
  delay(100);

}

//////////////////////FILTROS FIR/////////////7


//////SUAVIZADO DE  LA SEÑAL Mediana ////////////////////////////
void media (double *sig_in, double *output_signal, int sig_tam, int filter){
  int i,j;
      for(i=0;i<sig_tam;i++){
    output_signal[i]=0;
    for(j=-filter/2;j<filter/2;j++){
        output_signal[i]=output_signal[i]+sig_in[i+j];
      }
      output_signal[i]=output_signal[i]/filter;
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

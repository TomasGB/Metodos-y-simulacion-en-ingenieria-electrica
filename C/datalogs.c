#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
/*
    autor: Tomas Gomez
    fecha: 27/04
    finalidad: calcular la frecuencia promedio y valor eficaz de los datalog
    argumentos de entrada: la funcion no posee argumentos de entrada.
    argumentos de salida: la funcion no posee argumentos de salida.
*/

char datalog[9];
printf("\nIngrese nombre del datalog..\n");
scanf("%s",datalog);


//leer datos desde datalog

FILE * fp;
fp = fopen(datalog,"r");

if(!fp){
    printf("no se encontro el archivo\n");
    exit(101);
}

int nro_datos,cantidad_intervalos,i=0;


while(!feof(fp))
{
  i = fgetc(fp);
  if(i == '\n')
  {
    nro_datos++;
  }
}
fclose(fp);
printf("\ncant datos: %d\n",nro_datos);

cantidad_intervalos=(int)ceil(((nro_datos*0.001)/0.1));

printf("\ncant intervalos: %d\n",cantidad_intervalos);

fp = fopen(datalog,"r");


double datos[1571],datos_corregidos[1571],frecuencias[5][16];


for (int i=0;i<nro_datos;i++){
    fscanf(fp,"%lf ",&datos[i]);
}
fclose(fp);


//regresionLineal
float ordenada;

for (int i=0;i<nro_datos;i++){
    ordenada+=datos[i];
}

ordenada=ordenada/nro_datos;
printf("\nordenada: %.4f\n",ordenada);

for(int i=0;i<nro_datos;i++){
    datos_corregidos[i]=ordenada-datos[i];
}

// genera tabla de frecuencias

int cambios=0;
int intervalo, in, sen, pos=0; 
double mc,frec_int,RMS_int=0;
float dur_intervalo=0.1;

/*
    duracion de un intervalo: 0.1 seg (5 senoides ideales)
    frecuencias[0][]=numero de intervalo
    frecuencias[1][]=marca de clase del intervalo
    frecuencias[2][]=ciclos completos de la señal del datalog cumplidos en ese intervalo
    frecuencias[3][]=frecuencia del intervalo
    frecuencias[4][]=valor eficaz del intervalo

*/


printf("\nTabla de frecuencias (%s)\n\n",datalog);
printf("intervalo | marca de clase  |    ciclos completos    |   frecuencia del intervalo  |  RMS del intervalo  |\n");
printf("==========================================================================================================\n");

while (intervalo < cantidad_intervalos)
{
    RMS_int=0;

    for (int i=pos;i<pos+100;i++){
        //calcula los ciclos completos
        if( datos_corregidos[i]>=0 && (datos_corregidos[i-1])<0 ){
            cambios += 1;
        }
        // busca el pico del intervalo
        if(datos_corregidos[i]>RMS_int){
            RMS_int=datos_corregidos[i];
        }
    }
    RMS_int=RMS_int/sqrt(2);
    
    mc=((dur_intervalo-0.1)+dur_intervalo)/2;

    frecuencias[0][intervalo]=intervalo+1;
    frecuencias[1][intervalo]=mc;
    frecuencias[2][intervalo]=cambios;

    in=round(frecuencias[0][intervalo]);
    sen=round(frecuencias[2][intervalo]);
    frec_int=(sen)/(100*0.001);
    frecuencias[3][intervalo]=frec_int;
    frecuencias[4][intervalo]=RMS_int;

    printf("    %d     |       %.2f      |           %d            |            %.2f            |       %.2f        |\n", in, mc, sen,frec_int,RMS_int);
    cambios=0;
    pos=pos+100;
    dur_intervalo=dur_intervalo+(0.1);
    RMS_int=0;
    intervalo++;

}
printf("==========================================================================================================\n");
printf("\n");


//calculo promedio y desv estandar

int prom =0;
float desv, var,prom_htz,prom_ciclos=0;

for (int i=0;i<cantidad_intervalos;i++){
    prom=prom+frecuencias[2][i];
    prom_ciclos=prom_ciclos+frecuencias[2][i];
}
prom_ciclos=prom_ciclos/cantidad_intervalos;
prom_htz=prom/(nro_datos*0.001); //0.001 es de ((1/50)/20)

printf("promedio ciclos completos por intevalo: %.4f\n",prom_ciclos);
printf("\nfrecuencia promedio: %.4f\n",prom_htz);


for (int i=0;i<cantidad_intervalos;i++){
    var=var+pow((frecuencias[2][i]-prom_ciclos),2);
}

var=var/cantidad_intervalos;
desv=sqrt(var);


printf("\ndesv estandar: %.4f\n\n",desv);

printf("==========================================================================================================\n");

//calculo de valor eficaz

float pico, amplitud, RMS=0;

for (int i=0;i<nro_datos;i++){
    if (datos[i]>pico)
    {
        pico=datos[i];
    }
}

amplitud=pico-ordenada;
printf("\npico: %.4f\namplitud: %.4f\n",pico, amplitud);

RMS=amplitud/sqrt(2);

printf("RMS: %.4f\n",RMS);



}//end main

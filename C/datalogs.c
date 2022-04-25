#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int calcularCantidadSenoides(double datos[1571],int pos, int cambios,int senoides);
double mostrarFrecuencias(double frecuencias[2][50]);

int main(){

double datos[1571],datos_corregidos[1571],frecuencias[2][50];
//leer datos desde datalog

FILE * fp;
fp = fopen("datalog1","r");

if(!fp){
    printf("no se encontro el archivo\n");
    exit(101);
}

for (int i=0;i<1571;i++){
    fscanf(fp,"%lf ",&datos[i]);
}
fclose(fp);


for (int i=0;i<1571;i++){
    datos_corregidos[i]=338.95-datos[i];
}

// print datos
printf(" tiempo| datos |  datos_corregidos|\n");
for (int i=0; i<40;i++){
    printf("%d | %.4f | %.4f |\n",i,datos[i],datos_corregidos[i]);
}

// genera tabla de frecuencias

// cada intervalo dura 5 senoides ideales


int cambios=0;
frecuencias[3][10];
int intervalo, in, sen, pos=0; 
double mc=0;
float dur_intervalo=(1/50)*5;


printf("\nTabla de frecuencias (datalog 1)\n\n");
printf("intervalo| marca de clase  |  frecuencia \n");

while (intervalo < 10)
{

    for (int i=pos;i<pos+100;i++){
        if( datos_corregidos[i]>=0 && (datos_corregidos[i-1])<0 ){
            cambios += 1;
        }
    }
    mc=dur_intervalo/2;

    frecuencias[0][intervalo]=intervalo+1;
    frecuencias[1][intervalo]=mc;
    frecuencias[2][intervalo]=(cambios/2);

    in=round(frecuencias[0][intervalo]);
    //mc=frecuencias[1][intervalo];
    sen=round(frecuencias[2][intervalo]);
    printf("%lf",mc);

    //printf("%d        |   %f     |        %d\n", in, mc, sen);
    cambios=0;
    pos=pos+100;
    dur_intervalo=dur_intervalo+((1/50)*5);
    intervalo++;

}
printf("\n");

//calculo promedio y desv estandar


//prom= sumatoria((x_i*f_i)/n)
int n =0;
float prom=0;
for (int i=0;i<10;i++){
    n=n+frecuencias[2][i];
}

for (int i=0;i<10;i++){
    prom=prom+((frecuencias[1][i]*frecuencias[2][i])/n);
}

printf("\npromedio: %f",prom);


}//end main

int calcularCantidadSenoides(double datos_corregidos[1571],int pos, int cambios,int senoides){

    //int cambios=0;
    for (int i=pos;i<pos+20;i++){
        if( datos_corregidos[i]>=0 && (datos_corregidos[i-1])<0 ){
            cambios += 1;
        }
    }
    senoides=cambios/2;
    //printf("cambios: %d  senoides: %d",cambios,(cambios/2));
    return senoides;
}

double mostrarFrecuencias(double frecuencias[2][50]){
    printf("\n");
    for (int it_x=0;it_x<2;it_x++){
        for (int it_y=0;it_y<50;it_y++){
            printf("%d ",frecuencias[it_x][it_y]);
        }
        printf("\n");
    }
}
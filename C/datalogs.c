#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double regresionLineal(double datos[1571], double datos_corregidos[1571], int nro_datos);

int main(){

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

int nro_datos,i=0;
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

fp = fopen(datalog,"r");


double datos[1571],datos_corregidos[1571],frecuencias[2][50];

for (int i=0;i<1571;i++){
    fscanf(fp,"%lf ",&datos[i]);
}
fclose(fp);

//regresionLineal(datos,datos_corregidos,nro_datos);


for (int i=0;i<1571;i++){
    datos_corregidos[i]=338.95-datos[i];
}

/*
// print datos
printf(" tiempo| datos |  datos_corregidos|\n");
for (int i=0; i<40;i++){
    printf("%d | %.4f | %.4f |\n",i,datos[i],datos_corregidos[i]);
}
*/


// genera tabla de frecuencias
// cada intervalo dura 5 senoides ideales


int cambios=0;
int intervalo, in, sen, pos=0; 
double mc=0;
float dur_intervalo=0.1;
frecuencias[3][10];


printf("\nTabla de frecuencias (%s)\n\n",datalog);
printf("intervalo | marca de clase  |  frecuencia \n");
printf("======================================== \n");

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
    sen=round(frecuencias[2][intervalo]);

    printf("%d         |   %.2f          |        %d\n", in, mc, sen);
    cambios=0;
    pos=pos+100;
    dur_intervalo=dur_intervalo+(0.1);
    intervalo++;

}
printf("\n");

//calculo promedio y desv estandar

// f_i: frecuencia , x_i: marca de clase, n: cantidad de datos
//prom= sumatoria((x_i*f_i)/n)
// var = ((sumatoria(x_i-media)^2)*f_i)/n
// desv = sqrt(var)


int n =0;
float desv, var, prom=0;

for (int i=0;i<10;i++){
    n=n+frecuencias[2][i];
    prom=prom+(((frecuencias[1][i]*frecuencias[2][i])));
}
prom=prom/n;

printf("\npromedio: %.4f\n",prom);

for (int i=0;i<10;i++){
    var=var+(frecuencias[2][i]*(pow((frecuencias[1][i]-prom),2)));
}
var=var/n;
desv=sqrt(var);


printf("\ndesv estandar: %.4f\n",desv);

}//end main

double regresionLineal(double datos[1571], double datos_corregidos[1571], int nro_datos){

    double ordenada;

    for (int i=0;i<nro_datos;i++){
        ordenada+=datos[i];
    }

    ordenada=ordenada/nro_datos;
    printf("\n %f\n",ordenada);

    for(int i=0;i<1571;i++){
        datos_corregidos[i]=ordenada-datos[i];
    }

    return datos_corregidos[1571];
}
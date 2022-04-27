/*
function B = tl(A, Tx, Ty, Sx, Sy, Rot)
	% transformación lineal del punto A: translación (Tx, Ty), escala (Sx, Sy), rotación en (Rot) grados.
	% gck, 2004

  T = [Tx; Ty];
  S = [Sx 0; 0 Sy];
  alfa = Rot*pi/180;
  R = [cos(alfa) -sin(alfa); sin(alfa) cos(alfa)];

  B = T + R * S * A;
end
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

//void transform2D(int A, int Tx, int Ty, int Sx, int Sy, int Rot);
double GuardarEnArchivo(double arreglo[2][11]);
int contarNumeroDeFilas(void);
int contarNumeroDeColumnas(void);

int main(void){
    //double Fig[2][11]={{-6, -6, -7, 0, 7, 6, 6, -3, -3, 0, 0},{ -7, 2, 1, 8, 1, 2, -7, -7, -2, -2, -7}};
    int angulo = 45;
    int columnas,filas=0;
    filas=contarNumeroDeFilas();
    columnas=contarNumeroDeColumnas();

    printf("filas: %d\ncolumnas: %d\n",filas);
    double Fig[filas][columnas],resultado[filas][columnas];

    /*
    FILE * fp;
    fp = fopen("test.txt","r");

    if(!fp){
        printf("no se encontro el archivo\n");
        exit(101);
    }

    for (int i=0;i<2;i++){
        for (int j=0;j<11;j++){
            fscanf(fp,"%lf ",&Fig[i][j]);
        }
    }
    fclose(fp);
    */


    printf("===================================\n");
    printf("Figura original\n");

    for (int i=0;i<2;i++){
        for (int j=0;j<11;j++){
            printf(" %.4f ",Fig[i][j]);
        }
        printf("\n");
    }
    printf("===================================\n");
    printf("Figura transformada\n");

    for (int i=0;i<2;i++){
        for(int j=0;j<11;j++){
            printf("%.4f ",resultado[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    GuardarEnArchivo(resultado);


}//end main

double GuardarEnArchivo(double arreglo[2][11]){
    FILE *fichero;

    fichero = fopen( "fig_original2.txt", "w+" );

    for( int i = 0; i < 2 ; i++) {
        for( int j= 0; j < 11; j++) {
            fprintf(fichero, "%.4f ",arreglo[i][j]);
        }
        fprintf(fichero, "\n");
    }
    fclose( fichero );
}

int contarNumeroDeFilas(void){
    FILE * fp;
    fp = fopen("fig_original.txt","r");

    if(!fp){
        printf("no se encontro el archivo\n");
        exit(101);
    }

    int filas,i=0;
    while(!feof(fp))
    {
    i = fgetc(fp);
    if(i == '\n')
    {
        filas++;
    }
    }
    fclose(fp);

    fp = fopen("fig_original.txt","r");
    return filas;

}

int contarNumeroDeColumnas(void){
    
    FILE * fp;
    fp = fopen("fig_original.txt","r");

    if(!fp){
        printf("no se encontro el archivo\n");
        exit(101);
    }

    int columnas,i=0;

    while(feof(fp)!='\0'){
        columnas+=1;
    }
    
    fclose(fp);

    return columnas;
}

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
int GuardarEnArchivo(int arreglo[2][11]);
int LeerDeArchivo(void);
float rotation(int Fig[2][11], int angle);

int main(void){
    int Fig[2][11]={{-6, -6, -7, 0, 7, 6, 6, -3, -3, 0, 0},{ -7, 2, 1, 8, 1, 2, -7, -7, -2, -2, -7}};
    float resultado[2][11];
    int angulo = 45;

    printf("===================================\n");
    printf("Figura original\n\n");

    for (int i=0;i<2;i++){
        for (int j=0;j<11;j++){
            printf(" %d ",Fig[i][j]);
        }
        printf("\n");
    }
    printf("===================================\n");
    printf("Figura transformada\n\n");
    //GuardarEnArchivo(Fig);

    //rotation(Fig, angulo);


}//end main

int GuardarEnArchivo(int arreglo[2][11]){
    FILE *fichero;

    fichero = fopen( "fig_original2.txt", "w+" );

    for( int i = 0; i < 2 ; i++) {
        for( int j= 0; j < 11; j++) {
            fprintf(fichero, "%d ",arreglo[i][j]);
        }
        fprintf(fichero, "\n");
    }
    fclose( fichero );
}

/*
int LeerDeArchivo(void){
     FILE *fichero;

    fichero = fopen( "fig_original2.txt", "r" );
    int arreglo[2][11];
    
    int** mat=malloc(1000000*sizeof(int*)); 
    for(int it=0;it<1000000;++it){
        mat[it]=malloc(4*sizeof(int));
    }

    for( int i = 0; i < 2 ; i++) {
        for( int j= 0; j < 11; j++) {
            if (!fscanf(fichero, "%d", &mat[i][j])) 
                break;
            printf(" %d ",mat[i][j]);
            arreglo[i][j]=scanf("%d",mat[i][j]);
        }
        printf("\n");
    }
    
    fclose( fichero );
    printf("%d",arreglo);
    return 0;
}
*/


//void transform2D(int A, int Tx, int Ty, int Sx, int Sy, int Rot){


//    }
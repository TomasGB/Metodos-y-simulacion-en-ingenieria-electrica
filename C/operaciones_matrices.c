#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int mostrarMatriz(int mat_1[2][11]);
float mostrarMatrizFloat(float mat_1[11][2]);
//float mat_mult(float mat_1[2][11], int mat_2[2][11], int res[11][2]);
int translate(int Fig[2][11], int Tx , int Ty, int TFig[2][11]);
int scale(int Fig[2][11], int Sx , int Sy, int TFig[2][11]);
//float rotation(float Fig[2][11], int angle,float res[11][2]);

int main(){

    float ang_rad=(45/180)*PI;

    float matrizDeRotacion[2][2]={{cos(ang_rad),-sin(ang_rad)},{sin(ang_rad),cos(ang_rad)}};
    int Fig[2][11]={{-6, -6, -7, 0, 7, 6, 6, -3, -3, 0, 0},{ -7, 2, 1, 8, 1, 2, -7, -7, -2, -2, -7}};
    int TFig[2][11],TFig2[2][11];

    //float FigFloat[2][11]={{-6.0000, -6.0000, -7.0000, 0.0000, 7.0000, 6.0000, 6.0000, -3.0000, -3.0000, 0.0000, 0.0000},{ -7.0000, 2.0000, 1.0000, 8.0000, 1.0000, 2.0000, -7.0000, -7.0000, -2.0000, -2.0000, -7.0000}};

    int angulo = 35;
    int Tx =15;
    int Ty= -2;
    int Sx=2;
    int Sy=2;

    float resultado[11][2];
    //int Fig2[11][11]={-6, -6, -7, 0, 7, 6, 6, -3, -3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,1};

    mostrarMatriz(Fig);
    translate(Fig, Tx , Ty, TFig);
    scale(TFig, Sx , Sy, TFig2);
    printf("\n");
    mostrarMatriz(TFig2);


    //mat_mult(matrizDeRotacion,FigFloat,resultado);

    //mostrarMatrizFloat(FigFloat);
    //rotation(Fig, angulo,resultado);
    //enum { Fig, FigFloat };

}


int mostrarMatriz(int mat_1[2][11]){
    for (int i=0;i<2;i++){
            for (int j=0;j<11;j++){
                printf(" %d ",mat_1[i][j]);
            }
        printf("\n");
    }
}

float mat_mult(float mat_1[2][2], float mat_2[2][11], float res[11][2]){
    for(int i=0;i<2;i++){
            for(int j=0;j<11;j++){
                res[i][j]=0;
                for(int k=0;k<2;k++){
                    printf(" %d ",(mat_1[i][k]*mat_2[k][j]));
                    res[i][j]=res[i][j]+(mat_1[i][k]*mat_2[k][j]);
                }
                printf("\n");
            }  
            printf("\n");
        }
        return res[11][2];
}


float mostrarMatrizFloat(float mat_1[11][2]){
    for (int i=0;i<2;i++){
            for (int j=0;j<2;j++){
                printf(" %4d ",mat_1[i][j]);
            }
        printf("\n");
    }

}

int translate(int Fig[2][11], int Tx , int Ty, int TFig[2][11]){
    for (int i=0;i<11;i++){
        TFig[0][i]=Fig[0][i]+Tx; 
        TFig[1][i]=Fig[1][i]+Ty;
    }
    return TFig[2][11];
}
int scale(int Fig[2][11], int Sx , int Sy, int TFig[2][11]){
    for (int i=0;i<11;i++){
        TFig[0][i]=Fig[0][i]+Sx; 
        TFig[1][i]=Fig[1][i]+Sy;
    }
    return TFig[2][11];
}

/*
float rotation(int Fig[2][11], int angle,float resultado[11][2]){
    float ang_rad=(angle/180)*PI;
    float matrizDeRotacion[2][2]={{cos(ang_rad),-sin(ang_rad)},{sin(ang_rad),cos(ang_rad)}};

    for(int i=0;i<2;i++){
            for(int j=0;j<11;j++){
                for(int k=0;k<2;k++){
                    resultado[i][j]=resultado[i][j]+(matrizDeRotacion[i][k]*Fig[k][j]);
                    printf(" %d ",(matrizDeRotacion[i][k]*Fig[k][j]));
                }
                printf("\n");
            }  
            printf("\n");
        }
    
    

    //mat_mult(matrizDeRotacion, Fig, resultado);
    printf("matriz resultado:\n");

    }
    */
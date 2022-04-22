#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int mostrarMatrizInt(int mat_1[2][11]);
float mostrarMatrizFloat(float mat_1[11][2]);
//float mat_mult(float mat_1[2][11], int mat_2[2][11], int res[11][2]);
int translate2D(int Fig[2][11], int Tx , int Ty, int TFig[2][11]);
int translate3D(int Fig[3][11], int Tx , int Ty, int Tz, int TFig[3][11]);
int scale2D(int Fig[2][11], float Sx , float Sy, int TFig[2][11]);
int scale3D(int Fig[3][11], float Sx , float Sy, float Sz, int TFig[3][11]);
float rotation2D(int Fig[2][11], int angle,float res[11][2]);

int main(){

    float ang_rad=(45/180)*PI;

    float matrizDeRotacion[2][2]={{cos(ang_rad),-sin(ang_rad)},{sin(ang_rad),cos(ang_rad)}};
    int Fig[2][11]={{-6, -6, -7, 0, 7, 6, 6, -3, -3, 0, 0},{ -7, 2, 1, 8, 1, 2, -7, -7, -2, -2, -7}};
    int TFig[2][11],TFig2[2][11];

    //parametros de transformacion
    int angulo = 45;
    int Tx =25;
    int Ty= -12;
    float Sx=3;
    float Sy=0.5;

    float resultado[11][2];

    mostrarMatrizInt(Fig);
    translate2D(Fig, Tx , Ty, TFig);
    scale2D(TFig, Sx , Sy, TFig);
    printf("\n");
    mostrarMatrizInt(TFig);
    rotation2D(TFig, angulo,resultado);
    printf("\n");
    mostrarMatrizFloat(resultado);

}

//========= Print Matrices ==========================

int mostrarMatrizInt(int mat_1[2][11]){
    for (int i=0;i<2;i++){
            for (int j=0;j<11;j++){
                printf(" %d ",mat_1[i][j]);
            }
        printf("\n");
    }
}

float mostrarMatrizFloat(float mat_1[11][2]){

    for (int it_x=0;it_x<2;it_x++){
        for (int it_y=0;it_y<11;it_y++){
            printf("%0.4f ",mat_1[it_x][it_y]);
        }
        printf("\n");
    }
}

//============== Operaciones matematicas ====================

float mat_mult(float mat_1[2][2], int mat_2[2][11], float res[11][2]){
    for(int i=0;i<2;i++){
            for(int j=0;j<11;j++){
                res[i][j]=0;
                for(int k=0;k<2;k++){
                    printf("%0.4f ",(mat_1[i][k]*mat_2[k][j]));
                    res[i][j]=res[i][j]+(mat_1[i][k]*mat_2[k][j]);
                }
                printf("\n");
            }  
            printf("\n");
        }
        return res[11][2];
}

//============== Transformaciones ======================

int translate2D(int Fig[2][11], int Tx , int Ty, int TFig[2][11]){
    for (int i=0;i<11;i++){
        TFig[0][i]=Fig[0][i]+Tx; 
        TFig[1][i]=Fig[1][i]+Ty;
    }
    return TFig[2][11];
}
int translate3D(int Fig[3][11], int Tx , int Ty, int Tz, int TFig[3][11]){
    for (int i=0;i<11;i++){
        TFig[0][i]=Fig[0][i]+Tx; 
        TFig[1][i]=Fig[1][i]+Ty;
        TFig[2][i]=Fig[2][i]+Tz;
    }
    return TFig[3][11];
}

int scale2D(int Fig[2][11], float Sx , float Sy, int TFig[2][11]){
    for (int i=0;i<11;i++){
        TFig[0][i]=Fig[0][i]*Sx; 
        TFig[1][i]=Fig[1][i]*Sy;
    }
    return TFig[2][11];
}
int scale3D(int Fig[3][11], float Sx , float Sy, float Sz, int TFig[3][11]){
    for (int i=0;i<11;i++){
        TFig[0][i]=Fig[0][i]*Sx; 
        TFig[1][i]=Fig[1][i]*Sy;
        TFig[2][i]=Fig[2][i]*Sz;
    }
    return TFig[3][11];
}

float rotation2D(int Fig[2][11], int angle,float result[11][2]){
    float ang_rad=(angle/180)*PI;
    float matrizDeRotacion[2][2]={{cos(ang_rad),-sin(ang_rad)},{sin(ang_rad),cos(ang_rad)}};

    for(int i=0;i<11;i++){
        for(int j=0;j<2;j++){
            float acum=0.00;
            for(int k=0;k<2;k++){
                acum=acum+(matrizDeRotacion[j][k]*Fig[k][i]);
                //result[i][j]=result[i][j]+(matrizDeRotacion[i][k]*Fig[k][j]);
            }
            result[j][i]=acum;
        }
    }
    return result[11][2];
    }
    
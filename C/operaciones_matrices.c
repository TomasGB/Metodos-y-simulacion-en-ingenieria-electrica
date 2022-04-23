#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

/*
typedef struct{
    int x[11];
    int y[11];
}tyMatrizInt2D;


typedef struct{
    float x[11];
    float y[11];
}tyMatrizFloat2D;

void mostrarMatrizInt2D(tyMatrizInt2D mat_1);
void mostrarMatrizFloat2D(tyMatrizFloat2D mat_1);
tyMatrizInt2D translateMatrix2D(tyMatrizInt2D Fig, int Tx , int Ty, tyMatrizInt2D TFig);
tyMatrizInt2D scaleMatrix2D(tyMatrizInt2D Fig, float Sx , float Sy, tyMatrizInt2D TFig);

*/

float mostrarMatriz(float mat_1[2][11]);
float translate2D(float Fig[2][11], float Tx , float Ty, float TFig[2][11]);
float translate3D(float Fig[3][11], float Tx , float Ty, float Tz, float TFig[3][11]);
float scale2D(float Fig[2][11], float Sx , float Sy, float TFig[2][11]);
float scale3D(float Fig[3][11], float Sx , float Sy, float Sz, float TFig[3][11]);

float mat_mult(float mat_1[2][2], float mat_2[2][11], float res[2][11]);
float rotation2D(float Fig[2][11], int angle,float res[2][11]);

int main(){
    /*
    tyMatrizInt2D m1={{-6, -6, -7, 0, 7, 6, 6, -3, -3, 0, 0},{ -7, 2, 1, 8, 1, 2, -7, -7, -2, -2, -7}};
    tyMatrizInt2D m2={{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    */

    float ang_rad=(PI/180)*90;

    float matrizDeRotacion[2][2]={{cos(ang_rad),-1*sin(ang_rad)},{sin(ang_rad),cos(ang_rad)}};
    float Fig[2][11]={{-6, -6, -7, 0, 7, 6, 6, -3, -3, 0, 0},{ -7, 2, 1, 8, 1, 2, -7, -7, -2, -2, -7}};
    float TFig[2][11],TFig2[2][11];
    float res[2][11]={{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0}};

    //parametros de transformacion
    int angulo = 45;
    float Tx =25;
    float Ty= -12;
    float Sx=3;
    float Sy=0.5;


    mostrarMatriz(Fig);
    translate2D(Fig, Tx , Ty, TFig);
    scale2D(TFig, Sx , Sy, TFig);
    rotation2D(TFig, angulo,res);
    printf("\n");
    mostrarMatriz(res);

}

//========= Print Matrices ==========================
/*
void mostrarMatrizInt2D(tyMatrizInt2D mat_1){
    for (int i=0;i<11;i++){
        printf("%d ",mat_1.x[i]);
    }
    printf("\n");
    for (int j=0;j<11;j++){
        printf("%d ",mat_1.y[j]);
    }
    printf("\n");
}
void mostrarMatrizFloat2D(tyMatrizFloat2D mat_1){
    for (int i=0;i<11;i++){
        printf("%0.4f ",mat_1.x[i]);
    }
    printf("\n");
    for (int j=0;j<11;j++){
        printf("%0.4f ",mat_1.y[j]);
    }
    printf("\n");
}
*/

float mostrarMatriz(float mat_1[2][11]){
    for (int it_x=0;it_x<2;it_x++){
        for (int it_y=0;it_y<11;it_y++){
            printf("%0.4f ",mat_1[it_x][it_y]);
        }
        printf("\n");
    }
}
//============== Operaciones matematicas ====================

float mat_mult(float mat_1[2][2], float mat_2[2][11], float res[2][11]){
    for(int i=0;i<2;i++){
        for(int j=0;j<11;j++){
            res[i][j]=0;
            for(int k=0;k<2;k++){
                res[i][j]+=(mat_1[i][k]*mat_2[k][j]);
            }
        }
    }
    return res[2][11];
}

//============== Transformaciones ======================
/*
tyMatrizInt2D translateMatrix2D(tyMatrizInt2D Fig, int Tx , int Ty, tyMatrizInt2D TFig){
    for (int i=0;i<11;i++){
        TFig.x[i]=Fig.x[i]+Tx; 
        TFig.y[i]=Fig.y[i]+Ty;
    }
    return TFig;
}

tyMatrizInt2D scaleMatrix2D(tyMatrizInt2D Fig, float Sx , float Sy, tyMatrizInt2D TFig){
    for (int i=0;i<11;i++){
        TFig.x[i]=Fig.x[i]*Sx; 
        TFig.y[i]=Fig.y[i]*Sy;
    }
    return TFig;
}
*/

float translate2D(float Fig[2][11], float Tx , float Ty, float TFig[2][11]){
    for (int i=0;i<11;i++){
        TFig[0][i]=Fig[0][i]+Tx; 
        TFig[1][i]=Fig[1][i]+Ty;
    }
    return TFig[2][11];
}

float translate3D(float Fig[3][11], float Tx , float Ty, float Tz, float TFig[3][11]){
    for (int i=0;i<11;i++){
        TFig[0][i]=Fig[0][i]+Tx; 
        TFig[1][i]=Fig[1][i]+Ty;
        TFig[2][i]=Fig[2][i]+Tz;
    }
    return TFig[3][11];
}

float scale2D(float Fig[2][11], float Sx , float Sy, float TFig[2][11]){
    for (int i=0;i<11;i++){
        TFig[0][i]=Fig[0][i]*Sx; 
        TFig[1][i]=Fig[1][i]*Sy;
    }
    return TFig[2][11];
}
float scale3D(float Fig[3][11], float Sx , float Sy, float Sz, float TFig[3][11]){
    for (int i=0;i<11;i++){
        TFig[0][i]=Fig[0][i]*Sx; 
        TFig[1][i]=Fig[1][i]*Sy;
        TFig[2][i]=Fig[2][i]*Sz;
    }
    return TFig[3][11];
}

float rotation2D(float Fig[2][11], int angle,float res[2][11]){
    float ang_rad=(PI/180)*angle;
    float matrizDeRotacion[2][2]={{cos(ang_rad),(-1)*sin(ang_rad)},{sin(ang_rad),cos(ang_rad)}};

    for(int i=0;i<2;i++){
        for(int j=0;j<11;j++){
            res[i][j]=0;
            for(int k=0;k<2;k++){
                res[i][j]+=matrizDeRotacion[i][k]*Fig[k][j];
            }
        }
    }
    return res[2][11];
    }
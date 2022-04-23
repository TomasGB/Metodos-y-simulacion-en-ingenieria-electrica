#include<stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

float mat_mult(float mat_1[2][2], float mat_2[2][11], float res[2][11]);
float mostrarMatrizInt1(float mat_1[2][2]);
float mostrarMatrizRot(float mat_1[2][2]);
float mostrarMatrizIntRes(float mat_1[2][11]);


void main(void){

    float ang_rad=90*(PI/180);
    float mat_1[2][11]={{-6, -6, -7, 0, 7, 6, 6, -3, -3, 0, 0},{ -7, 2, 1, 8, 1, 2, -7, -7, -2, -2, -7}};
    float mat_2[2][2]={{(cos(ang_rad)),(-1*sin(ang_rad))},{(sin(ang_rad)),(cos(ang_rad))}};
    //float mat_2[2][2]={{0,-1},{1,0}};

    float res[2][11]={{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0}};

    mostrarMatrizIntRes(mat_1);
    printf("\n");
    printf("%f",(-1*sin(ang_rad)));
    printf("\n");
    mostrarMatrizRot(mat_2);
    mat_mult(mat_2,mat_1,res);
    printf("\n");
    mostrarMatrizIntRes(res);
}


float mostrarMatrizInt1(float mat_1[2][2]){
    for (int i=0;i<2;i++){
            for (int j=0;j<2;j++){
                printf(" %d ",mat_1[i][j]);
            }
        printf("\n");
    }
    printf("\n");
}
float mostrarMatrizRot(float mat_1[2][2]){
    for (int i=0;i<2;i++){
            for (int j=0;j<2;j++){
                printf(" %.4f ",mat_1[i][j]);
            }
        printf("\n");
    }
}
float mostrarMatrizIntRes(float mat_1[2][11]){
    for (int i=0;i<2;i++){
            for (int j=0;j<11;j++){
                printf(" %.4f ",mat_1[i][j]);
            }
        printf("\n");
    }
}


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
#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

double mostrarMatriz(double mat_1[2][11]);
double mostrarMatriz3D(double mat_1[3][11]);
double transform2D(double Fig[2][11], float Tx , float Ty, float Sx , float Sy, int angle, double TFig[2][11], double res[2][11]);
double transform3D(double Fig3D[3][11], float Tx , float Ty, float Tz, float Sx , float Sy, float Sz, int angle_x, int angle_y, int angle_z, double TFig3D[3][11], double res3D[3][11]);
double translate2D(double Fig[2][11], float Tx , float Ty, double TFig[2][11]);
double translate3D(double Fig[3][11], float Tx , float Ty, float Tz, double TFig[3][11]);
double scale2D(double Fig[2][11], float Sx , float Sy, double TFig[2][11]);
double scale3D(double Fig[3][11], float Sx , float Sy, float Sz, double TFig[3][11]);
double rotation2D(double Fig[2][11], int angle,double res[2][11]);
double rotation3D(double Fig[3][11], int angle_x, int angle_y, int angle_z,double res[3][11]);

int main(){

    float ang_rad=(PI/180)*90;

<<<<<<< HEAD
    //float matrizDeRotacion[2][2]={{cos(ang_rad),-1*sin(ang_rad)},{sin(ang_rad),cos(ang_rad)}};
    float Fig[2][11]={{-6, -6, -7, 0, 7, 6, 6, -3, -3, 0, 0},{ -7, 2, 1, 8, 1, 2, -7, -7, -2, -2, -7}};
    float TFig[2][11]={{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0}};
    float res[2][11]={{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0}};
=======
    double matrizDeRotacion[2][2]={{cos(ang_rad),-1*sin(ang_rad)},{sin(ang_rad),cos(ang_rad)}};
    double Fig[2][11]={{-6, -6, -7, 0, 7, 6, 6, -3, -3, 0, 0},{ -7, 2, 1, 8, 1, 2, -7, -7, -2, -2, -7}};
    double TFig[2][11]={{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0}};
    double res[2][11]={{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0}};
>>>>>>> 011cc15269309c74cf0326e19122c17f9c270355

    double Fig3D[3][11]={{-6, -6, -7, 0, 7, 6, 6, -3, -3, 0, 0},{ -7, 2, 1, 8, 1, 2, -7, -7, -2, -2, -7},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    double TFig3D[3][11]={{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    double res3D[3][11]={{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    //parametros de transformacion
    int angulo = 5;
    int angulo_x= 90;
    int angulo_y = 30;
    int angulo_z = 50;

    float Tx = 0;
    float Ty = 0;
    float Tz = 0;

    float Sx = 1;
    float Sy = 1;
    float Sz = 1;


    // Transformaciones 2D
    printf("Figura original 2D:\n");
    mostrarMatriz(Fig);
    printf("\n");
    printf("Figura transformada 2D:\n");
    transform2D(Fig, Tx , Ty, Sx , Sy , angulo, TFig, res);
    mostrarMatriz(res);
    printf("\n");
    // Transformaciones 3D
    printf("\n");
    printf("Figura original 3D:\n");
    mostrarMatriz3D(Fig3D);
    printf("\n");
    printf("Figura transformada 3D:\n");
    transform3D(Fig3D, Tx , Ty, Tz, Sx , Sy, Sz, angulo_x, angulo_y, angulo_z, TFig3D, res3D);
    mostrarMatriz3D(res3D);

}

//========= Print Matrices ==========================
double mostrarMatriz(double mat_1[2][11]){
    for (int it_x=0;it_x<2;it_x++){
        for (int it_y=0;it_y<11;it_y++){
            printf("%0.4f ",mat_1[it_x][it_y]);
        }
        printf("\n");
    }
}
double mostrarMatriz3D(double mat_1[3][11]){
    for (int it_x=0;it_x<3;it_x++){
        for (int it_y=0;it_y<11;it_y++){
            printf("%0.4f ",mat_1[it_x][it_y]);
        }
        printf("\n");
    }
}
//============== Transformaciones ======================

double transform2D(double Fig[2][11], float Tx , float Ty, float Sx , float Sy, int angle, double TFig[2][11], double res[2][11]){
    translate2D(Fig, Tx , Ty, TFig);
    scale2D(TFig, Sx , Sy, TFig);
    rotation2D(TFig, angle, res);
    return res[2][11];
}
double transform3D(double Fig3D[3][11], float Tx , float Ty, float Tz, float Sx , float Sy, float Sz, int angle_x, int angle_y, int angle_z, double TFig3D[3][11], double res3D[3][11]){
    translate3D(Fig3D, Tx , Ty, Tz, TFig3D);
    scale3D(TFig3D, Sx , Sy, Sz, TFig3D);
    rotation3D(TFig3D, angle_x,angle_y,angle_z, res3D);
    return res3D[3][11];
}

double translate2D(double Fig[2][11], float Tx , float Ty, double TFig[2][11]){
    for (int i=0;i<11;i++){
        TFig[0][i]=Fig[0][i]+Tx; 
        TFig[1][i]=Fig[1][i]+Ty;
    }
    return TFig[2][11];
}

double translate3D(double Fig[3][11], float Tx , float Ty, float Tz, double TFig[3][11]){
    for (int i=0;i<11;i++){
        TFig[0][i]=Fig[0][i]+Tx; 
        TFig[1][i]=Fig[1][i]+Ty;
        TFig[2][i]=Fig[2][i]+Tz;
    }
    return TFig[3][11];
}

double scale2D(double Fig[2][11], float Sx , float Sy, double TFig[2][11]){
    for (int i=0;i<11;i++){
        TFig[0][i]=Fig[0][i]*Sx; 
        TFig[1][i]=Fig[1][i]*Sy;
    }
    return TFig[2][11];
}
double scale3D(double Fig[3][11], float Sx , float Sy, float Sz, double TFig[3][11]){
    for (int i=0;i<11;i++){
        TFig[0][i]=Fig[0][i]*Sx; 
        TFig[1][i]=Fig[1][i]*Sy;
        TFig[2][i]=Fig[2][i]*Sz;
    }
    return TFig[3][11];
}

double rotation2D(double Fig[2][11], int angle,double res[2][11]){
    float ang_rad=(PI/180)*angle;
    double matrizDeRotacion[2][2]={{cos(ang_rad),(-1)*sin(ang_rad)},{sin(ang_rad),cos(ang_rad)}};

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

double rotation3D(double Fig[3][11], int angle_x, int angle_y, int angle_z,double res[3][11]){
    
    float ang_rad_X=(PI/180)*angle_x;
    float ang_rad_Y=(PI/180)*angle_y;
    float ang_rad_Z=(PI/180)*angle_z;

    double matrizDeRotacion_X[3][3]={{1,0,0},{0,cos(ang_rad_X),(-1)*sin(ang_rad_X)},{0,sin(ang_rad_X),cos(ang_rad_X)}}; // eje x
    double matrizDeRotacion_Y[3][3]={{cos(ang_rad_Y),0,sin(ang_rad_Y)},{0,1,0},{sin(ang_rad_Y),0,cos(ang_rad_Y)}}; // eje y
    double matrizDeRotacion_Z[3][3]={{cos(ang_rad_Z),(-1)*sin(ang_rad_Z),0},{sin(ang_rad_Z),cos(ang_rad_Z),0},{0,0,1}}; // eje z;

    for(int i_x=0;i_x<3;i_x++){
        for(int j_x=0;j_x<11;j_x++){
            res[i_x][j_x]=0;
            for(int k_x=0;k_x<3;k_x++){
                res[i_x][j_x]+=matrizDeRotacion_X[i_x][k_x]*Fig[k_x][j_x];
            }
        }
    }

    for(int i_y=0;i_y<3;i_y++){
        for(int j_y=0;j_y<11;j_y++){
            Fig[i_y][j_y]=0;
            for(int k_y=0;k_y<3;k_y++){
                Fig[i_y][j_y]+=matrizDeRotacion_Y[i_y][k_y]*res[k_y][j_y];
            }
        }
    }

    for(int i_z=0;i_z<3;i_z++){
        for(int j_z=0;j_z<11;j_z++){
            res[i_z][j_z]=0;
            for(int k_z=0;k_z<3;k_z++){
                res[i_z][j_z]+=matrizDeRotacion_Z[i_z][k_z]*Fig[k_z][j_z];
            }
        }
    }

    return res[3][11];
}
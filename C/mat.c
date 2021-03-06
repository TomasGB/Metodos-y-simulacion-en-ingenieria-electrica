#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int contarNumeroDeFilas(void);
int contarNumeroDeColumnas(void);

typedef struct{
    float x[11];
    float y[11];
}tyMatriz2D;

typedef struct{
    float x[11];
    float y[11];
    float z[11];
}tyMatriz3D;



void mostrarMatriz2D(tyMatriz2D mat_1);
void mostrarMatriz3D(tyMatriz3D mat_1);

tyMatriz2D translateMatrix2D(tyMatriz2D Fig, float Tx , float Ty, tyMatriz2D TFig);
tyMatriz2D scaleMatrix2D(tyMatriz2D Fig, float Sx , float Sy, tyMatriz2D TFig);
tyMatriz3D translateMatrix3D(tyMatriz3D Fig, float Tx , float Ty, float Tz, tyMatriz3D TFig);
tyMatriz3D scaleMatrix3D(tyMatriz3D Fig, float Sx , float Sy, float Sz, tyMatriz3D TFig);


void main(){

    int columnas,filas=0;
    filas=contarNumeroDeFilas();
    columnas=contarNumeroDeColumnas();
    
    tyMatriz2D mat_1={{-6, -6, -7, 0, 7, 6, 6, -3, -3, 0, 0},{ -7, 2, 1, 8, 1, 2, -7, -7, -2, -2, -7}};
    tyMatriz2D mat_2={{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    mostrarMatriz2D(mat_1);


    int columnasFig=sizeof(mat_1.x)/sizeof(int); // calcula el numero de columnas
    int filasFig=sizeof(tyMatriz2D)/sizeof(mat_1.x); // calcula el numero de filas
    //printf("%d    %d",filasFig,columnasFig);
    
    float Tx = 5;
    float Ty = -2;


    translateMatrix2D( mat_1, Tx , Ty, mat_2);
    printf("\n");
    mostrarMatriz2D(mat_2);
}



//========= Print Matrices ==========================

void mostrarMatriz2D(tyMatriz2D mat_1){
    for (int i=0;i<11;i++){
        printf("%0.4f ",mat_1.x[i]);
    }
    printf("\n");
    for (int j=0;j<11;j++){
        printf("%0.4f ",mat_1.y[j]);
    }
    printf("\n");
}
void mostrarMatriz3D(tyMatriz3D mat_1){
    for (int i=0;i<11;i++){
        printf("%0.4f ",mat_1.x[i]);
    }
    printf("\n");
    for (int j=0;j<11;j++){
        printf("%0.4f ",mat_1.y[j]);
    }
    printf("\n");
    for (int k=0;k<11;k++){
        printf("%0.4f ",mat_1.y[k]);
    }
    printf("\n");
}
//=================== Operaciones =====================================




//============== Transformaciones =====================================

tyMatriz2D translateMatrix2D(tyMatriz2D Fig, float Tx , float Ty, tyMatriz2D TFig){
    for (int i=0;i<11;i++){
        TFig.x[i]=Fig.x[i]+Tx; 
        TFig.y[i]=Fig.y[i]+Ty;
    }
    return TFig;
}

tyMatriz2D scaleMatrix2D(tyMatriz2D Fig, float Sx , float Sy, tyMatriz2D TFig){
    for (int i=0;i<11;i++){
        TFig.x[i]=Fig.x[i]*Sx; 
        TFig.y[i]=Fig.y[i]*Sy;
    }
    return TFig;
}
tyMatriz3D translateMatrix3D(tyMatriz3D Fig, float Tx , float Ty, float Tz, tyMatriz3D TFig){
    for (int i=0;i<11;i++){
        TFig.x[i]=Fig.x[i]+Tx; 
        TFig.y[i]=Fig.y[i]+Ty;
        TFig.z[i]=Fig.z[i]+Tz;
    }
    return TFig;
}

tyMatriz3D scaleMatrix3D(tyMatriz3D Fig, float Sx , float Sy, float Sz, tyMatriz3D TFig){
    for (int i=0;i<11;i++){
        TFig.x[i]=Fig.x[i]*Sx; 
        TFig.y[i]=Fig.y[i]*Sy;
        TFig.z[i]=Fig.z[i]*Sz;
    }
    return TFig;
}

tyMatriz2D rotationMatrix2D(tyMatriz3D Fig, int angle, tyMatriz3D TFig){
    float ang_rad=(PI/180)*angle;
    float matrizDeRotacion[2][2]={{cos(ang_rad),(-1)*sin(ang_rad)},{sin(ang_rad),cos(ang_rad)}};
/*
    for(int i=0;i<2;i++){
        for(int j=0;j<11;j++){
            TFig.x[i],TFig.y[j]=0;
            for(int k=0;k<2;k++){
                TFig.x[i],TFig.y[j]+=matrizDeRotacion[i][k]*Fig.x[k][j];
            }
        }
    }
    return TFig[2][11];
    */
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

    while(!feof(fp) && fgetc(fp)!='\n'){
        if (fgetc(fp)=='-'||fgetc(fp)==' '||fgetc(fp)=='\0'){
            
        }else{
            columnas+=1;
        }
    }
    columnas++;

    fclose(fp);

    return columnas;
}

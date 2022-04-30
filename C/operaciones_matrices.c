#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265358979323846


typedef struct {
    char operacion;
    double parametros[3];
}instruccion;

double mostrarMatriz(int dimensiones, double mat_1[3][11]);
double transform(int dimensiones, double Fig3D[3][11],char operacion, double parametros[3], double res[3][11]);
double translate(int dimensiones, double Fig[3][11], float Tx , float Ty, float Tz, double TFig[3][11]);
double scale(int dimensiones,double Fig[3][11], float Sx , float Sy, float Sz, double TFig[3][11]);
double rotation2D(double Fig[3][11], float angle,double res[3][11]);
double rotation3D(double Fig[3][11], float angle_x, float angle_y, float angle_z,double res[3][11]);

//double transform2(int filas, double Fig3D[3][11], float Tx , float Ty, float Tz, float Sx , float Sy, float Sz, int angle_x, int angle_y, int angle_z, double TFig3D[3][11], double res3D[3][11]);
//int contarNumeroDeColumnas(void);
int contarNumeroDeDimensiones(void);
double cargarMatriz(int dimensiones, double matriz[3][11]);
void GuardarEnArchivo(int dimensiones,double arreglo[3][11]);
instruccion readTransformations(instruccion transformaciones);

int main(){

    //float ang_rad=(PI/180)*90;

    int dimensiones=contarNumeroDeDimensiones();
    double Fig3D[3][11];

    Fig3D[3][11]=cargarMatriz(dimensiones,Fig3D);
    double TFig3D[3][11]={{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    //double res3D[3][11]={{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    //double Fig3D[3][11]={{-6, -6, -7, 0, 7, 6, 6, -3, -3, 0, 0},{ -7, 2, 1, 8, 1, 2, -7, -7, -2, -2, -7},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    /*
    //parametros de transformacion
    int angulo = 0;
    int angulo_x= 0;
    int angulo_y = 0;
    int angulo_z = 0;

    float Tx = 0;
    float Ty = 0;
    float Tz = 1;

    float Sx = 1;
    float Sy = 1;
    float Sz = 1;
    */

   // Transformaciones 3D
    printf("Dimensiones: %d\n",dimensiones);
    printf("\n");
    printf("Figura original:\n");
    mostrarMatriz(dimensiones,Fig3D);

    //lee instrucciones del archivo
    char operacion;
    double parametros[3];

    FILE * fp;
    fp = fopen("transformaciones.txt","r");

    if(!fp){
        printf("no se encontro el archivo\n");
        exit(101);
    }

    int jk=0;
    int it=0;
    char a;
    while(!feof(fp))
    {
        if(jk<1){
            operacion=fgetc(fp);
            jk++;
        }
        fscanf(fp,"%lf",&parametros[it]);

        it++;

        if(it==3 && operacion!='r'){
            transform(dimensiones, Fig3D,operacion,parametros,Fig3D);
            Fig3D[3][11]=Fig3D[3][11];
            it=0;
            jk=0;
        }
        if(it==3 && operacion=='r'){
            transform(dimensiones, Fig3D,operacion,parametros,TFig3D);
            Fig3D[3][11]=TFig3D[3][11];
            it=0;
            jk=0;
        }

    }

    fclose(fp);

    printf("\n");
    printf("Figura transformada:\n");

    mostrarMatriz(dimensiones,Fig3D);

    GuardarEnArchivo(dimensiones,Fig3D);
    

}

//========= Print Matrices ==========================

double mostrarMatriz(int dimensiones, double mat_1[3][11]){
    for (int it_x=0;it_x<dimensiones;it_x++){
        for (int it_y=0;it_y<11;it_y++){
            printf("%0.4f ",mat_1[it_x][it_y]);
        }
        printf("\n");
    }
}
//============== Transformaciones ======================

double transform(int dimensiones, double Fig3D[3][11],char operacion, double parametros[3], double res[3][11]){

    switch (operacion){
        case 't':
            if(dimensiones==3){
                translate(dimensiones,Fig3D,parametros[0],parametros[1],parametros[2], res);
            }else if(dimensiones==2){
                translate(dimensiones,Fig3D,parametros[0],parametros[1],0,res);
            }
        break;

        case 's':
        if(dimensiones==3){
                scale(dimensiones,Fig3D,parametros[0],parametros[1],parametros[2], res);
            }else if(dimensiones==2){
                scale(dimensiones,Fig3D,parametros[0],parametros[1],0, res);
            }
        break;
        case 'r':
        if(dimensiones==3){
                rotation3D(Fig3D,parametros[0],parametros[1],parametros[2],res);
            }else if(dimensiones==2){
                rotation2D(Fig3D,parametros[2],res);
            }
        break;
    }
}

double transform2(int dimensiones, double Fig3D[3][11], float Tx , float Ty, float Tz, float Sx , float Sy, float Sz, int angle_x, int angle_y, int angle_z, double TFig3D[3][11], double res3D[3][11]){
    translate(dimensiones, Fig3D, Tx , Ty, Tz, TFig3D);
    scale(dimensiones, TFig3D, Sx , Sy, Sz, TFig3D);

    if (dimensiones==2){
        rotation2D(TFig3D, angle_z, res3D);
    }else{
        rotation3D(TFig3D, angle_x,angle_y,angle_z, res3D);
    }
    return res3D[3][11];
}
double translate(int dimensiones, double Fig[3][11], float Tx , float Ty, float Tz, double TFig[3][11]){
    for (int i=0;i<11;i++){
        TFig[0][i]=Fig[0][i]+Tx; 
        TFig[1][i]=Fig[1][i]+Ty;

        if(dimensiones==2){
            }else{
            TFig[2][i]=Fig[2][i]+Tz;
        }
    }
    return TFig[3][11];
}
double scale(int dimensiones,double Fig[3][11], float Sx , float Sy, float Sz, double TFig[3][11]){
    for (int i=0;i<11;i++){
        TFig[0][i]=Fig[0][i]*Sx; 
        TFig[1][i]=Fig[1][i]*Sy;

        if(dimensiones==2){

        }else{
            TFig[2][i]=Fig[2][i]*Sz;
        }
    }
    return TFig[3][11];
}

double rotation2D(double Fig[3][11], float angle,double res[3][11]){
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

    for(int i=0;i<11;i++){
        res[2][i]=0;
    }
    return res[3][11];
}

double rotation3D(double Fig[3][11], float angle_x, float angle_y, float angle_z,double res[3][11]){
    
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

//========================= Archivos =====================================================

int contarNumeroDeDimensiones(void){
    FILE * fp;
    fp = fopen("fig_original3D.txt","r");

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
    filas+=1; 

    return filas;

}
/*
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
*/

double cargarMatriz(int dimensiones, double matriz[3][11]){
    FILE * fp;
    fp = fopen("fig_original3D.txt","r");

    if(!fp){
        printf("no se encontro el archivo\n");
        exit(101);
    }

    for (int i=0;i<dimensiones;i++){
        for (int j=0;j<11;j++){
            fscanf(fp,"%lf ",&matriz[i][j]);
        }
    }
    if(dimensiones==2){
        for (int j=0;j<11;j++){
            matriz[2][j]=0;
        }
    }
    fclose(fp);

    return matriz[3][11];

}

void GuardarEnArchivo(int dimensiones,double arreglo[3][11]){
    FILE *fp;

    fp = fopen( "test.txt", "w+" );

    for( int i = 0; i < dimensiones ; i++) {
        for( int j= 0; j < 11; j++) {
            fprintf(fp, "%.4f ",arreglo[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose( fp );
}



/*
 void readTransformations(void){
        ejemplo de instruccion:

        transformacion, eje x, eje y, eje z

        traslacion: t , escalado: s, rotacion: r

        t,15,-2,6 ----> traslada 15 unidades en x, -2 en y, 6 en z
        r,5,0,45 ----> rota 5° en x, 0° en y, 45° en z



    FILE * fp;
    fp = fopen("transformaciones.txt","r");

    if(!fp){
        printf("no se encontro el archivo\n");
        exit(101);
    }

    int jk=0;
    int it=0;
    char a;
    while(!feof(fp))
    {
        if(jk<1){
            operacion=fgetc(fp);
            jk++;
        }
        fscanf(fp,"%lf",&parametros[it]);

        it++;

    }
}
*/
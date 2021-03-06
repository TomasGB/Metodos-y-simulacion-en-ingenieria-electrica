#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265358979323846

double showMatrix(int dimension, double Fig[3][11]);
double transform(int dimension, double Fig[3][11],char operation, double parameters[3], double res[3][11]);
double translate(int dimension, double Fig[3][11], float Tx , float Ty, float Tz, double TFig[3][11]);
double scale(int dimension,double Fig[3][11], float Sx , float Sy, float Sz, double TFig[3][11]);
double rotation2D(double Fig[3][11], float angle,double TFig[3][11]);
double rotation3D(double Fig[3][11], float angle_x, float angle_y, float angle_z,double TFig[3][11]);
int calculateDimension(void);
double loadMatrix(int dimension, double Fig[3][11]);
void saveInFile(int dimension,double Fig[3][11]);


int main(){

    int dimensiones=calculateDimension();
    double Fig[3][11];


    Fig[3][11]=loadMatrix(dimensiones,Fig);
    double TFig[3][11]={{0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0},{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

   // Transformaciones
    printf("Dimensiones: %d\n",dimensiones);
    printf("\n");
    printf("Figura original:\n");
    showMatrix(dimensiones,Fig);

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
    while(!feof(fp))
    {
        if(jk<1){
            operacion=fgetc(fp);
            jk++;
        }
        fscanf(fp,"%lf",&parametros[it]);

        it++;

        if(it==3 && operacion!='r'){
            transform(dimensiones, Fig,operacion,parametros,Fig);
            Fig[3][11]=Fig[3][11];
            it=0;
            jk=0;
        }
        if(it==3 && operacion=='r'){
            transform(dimensiones, Fig,operacion,parametros,TFig);

            for(int i=0;i<dimensiones;i++){
                for (int j=0;j<11;j++){
                    Fig[i][j]=TFig[i][j];
                }
            }
            it=0;
            jk=0;
        }
    }

    fclose(fp);

    printf("\n");
    printf("Figura transformada:\n");

    showMatrix(dimensiones,Fig);
    saveInFile(dimensiones,Fig);
}

//========= Print Matrices ==========================

double showMatrix(int dimension, double Fig[3][11]){
    /*
        autor: Tomas Gomez
        fecha: 20/04
        finalidad: Mostrar por consola la matriz de puntos la figura
        argumentos de entrada:
            + int dimensiones: Valor entero indicando si se trata de una figura en dos o tres dimensiones.
            + double Fig[3][11]: Matriz conteniendo los puntos de la figura
        
        argumentos de salida: la funcion no posee argumentos de salida.
        ejemplo de invocacion: showMatrix(dimensiones,Fig);
    */

    for (int it_x=0;it_x<dimension;it_x++){
        for (int it_y=0;it_y<11;it_y++){
            printf("%0.4f ",Fig[it_x][it_y]);
        }
        printf("\n");
    }
}
//============== Transformaciones ======================

double transform(int dimension, double Fig3D[3][11], char operation, double parameters[3], double res[3][11]){
    /*
        autor: Tomas Gomez
        fecha: 01/05
        finalidad: aplicar transformaciones en la figura.
        argumentos de entrada:
            + int dimensiones: Valor entero indicando si se trata de una figura en dos o tres dimensiones
            + double Fig[3][11]: Matriz conteniendo los puntos de la figura
            + char operation: Char indicando el tipo de operacion a aplicar
            + double parameters[3]: Arreglo de largo 3 conteniendo los parametros para la transformacion
        argumentos de salida: 
            + double res[3][11]: Matriz conteniendo los puntos transformados
        ejemplo de invocacion: transform(dimensiones, Fig,operacion,parametros,Fig);
    */
    switch (operation){
        case 't':
            if(dimension==3){
                translate(dimension,Fig3D,parameters[0],parameters[1],parameters[2], res);
            }else if(dimension==2){
                translate(dimension,Fig3D,parameters[0],parameters[1],0,res);
            }
        break;

        case 's':
        if(dimension==3){
                scale(dimension,Fig3D,parameters[0],parameters[1],parameters[2], res);
            }else if(dimension==2){
                scale(dimension,Fig3D,parameters[0],parameters[1],0, res);
            }
        break;
        case 'r':
        if(dimension==3){
                rotation3D(Fig3D,parameters[0],parameters[1],parameters[2],res);
            }else if(dimension==2){
                rotation2D(Fig3D,parameters[0],res);
            }
        break;
    }
}

double translate(int dimension, double Fig[3][11], float Tx , float Ty, float Tz, double TFig[3][11]){
    // para modificar poner que devuelvan void y en la declaracion double TFig[][11]
    /*
        autor: Franco del Pardo
        fecha: 20/04
        finalidad: aplicar transformacion de traslacion en la figura.
        argumentos de entrada:
            + int dimensiones: Valor entero indicando si se trata de una figura en dos o tres dimensiones
            + double Fig[3][11]: Matriz conteniendo los puntos de la figura
            + float Tx: Parametro de traslacion en eje x
            + float Ty: Parametro de traslacion en eje y
            + float Tz: Parametro de traslacion en eje z
        argumentos de salida: 
            + double TFig[3][11]: Matriz conteniendo los puntos transformados
        ejemplo de invocacion: translate(dimension,Fig3D,parameters[0],parameters[1],parameters[2], res);
    */
    for (int i=0;i<11;i++){
        TFig[0][i]=Fig[0][i]+Tx; 
        TFig[1][i]=Fig[1][i]+Ty;

        if(dimension==3){
            TFig[2][i]=Fig[2][i]+Tz;
        }
    }
    return TFig[3][11];
}
double scale(int dimension,double Fig[3][11], float Sx , float Sy, float Sz, double TFig[3][11]){
    /*
        autor: Franco del Pardo
        fecha: 20/04
        finalidad: aplicar transformacion de escalado en la figura.
        argumentos de entrada:
            + int dimensiones: Valor entero indicando si se trata de una figura en dos o tres dimensiones
            + double Fig[3][11]: Matriz conteniendo los puntos de la figura
            + float Tx: Parametro de escalado en eje x
            + float Ty: Parametro de escalado en eje y
            + float Tz: Parametro de escalado en eje z
        argumentos de salida: 
            + double TFig[3][11]: Matriz conteniendo los puntos transformados
        ejemplo de invocacion: scale(dimension,Fig3D,parameters[0],parameters[1],parameters[2], res);
    */
    for (int i=0;i<11;i++){
        TFig[0][i]=Fig[0][i]*Sx; 
        TFig[1][i]=Fig[1][i]*Sy;

        if(dimension==3){
            TFig[2][i]=Fig[2][i]*Sz;
        }
    }
    return TFig[3][11];
}

double rotation2D(double Fig[3][11], float angle,double TFig[3][11]){
    /*
        autor: Tomas Gomez
        fecha: 22/04
        finalidad: aplicar transformacion de rotacion en 2D en la figura.
        argumentos de entrada:
            + double Fig[3][11]: Matriz conteniendo los puntos de la figura
            + float angle: angulo de rotacion
        argumentos de salida: 
            + double TFig[3][11]: Matriz conteniendo los puntos transformados
        ejemplo de invocacion: rotation2D(Fig3D,parameters[0],res);
    */
    float ang_rad=(PI/180)*angle;
    double matrizDeRotacion[2][2]={{cos(ang_rad),(-1)*sin(ang_rad)},{sin(ang_rad),cos(ang_rad)}};

    for(int i=0;i<2;i++){
        for(int j=0;j<11;j++){
            TFig[i][j]=0;
            for(int k=0;k<2;k++){
                TFig[i][j]+=matrizDeRotacion[i][k]*Fig[k][j];
            }
        }
    }

    for(int i=0;i<11;i++){
        TFig[2][i]=0;
    }
    return TFig[3][11];
}

double rotation3D(double Fig[3][11], float angle_x, float angle_y, float angle_z,double TFig[3][11]){
    /*
        autor: Tomas Gomez
        fecha: 22/04
        finalidad: aplicar transformacion de rotacion en 2D en la figura.
        argumentos de entrada:
            + double Fig[3][11]: Matriz conteniendo los puntos de la figura
            + float angle_x: angulo de rotacion en eje x
            + float angle_y: angulo de rotacion en eje y
            + float angle_z: angulo de rotacion en eje z
        argumentos de salida: 
            + double TFig[3][11]: Matriz conteniendo los puntos transformados
        ejemplo de invocacion: rotation3D(Fig3D,parameters[0],parameters[1],parameters[2],res);
    */

    float ang_rad_X=(PI/180)*angle_x;
    float ang_rad_Y=(PI/180)*angle_y;
    float ang_rad_Z=(PI/180)*angle_z;

    double matrizDeRotacion_X[3][3]={{1,0,0},{0,cos(ang_rad_X),(-1)*sin(ang_rad_X)},{0,sin(ang_rad_X),cos(ang_rad_X)}}; // eje x
    double matrizDeRotacion_Y[3][3]={{cos(ang_rad_Y),0,sin(ang_rad_Y)},{0,1,0},{sin(ang_rad_Y),0,cos(ang_rad_Y)}}; // eje y
    double matrizDeRotacion_Z[3][3]={{cos(ang_rad_Z),(-1)*sin(ang_rad_Z),0},{sin(ang_rad_Z),cos(ang_rad_Z),0},{0,0,1}}; // eje z;

    for(int i_x=0;i_x<3;i_x++){
        for(int j_x=0;j_x<11;j_x++){
            TFig[i_x][j_x]=0;
            for(int k_x=0;k_x<3;k_x++){
                TFig[i_x][j_x]+=matrizDeRotacion_X[i_x][k_x]*Fig[k_x][j_x];
            }
        }
    }

    for(int i_y=0;i_y<3;i_y++){
        for(int j_y=0;j_y<11;j_y++){
            Fig[i_y][j_y]=0;
            for(int k_y=0;k_y<3;k_y++){
                Fig[i_y][j_y]+=matrizDeRotacion_Y[i_y][k_y]*TFig[k_y][j_y];
            }
        }
    }

    for(int i_z=0;i_z<3;i_z++){
        for(int j_z=0;j_z<11;j_z++){
            TFig[i_z][j_z]=0;
            for(int k_z=0;k_z<3;k_z++){
                TFig[i_z][j_z]+=matrizDeRotacion_Z[i_z][k_z]*Fig[k_z][j_z];
            }
        }
    }
    return TFig[3][11];
}

//========================= Archivos =====================================================

int calculateDimension(void){
    /*
        autor: Tomas Gomez
        fecha: 02/05
        finalidad: calcular la dimension de la figura original.
        argumentos de entrada: esta funcion no posee argumentos de entrada
        argumentos de salida: 
            + int filas: numero de filas del archivo, que determina las dimensiones de la figura
        ejemplo de invocacion: int dimensiones=calculateDimension();
    */

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
    filas+=1; 

    return filas;
}

double loadMatrix(int dimension, double matrix[3][11]){
    /*
        autor: Tomas Gomez
        fecha: 02/05
        finalidad: cargar los puntos del archivo de texto a la matriz
        argumentos de entrada:
            + int dimension: dimension de la figura
        argumentos de salida: 
            + double matrix[3][11]: matriz con los puntos cargados
        ejemplo de invocacion: Fig[3][11]=loadMatrix(dimensiones,Fig);
    */

    FILE * fp;
    fp = fopen("fig_original.txt","r");

    if(!fp){
        printf("no se encontro el archivo\n");
        exit(101);
    }

    for (int i=0;i<dimension;i++){
        for (int j=0;j<11;j++){
            fscanf(fp,"%lf ",&matrix[i][j]);
        }
    }
    if(dimension==2){
        for (int j=0;j<11;j++){
            matrix[2][j]=0;
        }
    }
    fclose(fp);

    return matrix[3][11];
}

void saveInFile(int dimension,double Fig[3][11]){
     /*
        autor: Tomas Gomez
        fecha: 02/05
        finalidad: guardar los puntos transformados en un nuevo archivo de texto
        argumentos de entrada:
            + int dimension: dimension de la figura
            + double Fig[3][11]: matriz de la figura resultante de la transformacion
        argumentos de salida:esta funcion no posee argumentos de salida
        ejemplo de invocacion: saveInFile(dimensiones,Fig);
    */
    FILE *fp;

    fp = fopen( "fig_transformada.txt", "w+" );

    for( int i = 0; i < dimension ; i++) {
        for( int j= 0; j < 11; j++) {
            fprintf(fp, "%.4f ",Fig[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose( fp );
}
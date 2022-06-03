#include <stdio.h>


double precision(double n, int precision);
double power(double n, int exponent);
double factorial(int numero, int resFactorials[]);
double absolute_value(double n);
double sine(double angle,  int resFactorials[],  double tol, double sine);
double cosine(double angle,  int resFactorials[], double tol, double cosine);
double tangent(double angle,  int resFactorials[],double tangent, double presicion);
void saveInFile(int angle, double decimals1,double decimals3,double decimals5,double decimals7,int table, int sums_substracts, int prod_cocients);
void saveInFileCosto(int angle, double tangent,int sum_prods,int prods_cocient,int decimales,int table);

// Variables Globales

int sumas_restas=0,sumas_restas1=0,sumas_restas3=0,sumas_restas5=0,sumas_restas7=0;
int productos_cocientes=0,productos_cocientes1=0,productos_cocientes3=0,productos_cocientes5=0,productos_cocientes7=0;

// El arreglo se eligio de 12 lugares porque a partir del factorial de 13 aparecen errores
static int resFactorials[12]={0};
double PI=(314159265359/(double)100000000000);

void main(void){
    double result,d1,d3,d5,d7,presicion;
    double sin,cos,tan=100,tan1,tan3,tan5,tan7;
    int angle;


    printf("Ingrese un angulo: ");
    scanf("%d",&angle);
    //angle=45;
    double ang=(angle*PI)/180;

    printf("Ingrese cuanto decimales de presicion: ");
    scanf("%lf",&presicion);



    printf("\n\nangulo en grados : %d    angulo en radianes: %f \n\n",angle,ang);



    tan=tangent(ang,resFactorials,tan,1/power(10,presicion));
    printf("\ntan : %lf \n",tan);
    tan=0;


    printf("\n");

    //tabla de 0° a 45°

    FILE * fp;
    fp = fopen( "tabla_angulos.txt","w+");
    fprintf(fp,"==============================================================================\n");
    fprintf(fp,"| grados |   1 decimal   |  3 decimales  |  5 decimales  |    7 decimales    |\n");
    fprintf(fp,"==============================================================================\n");
    fclose(fp);


    printf("\nTabla de angulos:\n");

    for (int j=1;j<8;j+=2){
        printf("Precision: %d decimales\n",j);
        printf("\n========================================================================\n");
        printf("| grados |    tangente    |    sumas/restas   |   productos/cocientes  |\n");
        printf("========================================================================\n");
        sumas_restas=0;
        productos_cocientes=0;

        for (int i=0;i<46;i++){
            sumas_restas=0;
            productos_cocientes=0;
            ang=(i*PI)/180;
            tan=tangent(ang,resFactorials,tan,1/power(10,j));
            printf("|   %d    |     %.8lf   |         %d        |           %d           |\n",i,tan,sumas_restas,productos_cocientes);
            saveInFileCosto( i,tan,sumas_restas,productos_cocientes,j,0);
        }
        printf("===========================================================================\n");
        printf("\n");
    }


/*
    printf("\nTabla de costo computacional:\n");
    printf("\n=====================================================================================================================================================================================================================================================================\n");
    printf("| grados |     1 decimal   |   sumas/restas   |   productos/cocientes  |    3 decimales    |   sumas/restas   |   productos/cocientes  |    5 decimales    |   sumas/restas   |   productos/cocientes  |    7 decimales   |   sumas/restas   |   productos/cocientes  |\n");
    printf("\n=====================================================================================================================================================================================================================================================================\n");

    for (int i=0;i<46;i++){
        sumas_restas1=0;sumas_restas3=0;sumas_restas5=0;sumas_restas7=0;
        productos_cocientes1=0;productos_cocientes3=0;productos_cocientes5=0;productos_cocientes7=0;
        d1=0;d3=0;d5=0;d7=0;

        ang=(i*PI)/180;

        //tan=tangent(ang,resFactorials,tan,1/power(10,presicion));
        d1=tangent(ang,resFactorials,tan,1/power(10,1));//precision(tan, 1);
        d3=tangent(ang,resFactorials,tan,1/power(10,3));//precision(tan, 3);
        d5=tangent(ang,resFactorials,tan,1/power(10,5));//precision(tan, 5);
        d7=tangent(ang,resFactorials,tan,1/power(10,7));//precision(tan, 7);
        //printf("|   %d    |       %.1lf       |       %.3lf       |      %.5lf      |     %.7lf    |         %d        |           %d           |\n",i,d1,d3,d5,d7,sumas_restas,productos_cocientes);
        printf("|   %d     |     %.1lf     |   %d   |   %d      |    %.3lf     |   %d   |   %d      |    %.5lf      |   %d   |   %d      |       %.lf      |   %d   |   %d      |",i,d1,sumas_restas1,productos_cocientes1,d3,sumas_restas3,productos_cocientes3,d5,sumas_restas5,productos_cocientes5,d7,sumas_restas7,productos_cocientes7);
        //saveInFile( i,d1,d3,d5,d7,2,sumas_restas,productos_cocientes);
    }
    printf("===========================================================================================================================================================================================================================================================================================\n");
*/

}

//=============================== Operaciones auxiliares =======================================================

double precision(double n, int precision){
    /*
        autor: Tomas Gomez
        fecha: 17/05
        finalidad: Devolver la precision deseada
        argumentos de entrada:
            + double n: numero 
            + int precision: numero de decimales deseados
        
        argumentos de salida: 
        ejemplo de invocacion: precision(tan, 5);
    */
    int aux;
    double result;

    precision=power(10,precision);
    n=n*precision;
    aux=n;
    result=(float)aux/precision;
    productos_cocientes+=2;

    return result;
}

double power(double n, int exponent){
    /*
        autor: Tomas Gomez
        fecha: 16/05
        finalidad: Calcular potencias
        argumentos de entrada:
            + double n: numero 
            + int exponent: exponente
        
        argumentos de salida: 
        ejemplo de invocacion: power((-1),2);
    */
    double result;
    result=n;

    if(exponent==0){
        return result=1;
    }else if(exponent<0){

            for (int i=1;i<((-1)*exponent);i++){
            result=n*result;
            productos_cocientes+=1;
        }
        result=1/result;
        productos_cocientes+=1;
    }else{
        for (int i=1;i<exponent;i++){
            result=n*result;
            productos_cocientes+=1;
        }
    }


    return result;
}


double factorial(int number, int resFactorials[]){
    /*
        autor: Tomas Gomez
        fecha: 16/05
        finalidad: Calcular factorial de un numero
        argumentos de entrada:
            + double numero: numero a calcular el factorial
            + double resFactoriales[]: Arreglo conteniendo resultados ya calculados de factoriales
        argumentos de salida: 
        ejemplo de invocacion: factorial(7,resFactoriales);
    */

    double result=0;

    if(resFactorials[number]!=0){
        result=resFactorials[number];
    }else{
        if (number==0){
            result=1;
            resFactorials[number]=result;
        }
        else{
            if(resFactorials[number]==0){
                result=number*factorial(number-1,resFactorials);
                resFactorials[number]=result;
                productos_cocientes+=1;
            }else{
                result=number*resFactorials[number-1];
                productos_cocientes+=1;
            }
        }
    }

    return result;
}

double absolute_value(double n){
    if (n < 0) {
        n = (-1) * n;
    }
    productos_cocientes+=1;

    return n;
}

//================ Funciones trigonometricas ============================================

double sine(double angle,  int resFactorials[], double tol,double sine){
    /*
        autor: Tomas Gomez
        fecha: 16/05
        finalidad: Calcular el seno del angulo
        argumentos de entrada:
            + double angle: angulo 
            + double resFactorials[]: Arreglo conteniendo resultados ya calculados de factoriales
        
        argumentos de salida:
            + double seno: resultado del seno
        ejemplo de invocacion: sine(ang, resFactorials,sine);
    */

    int a,i=0;
    double b=0,c=0,old_value=10,actual_error=100;

    while(actual_error>tol){
        
        a=power((-1),i);
        b=power(angle,((2*i)+1));
        c=factorial(((2*i)+1),resFactorials);

        if(a<0){
            sine=sine-(b/c);
            productos_cocientes+=1;
            sumas_restas+=1;
        }else{
            sine=sine+(b/c);
            productos_cocientes+=1;
            sumas_restas+=1;
        }

        i++;
        
        actual_error=(sine-old_value)/sine*100;
        productos_cocientes+=2;
        sumas_restas+=1;

        actual_error=absolute_value(actual_error);
        old_value=sine;

    }
    return sine;
}
double cosine(double angle,  int resFactorials[], double tol, double cosine){

    /*
        autor: Tomas Gomez
        fecha: 16/05
        finalidad: Calcular el coseno del angulo
        argumentos de entrada:
            + double angle: angulo 
            + double resFactorials[]: Arreglo conteniendo resultados ya calculados de factoriales
        
        argumentos de salida: 
            + double cosine: resultado del coseno
        ejemplo de invocacion: cosine(ang, resFactorials,cos);
    */

    int a,i=0;
    double b,c,old_value=10,actual_error=100;


    while(actual_error>tol){

        a=power((-1),i);
        b=power(angle,((2*i)));
        c=factorial(((2*i)),resFactorials);

        if(a<0){
            cosine=cosine-(b/c);
            productos_cocientes+=1;
            sumas_restas+=1;
        }else{
            cosine=cosine+(b/c);
            productos_cocientes+=1;
            sumas_restas+=1;
        }

        i++;
        actual_error=(cosine-old_value)/cosine*100;
        productos_cocientes+=2;
        sumas_restas+=1;
        actual_error=absolute_value(actual_error);
        old_value=cosine;

    }

    return cosine;
}

double tangent(double angle,  int resFactorials[],double tangent, double presicion){
    /*
        autor: Tomas Gomez
        fecha: 16/05
        finalidad: Calcular la tangente del angulo
        argumentos de entrada:
            + double angle: angulo 
            + double resFactorials[]: Arreglo conteniendo resultados ya calculados de factoriales
        
        argumentos de salida:
            + double tangent: resultado de la tangente
        ejemplo de invocacion: tangent(ang, resFactoriales,tan);
    */

    double sin=0,cos=0,error_tg=10,tol,u,v;
    //double tol_tg=(1/power(10,4));
    int it=0;

    while (error_tg>presicion){

        tol=1/power(10,1+it);

        sin=sine(angle,resFactorials,tol,sin);
        cos=cosine(angle,resFactorials,tol,cos);

        u=absolute_value(sin);
        v=absolute_value(cos);
        error_tg=( u * tol + v * tol)/power(cos,2);
        productos_cocientes+=4;
        sumas_restas+=2;
        //printf("%lf\n",error_tg);
        it++;
    }

    tangent=(sin/cos);
    productos_cocientes+=1;
    return tangent;
}

//================ Archivo de texto ==================================================

void saveInFileCosto(int angle, double tangent,int sum_prods,int prods_cocient,int decimales,int table){
    /*
        autor: Tomas Gomez
        fecha: 16/05
        finalidad: Guardar tabla de precision en un archvio txt
        argumentos de entrada:
            + double angle: angulo 
            + double decimals1: tangente con 1 decimal
            + double decimals3: tangente con 3 decimales
            + double decimals5: tangente con 5 decimales
            + double decimals7: tangente con 7 decimales
            +int table: define que tabla se quiere guardar (1: Tabla de angulos, 2: Tabla de costo computacional))
            +int sums_substracts
            +int prod_cocients
        
        argumentos de salida: 
        ejemplo de invocacion: saveInFile( i,d1,d3,d5,d7,2,sumas_restas,productos_cocientes);
    */

    FILE * fp;


    /*
    if(table==1){
        fp = fopen( "tabla_angulos.txt","a");
        fprintf(fp,"|    %d   |      %.1lf      |     %.3lf     |    %.5lf    |     %.7lf     |\n",angle,decimals1,decimals3,decimals5,decimals7);
        fclose(fp);
    }else{*/

    switch(decimales){
        case 1:
            fp = fopen( "tabla_costo_computacional_1decimal.txt","a");
            fprintf(fp,"|   %d    |     %.1lf   |         %d        |           %d           |\n",angle,tangent,sum_prods,prods_cocient);
            fclose(fp);
        break;
        case 3:
            fp = fopen( "tabla_costo_computacional_3decimal.txt","a");
            fprintf(fp,"|   %d    |     %.3lf   |         %d        |           %d           |\n",angle,tangent,sum_prods,prods_cocient);
            fclose(fp);
        break;
        case 5:
            fp = fopen( "tabla_costo_computacional_5decimal.txt","a");
            fprintf(fp,"|   %d    |     %.5lf   |         %d        |           %d           |\n",angle,tangent,sum_prods,prods_cocient);
            fclose(fp);
        break;
        case 7:
            fp = fopen( "tabla_costo_computacional_7decimal.txt","a");
            fprintf(fp,"|   %d    |     %.7lf   |         %d        |           %d           |\n",angle,tangent,sum_prods,prods_cocient);
            fclose(fp);
        break;

    }



}
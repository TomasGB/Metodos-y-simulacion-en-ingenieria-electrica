#include <stdio.h>


double precision(double n, int precision);
double potencia(double grados, int exponente);
double factorial(int numero, int resFactoriales[12]);
double sen(double angulo,  int resFactoriales[12], double seno);
double coseno(double angulo,  int resFactoriales[12], double coseno);
double tangente(double angulo,  int resFactoriales[12],  double tangente);
void guardarEnArchivo(int angulo, double decimales1,double decimales3,double decimales5,double decimales7);

static int resFactoriales[12]={0};
double PI=(314159265359/(double)100000000000);

void main(void){
    double result,d1,d3,d5,d7;
    double seno,cos,tan=0.0;
    int angulo;

/*
    factorial(12,resFactoriales);

    for (int i=0;i<12;i++){
        printf("%d\n",resFactoriales[i]);
    }
*/  
    printf("Ingrese un angulo: ");
    scanf("%d",&angulo);
    double ang=(angulo*PI)/180;

    printf("\n\nangulo en grados : %d    angulo en radianes: %f\n",angulo,ang);

    

    tan=tangente(ang,resFactoriales,tan);
    printf("\ntan : %lf \n",tan);


    
    //tabla de 0° a 45°

    FILE * fp;
    fp = fopen( "tabla.txt","w+");
    fprintf(fp,"| grados |   1 decimal   |  3 decimales  |  5 decimales  |    7 decimales    |\n");
    fprintf(fp,"=============================================================================\n");
    fclose(fp);

    printf("\nTabla de angulos:\n");
    printf("\n=======================================================================================\n");
    printf("| grados |     1 decimal   |    3 decimales    |    5 decimales    |    7 decimales   |\n");
    printf("=======================================================================================\n");

    for (int i=0;i<46;i++){
        ang=(i*PI)/180;
        tan=tangente(ang,resFactoriales,tan);
        d1=precision(tan, 1);
        d3=precision(tan, 3);
        d5=precision(tan, 5);
        d7=precision(tan, 7);
        printf("|   %d    |     %lf    |     %lf      |      %lf     |     %lf     |\n",i,d1,d3,d5,d7);
        guardarEnArchivo( i,d1,d3,d5,d7);
    }
    


}


//=============================== Operaciones auxiliares =======================================================

double precision(double n, int precision){
    int aux;
    double resultado;

    precision=potencia(10,precision);
    n=n*precision;
    aux=n;
    resultado=(float)aux/precision;

    return resultado;
}

double potencia(double grados, int exponente){
    double resultado;
    resultado=grados;

    if(exponente==0){
        return resultado=1;
    }else if(exponente<0){

            for (int i=1;i<((-1)*exponente);i++){
            resultado=grados*resultado;
        }
        resultado=1/resultado;
    }else{
        for (int i=1;i<exponente;i++){
            resultado=grados*resultado;
        }
    }


    return resultado;
}


double factorial(int numero, int resFactoriales[12]){
    double resultado=0;

    if (numero==0){
        resultado=1;
        resFactoriales[numero]=resultado;
    }
    else{
        if(resFactoriales[numero]==0){
            resultado=numero*factorial(numero-1,resFactoriales);
            resFactoriales[numero]=resultado;
        }else{
            resultado=numero*resFactoriales[numero-1];
        }

    }
    return resultado;
}

//================ Funciones trigonometricas ============================================

double sen(double angulo,  int resFactoriales[12],  double seno){
    /*
        autor: Tomas Gomez
        fecha: 16/05
        finalidad: Calcular el seno del angulo
        argumentos de entrada:
            + double angulo: angulo 
            + double resFactoriales[12]: Arreglo conteniendo resultados ya calculados de factoriales
        
        argumentos de salida: 
        ejemplo de invocacion: sen(ang, resFactoriales,seno);
    */

    int a,i=0;
    double b,c;

    while(i<5){
        a=potencia((-1),i);
        b=potencia(angulo,((2*i)+1));
        c=factorial(((2*i)+1),resFactoriales);
        
        //printf("i: %d |%d | %lf | %lf\n",i,a,b,c);

        if(a<0){
            seno=seno-(b/c);
        }else{
            seno=seno+(b/c);
        }

        i++;
    }

    return seno;
}
double coseno(double angulo,  int resFactoriales[12],  double coseno){

    /*
        autor: Tomas Gomez
        fecha: 16/05
        finalidad: Calcular el coseno del angulo
        argumentos de entrada:
            + double angulo: angulo 
            + double resFactoriales[12]: Arreglo conteniendo resultados ya calculados de factoriales
        
        argumentos de salida: 
        ejemplo de invocacion: coseno(ang, resFactoriales,cos);
    */

    int a,i=0;
    double b,c;

    while(i<5){
        a=potencia((-1),i);
        b=potencia(angulo,((2*i)));
        c=factorial(((2*i)),resFactoriales);
        
        //printf("i: %d |%d | %lf | %lf\n",i,a,b,c);

        if(a<0){
            coseno=coseno-(b/c);
        }else{
            coseno=coseno+(b/c);
        }

        i++;
    }

    return coseno;
}

double tangente(double angulo,  int resFactoriales[12],  double tangente){
    /*
        autor: Tomas Gomez
        fecha: 16/05
        finalidad: Calcular la tangente del angulo
        argumentos de entrada:
            + double angulo: angulo 
            + double resFactoriales[12]: Arreglo conteniendo resultados ya calculados de factoriales
        
        argumentos de salida: 
        ejemplo de invocacion: tangente(ang, resFactoriales,tan);
    */
    double seno,cos=0;
    
    seno=sen(angulo,resFactoriales,seno);
    cos=coseno(angulo,resFactoriales,cos);

    tangente=seno/cos;

    return tangente;
}

//================ Archivo de texto ==================================================

void guardarEnArchivo(int angulo, double decimales1,double decimales3,double decimales5,double decimales7){
    /*
        autor: Tomas Gomez
        fecha: 16/05
        finalidad: Guardar tabla de precision en un archvio txt
        argumentos de entrada:
            + double angulo: angulo 
            + double decimales1: tangente con 1 decimal
            + double decimales3: tangente con 3 decimales
            + double decimales5: tangente con 5 decimales
            + double decimales7: tangente con 7 decimales
        
        argumentos de salida: 
        ejemplo de invocacion: guardarEnArchivo( i,d1,d3,d5,d7);
    */

    FILE * fp;
    

    fp = fopen( "tabla.txt","a");

    fprintf(fp,"|    %d   |      %.1lf      |     %.3lf     |    %.5lf    |     %.7lf     |\n",angulo,decimales1,decimales3,decimales5,decimales7);
    fclose(fp);


}
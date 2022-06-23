//#include <stdio.h>

int angleCorrection(int angle);
int signCorrection(int angle,int sign);
double power(double n, int exponent);
double factorial(int numero, int resFactorials[]);
double absolute_value(double n);
double sine(double angle,  int resFactorials[],  double tol, double sine);
double cosine(double angle,  int resFactorials[], double tol, double cosine);
double tangent(double angle,  int resFactorials[],double tangent, double presicion);


// Variables Globales

int sumas_restas=0;
int productos_cocientes=0;

// El arreglo se eligio de 12 lugares porque a partir del factorial de 13 aparecen errores
static int resFactorials[12]={0};
double PI=(314159265359/(double)100000000000);

void main(void){

    double sin,cos,tan_latitude=100,tan_longitude=100;
    int latitude,latitude_aux=0,longitude,longitude_aux=0,precision,sign_lat=1,sign_long=1;

    latitude=45;
    longitude=-75;
    precision=5;

/*
    printf("\nlatitud : %d \n",latitude);
    printf("\nlogitude : %d \n",longitude);
    printf("\npresicion : %d decimales \n",precision);
    */
    latitude_aux=angleCorrection(latitude);
    sign_lat=signCorrection(latitude,sign_lat);

    longitude_aux=angleCorrection(longitude);
    sign_long=signCorrection(longitude,sign_long);


    double ang_lat,ang_long;

    ang_lat=(latitude_aux*PI)/180;
    tan_latitude=sign_lat*tangent(ang_lat,resFactorials,tan_latitude,1/power(10,precision));

    ang_long=(longitude_aux*PI)/180;
    tan_longitude=sign_long*tangent(ang_long,resFactorials,tan_longitude,1/power(10,precision));

    /*
    printf("\ntan latitud : %lf \n",tan_latitude);
    printf("\ntan logitude : %lf \n",tan_longitude);
    */

}

//=============================== Operaciones auxiliares =======================================================
int angleCorrection(int angle){
    /*
        autor: Tomas Gomez
        fecha: 01/06
        finalidad: Corregir angulos negativos o mayores a 360
        argumentos de entrada:
            + int angle: angulo 
        argumentos de salida: 

        ejemplo de invocacion: angleCorrection(longitude);
    */
    int angle_aux=0;
    // correccion para angulos negativos
    if(angle <0){
        while(angle<0){
            angle=360+angle;
        }
    }

    //correccion para angulos mayores a 360
    if(angle>360){
        while(angle>360){
            angle=angle-360;
        }
    }
    angle_aux=angle;

    //correccion para angulos mayores a 90
    if(angle_aux>90){
        while(angle_aux>90){

            if(angle_aux>90 && angle_aux<=180){
                angle_aux=180-angle_aux;
            }
            if(angle_aux>180 && angle_aux<=270){
                angle_aux=270-angle_aux;
            }
            if(angle_aux>270 && angle_aux<=360){
                angle_aux=360-angle_aux;
            }
        }
    }else{
        angle_aux;
    }

    return angle_aux;
}

int signCorrection(int angle,int sign){
    /*
        autor: Tomas Gomez
        fecha: 01/06
        finalidad: Devolver el signo correcto para el resultado
        argumentos de entrada:
            + int angle: angulo 
        argumentos de salida: 
            + int sign: signo a multiplicar el resultado (-1 o 1)
        ejemplo de invocacion: signCorrection(latitude,sign_latitude);
    */
    int angle_aux=0;
    // correccion para angulos negativos
    if(angle <0){
        while(angle<0){
            angle=360+angle;
        }
    }

    //correccion para angulos mayores a 360
    if(angle>360){
        while(angle>360){
            angle=angle-360;
        }
    }
    angle_aux=angle;

    if(angle_aux<=90){
        sign=1;
    }
    if(angle_aux>90 && angle_aux<=180){
        sign=-1;
    }
    if(angle_aux>180 && angle_aux<=270){
        sign=1;
    }
    if(angle_aux>270 && angle_aux<=360){
        sign=-1;
    }
    return sign;
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
        it++;
    }

    tangent=(sin/cos);
    productos_cocientes+=1;
    return tangent;
}

#include <stdio.h> 

double tangent(double x, float epsilon_s);
double sine(double x, float epsilon_s);
double cosine(double x, float epsilon_s);

float fact(double f);
int power_int(double x, int n);
double power_float(double x, int n);
void absolute_value(double * n);

void generate_table();
int set_precision(float original_value, int precision);


//______________________________FUNCION DRIVER__________________________________
void main(){
    double angle, tan;
    float precision;
    int i, table;

    printf("- ¿Qué hace? Calcula la tangente de un valor dado en grados ");
    printf("decimales\n");
    printf("- ¿Qué debo ingresar? El ángulo deseado y la precisión con la ");
    printf("que desea calcularlo\n");

    printf("> Ingresar el ángulo cuya tangente desea calcular: ");
    scanf("%lf", &angle);
    printf("> Ingresar la precisión: ");
    scanf("%f", &precision); 

    tan = tangent(angle, (1/(float)2 * power_float(10, 2 - (precision + 1))));

    if (angle == 45) { 
        printf("> tan(x) = %lf\n ", tan);
    } else {
        if (tan*10 < 1){ 
            printf("> tan(x) = 0,0%d\n ", set_precision(tan, (int)precision));
        } else if (tan != 0){
            printf("> tan(x) = 0,%d\n ", set_precision(tan, (int)precision));
        } else {
            printf("> tan(x) = %d\n ", set_precision(tan, (int)precision));
        }
    }
    

    printf("> ¿Desea generar la tabla de precisiones? 1(SI) - 0(NO) \n");
    scanf("%d", &table);

    if (table == 1) {
        generate_table();
    }
}

//_________________________FUNCIONES TRIGONOMÉTRICAS____________________________
double tangent(double x, float epsilon_s){
  
   float epsilon_a = 100, delta;
   double sin, cos, u, v;
   int n=2;

   x = x * 3141592654/((float)180*1000000000);

   while (epsilon_a > epsilon_s)
   {
       /*Se calculan sin(x) y cos(x) con igual cantidad de  digitos 
       significativos, i.e. Δv = Δu.*/
       delta = 1/(float)2 * power_float(10, 2-n);

       sin = sine(x, delta); cos = cosine(x, delta);
       u = sin; v = cos;
       absolute_value(&u); absolute_value(&v);

       epsilon_a = (u * delta + v * delta)/power_float(v, 2);
       n++;  
   }
   return sin/cos;
}

double sine(double x, float epsilon_s){
   
    int sign_check = 1;
    double sin = 0, sin_old = 0, error_a = 100;

    for (int i = 1; error_a > epsilon_s; i+=2){
        if (sign_check % 2 == 0){
            sin = sin - power_float(x, i)/fact(i);
        } else {
            sin = sin + power_float(x, i)/fact(i);
        }
        error_a = (sin - sin_old)/sin * 100;
        sin_old = sin;
        absolute_value(&error_a);
        sign_check++;
    }
    return sin;
}

double cosine(double x, float epsilon_s){
   
    int sign_check = 1;
    double cos = 0, cos_old = 0, epsilon_a = 100;
    cos = 1;

    for (int i = 2; epsilon_a > epsilon_s; i+=2){
        if (sign_check % 2 == 0){
            cos = cos + power_float(x, i)/fact(i);
        } else {
            cos = cos - power_float(x, i)/fact(i);
        }
        epsilon_a = (cos - cos_old)/cos * 100;
        cos_old = cos;
        absolute_value(&epsilon_a);
        sign_check++;
    }
    return cos;
}

//__________________________OPERACIONES MATEMÁTICAS_____________________________
float fact(double f){
    int i, factorial;
    factorial = f;
    for (i = 1; i<f; i++){
        factorial = factorial * i;
    }
    return factorial;
}

int power_int(double x, int n){
    int i;
    double dummy;

    dummy = x;
    for (i = 1; i < n; i++){
        x = dummy * x;
    }
    return x;
}

double power_float(double x, int n){
    int i;
    double dummy;
    dummy = x;
    int sign_check = n; //Me guarda el valor y signo de n para el condicional

    if (n == 0){
        return 1;
    } 

    //Computa el valor absoluto de n si es negativo
    if (n < 0) {
        n = (-1) * n;
    }

    for (i = 1; i < n; i++){
        x = dummy * x;
    }
    if (sign_check > 0){
        return x;
    } else {
        return 1/x;
    }
}

void absolute_value(double * n){
    if (* n < 0) {
        * n = (-1) * (* n);
    }
}

int set_precision(float original_value, int precision){
    precision = power_int(10, precision);   
    return original_value * precision;
}

//______________________FUNCION DE GENERACIÓN DE TABLA__________________________


void generate_table(){    

    printf("Tangente |    7+/-1   |   5+/-1  |  3+/-1 | 1+/-1 \n");

    for (int i = 0; i <= 45; i++){
        printf("tan(%2d) ", i);
        printf(" | %1.8lf | %1.6lf | %1.4lf | %1.2lf \n", tangent(i, 5), 
            tangent(i, 0.05), tangent(i, 0.0005), tangent(i, 0.000005));
    }
}
#include <stdio.h>

void intercambio(int x, int y);
int intercambioPuntero(int *X, int *Y);

int main(void){
    //intercambio(1,2);
    
    int x=4;
    int y=5;
    int *X=&x;
    int *Y=&y;

    intercambioPuntero(X, Y);

    
}

void intercambio(int x, int y){
    int aux=0;
    printf("antes  x: %d,  y: %d\n",x,y);
    aux=x;
    x=y;
    y=aux;
    printf("desp: x: %d,  y: %d",x,y);
}

int intercambioPuntero(int *X, int *Y){
    int aux;

    printf("antes  x: %d,  y: %d\n",*X,*Y);
    
    aux=*Y;
    *Y=*X;
    *X=aux;
    printf("desp: x: %d,  y: %d",*X,*Y);
    return 0;
}
#include<stdio.h>
#include<math.h>

int main(void){
    printf(" sin(x)     | cos(x)     | tan(x)     | \n");
    int theta=45;
    for(theta;theta<=90;theta=theta+5){
        double res_sin,res_cos,res_tan;
        res_sin=sin(theta);
        res_cos=cos(theta);
        res_tan=tan(theta);
        printf("%d | %d | %d | \n",res_sin,res_cos,res_tan);

    }
}

#include<stdio.h>
#include<math.h>


float DegToRad(float angle);
int trig_sin();
int trig_cos();
int trig_tan();

int main(void){
    printf("-----+-----+ -----\n");
    trig_sin();
    trig_cos();
    trig_tan(); 
    printf("-----+-----+ -----\n");
}

float DegToRad(float angle){
    float res=0.0174532925*angle;
    return res;
}
int trig_sin(){
    int theta=0;
    printf("========================\n");
    printf("sin(x)\n");
    for(theta;theta<=90;theta=theta+5){
        float res_sin;
        res_sin=sinf(DegToRad(theta));
        printf("%d | %2d | %3d | %4d |%x\n",theta,res_sin,res_sin,res_sin,res_sin);
    }
}
int trig_cos(){
    int theta=0;
    printf("========================\n");
    printf("cos(x)\n");
    for(theta;theta<=90;theta=theta+5){
        float res_cos;
        res_cos=cosf(DegToRad(theta));
        printf("%d | %2d | %3d | %4d |%x\n",theta,res_cos,res_cos,res_cos,res_cos);
    }
}
int trig_tan(){
    int theta=0;
    printf("========================\n");
    printf("tan(x)\n");
    for(theta;theta<=90;theta=theta+5){
        float res_tan;
        res_tan=tanf(DegToRad(theta));
        
        printf("%d | %2d | %3d | %4d |%x\n",theta,res_tan,res_tan,res_tan,res_tan);
    }
}

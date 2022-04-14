#include<stdio.h>
#include<math.h>

#define LowerLimit 0

#define UpperLimit 12

int RaiseIntToPower(int n, int k);

void main(void){
    int n;
    printf("  |  2|  N| hexa\n");
    printf(" N|  2|  N| hexa\n");
    printf("-----+-----+ -----\n");

    for (n=LowerLimit; n<= UpperLimit;n++){
        printf("%2d| %3d |%4d|%x\n",n,
        RaiseIntToPower(n,2),
        RaiseIntToPower(n,2),RaiseIntToPower(2,n));
    }

    printf("\n");
    printf("-----+-----+ -----\n");
}

int RaiseIntToPower(int n, int k){
    int i, result=1;
    for (i=0;i<k;i++){
        result=result*n;//result*=n; es lo mismo, pero es mas eficiente
    }
    return(result);
}


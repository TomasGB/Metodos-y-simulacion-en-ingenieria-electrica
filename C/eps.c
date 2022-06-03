#include <stdio.h>

void main(void){
    double epsilon=1, test;
    int it=0;
    test=epsilon+1;

    while(test>1){
        epsilon/=2;
        test=epsilon+1;
        it++;
    }
    epsilon*=2;
    printf("\n epsilon: %e",epsilon);
}
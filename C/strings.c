#include <stdio.h>
#include <string.h>

void histo (char *s, int h[], int N);
void presentar(int h[], int N);

int letras[26][2];

void main(int argc,char **argv){

    for (int i=65; i<65+26;i++){
        letras[i][0]=(char)i;
        letras[i][1]=0;
        printf("%c:\n",letras[i][0]);
    }
    for (int i=0; i < argc;i++){
        printf("%s \n",argv[i]);

        for (int i=0;(char)**argv[i]=="\0";i++){
            for (int j=0;i<26;j++){
                if (*argv[i]==(char)letras[j][0]){
                    letras[j][1]+=1;
                }
            }
        }

    }

    printf("\n");
    for(int i=0;i<26;i++){
        printf("%c: %d \n",letras[i][0],letras[i][1]);
    }


    
}
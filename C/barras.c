// barra: grafica una serie de valores enteros escalados a un ancho dado de columnas
// compilado: gcc barras.c -obarras
// uso: ./barras ancho {datos} 
// ejm: ./barras 40 5 10 -4 7 8 44
//
// pend: tomar los datos de un archivo de texto.
//
// gck, oct/2020


#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define KWHT  "\x1B[37m" // white
#define CTRLL "\033[2J"  // CTRL-L, clear screen

int main(int, char **);
void barras(int [], int, float, int);
void espacios(int);

int main(int argc, char *argv[]) {
	// ATENTI: demorar la explicación del uso de los argumentos de main()
	// para capturar parámetros pasados en la línea de comando para cuando
	// se haya visto el tema punteros.

  // int dArr[1000];	// 1000 es especulativo
  int *dat, men = INT_MAX, may = INT_MIN, i;		//definidos en limits.h
  float escala;

  if (argc < 3) {
    printf("uso: %s ancho {datos} (ejm: %s 40 5 10 -4 7 8 44).\n", argv[0], argv[0]);
    return -1;
  }
  else
  	if ((dat = (int*)malloc((argc-2)*sizeof(int))) == NULL) {
		  printf("memoria insuficiente.\n");
		  return -1;
  	}

	for (i=2; i<argc; i++) {
		dat[i-2] = atoi(argv[i]);
		if (dat[i-2] < men)
			men = dat[i-2];
			
		if (dat[i-2] > may)
			may = dat[i-2];
	}

	escala = atoi(argv[1]) / (float)(may - men);

	printf("%s %s\n", CTRLL, KWHT);
	barras(dat, argc-2, escala, men);
	printf("\n");
	
  return 0;
}

void barras(int D[], int nD, float s, int men) {
  int d, c;

	for (d=0; d<nD; d++) {
		printf("[%5d]>\t", D[d]);
	
		if (men<0)
			espacios( (int)(D[d] >= 0) ? -men  * s : (D[d] - men) * s );
			//espacios( (int)(D[d] >= 0) ? men  * s : (D[d] - men) * s );

		for (c=D[d]*s; c < 0; c++)
			printf("*");

		printf("|");

		for (c=0; c < D[d]*s; c++)
			printf("*");

		printf("\n");
	}
}

void espacios(int esp) {
	int i;
	for (i=0; i<esp; i++)
		printf(" ");
}
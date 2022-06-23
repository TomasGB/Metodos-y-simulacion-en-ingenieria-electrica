// interpolación Van der Monde
// gck, 2204

#include "vander.h"

void main(int argc, char *argv[]) {
	double *pDat, *pf, *pd, *pA, *pa;
	int dim;	//cantidad de datos
	
  if (argc < 3) {
    printf("\a\tuso: %s arch-de-datos (ejm: %s datos resultado)\n", argv[0], argv[0]);
    printf("\a\t(formato de datos: n, d, f, ... d, f (n: cant. de pares (d,f); d: distancia; f: frecuencia))\n");
    exit(-1);
  }
  
	pDat = inicializar(argv[1], &dim);
	
	if (!pDat) {
		printf("\n\n>> memoria agotada o problemas con el archivo de configuración.");
		exit(-1);
	}
	else {
		pf = (double *) malloc(dim * sizeof(double));			// memoria para frecuencias
		pd = (double *) malloc(dim * sizeof(double));			// memoria para distancias
		pa = (double *) malloc(dim * sizeof(double));			// memoria para coeficientes del interpolador
		pA = (double *) malloc(dim * dim * sizeof(double));	// memoria para Van der Monde
		if (!pf || !pd || !pa || !pA) {
			free(pf); free(pd); free(pA); free(pa); free(pDat);
			printf("\n\n>> memoria agotada.");
			exit(-1);
		}
		else {
			conformar_vectores(pf, pd, pA, pDat, dim);
			pa = gauss(pA, pf, pa, dim);
		}

		if (!grabar(pa, dim, argv[2]))
			printf("\n\n>> no se logró grabar el resultado en %s.", argv[2]);

		free(pf);	free(pd);	free(pA); free(pa); free(pDat);
		printf("\n\n>> Terminado!\a\n");
	}
}

double * inicializar(char *cfgFile, int * dim) {
	// ref: https://stackoverflow.com/questions/3889992/how-does-strtok-split-the-string-into-tokens-in-c
	
	char *cfgStr, *tok;
	double *pDat, *pD;

	if (cfgStr = readFile(cfgFile)) {
		*dim = atoi((tok = strtok(cfgStr, ",\n")));	// cant. de pares (dist, frec)
		
		// memoria para los datos
		if ((*dim < 0) || ((pD = pDat = (double *) malloc((*dim) * 2 * sizeof(double))) == NULL)) {
			free(cfgStr);
			return NULL;
		}
		
		// leer datos
		int i = *dim;
		while (i-- > 0) {
			*pD++ = atof((tok = strtok(NULL, ",\n")));	// distancia
			*pD++ = atof((tok = strtok(NULL, ",\n")));	// frecuencia
		}
	}
	else
		return NULL;
   
	free(cfgStr);
	return pDat;
}

void conformar_vectores(double *pf, double *pd, double *pA, double *pDat, int n) {
	// separa los datos en pDat, en los conformar_vectores pf (frecuencias), pd (distancias) y pA, matriz Van der Monde
	for (int i = 0; i < n; i++) {
		pf[i] = pDat[i * 2];							// frecuencias
		pd[i] = pDat[i * 2 + 1];					// distancias
		for (int j = 0; j < n; j++)
			pA[i * n + j] = pow1(pd[i], j);	// Van der Monde
	}
}

double * gauss(double *pA, double *pf, double *pa, int n) {
	// ref: https://web.mit.edu/10.001/Web/Course_Notes/Gauss_Pivoting.c

	// forward elimination
	for (int k = 0; k < n - 1; k++) {

		// find pivot
		double amax = fabs(pA[k * n + k]), xfac;
		int mxi = k;
		for (int i = k; i < n; i++) {   // for col k, find the row with largest pivot
			xfac = fabs(pA[i * n + k]);
			if (xfac > amax) {
				amax = xfac; mxi = i;
			}
		}

		double temp;
		if (mxi != k) {  // pivoting: rows swapping if neccesary (m != k)
			for (int j = 0; j < n; j++) {	// pA swapping
				temp = pA[k * n + j];	pA[k * n + j] = pA[mxi * n + j]; pA[mxi * n + j] = temp;
			}
			temp = pf[k]; pf[k] = pf[mxi]; pf[mxi] = temp;	// pf swapping
		}

		// fwd elimination, every row after k
		for (int i = k + 1; i < n; i++) {
			double xfac = pA[i * n + k] / pA[k * n + k];
			for (int j = k; j < n; j++)
				pA[i * n + j] = pA[i * n + j] - xfac * pA[k * n + j];
			pf[i] -= xfac * pf[k];
		}
	}	// pA already triangular, right ?

	// back substitution
	for (int j = 0; j < n; j++) {
		int k = n - j - 1;
	  pa[k] = pf[k];
		for(int i = k + 1; i < n; i++)
			pa[k] -= pA[k * n + i] * pa[i];
		pa[k] /= pA[k * n + k];
	}

	return pa;
}

int grabar(double *pa, int n, char *file) {
	FILE *fh;
	if (!(fh = fopen(file, "w")))
		return FALSE;

	for (int i = 0; i < n; i++)
		fprintf(fh, "%f\n", pa[i]);

	fclose(fh);
	return TRUE;
}

char * readFile(char *filename) {
	// lee el archivo de configuración
	// ref: https://stackoverflow.com/questions/3463426/in-c-how-should-i-read-a-text-file-and-print-all-strings
	
	char *buff = NULL;
	FILE *fh;

	if (fh = fopen(filename, "r")) {
		fseek(fh, 0, SEEK_END);	// Seek the last byte of the file
		long stringSz = ftell(fh);	// Offset from the first to the last byte, or in other words, filesize
		rewind(fh);	// go back to the start of the file
		
		buff = (char*) malloc(sizeof(char) * (stringSz + 1) );	// allocate a string that can hold it 
		int readSz = fread(buff, sizeof(char), stringSz, fh);	// read it all at once

		buff[stringSz] = '\0'; // fread doesn't set it, so, put a trailing '\0' so as to configure a string

		if (stringSz != readSz) {
			// Something went wrong, throw away the memory and set the buffer to NULL
			free(buff);
			buff = NULL;
		}
		fclose(fh);
	}

	return buff;
}

double pow1(double b, int n) {
	// b^n
	double res = 1.0;
	for (int i = 0; i < n; i++)
		res *= b;

	return res;
}

double chopit(double X, int Pres) {
  double sgn = (X < 0.0) ? -1.0 : 1.0;
  X = fabs(X);

  return sgn * (floor(X*pow(BASE, Pres)) / pow(BASE, Pres));
}

double roundit(double X, int Pres) {
  double sgn = (X < 0.0) ? -1.0 : 1.0;
  X = fabs(X);
  double Y=X*pow(BASE, Pres);
  
  return sgn * ((Y-floor(Y) > 0.5) ? floor(X*pow(BASE, Pres)+1) / pow(BASE, Pres) : chopit(X, Pres));
}

void show2D(double *pC, int fils, int cols) {	// propósito de debugging
  printf("2D %d %d\n", fils, cols);
  for (int f = 0; f < fils; f++) {
    for (int c = 0; c < cols; c++)
    	printf("%f ", *pC++);
    printf("\n");
  }
}

void show1D(double *pC, int n) {	// propósito de debugging
  printf("1D, %d\n", n);
  for (int i = 0; i < n; i++, pC++) {
   	printf("%f ", *pC);
  }
  printf("\n");
}
// interpolación Van der Monde
// gck, 2204

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>

#define TRUE -1
#define FALSE 0

#define BASE 10

double * inicializar(char *, int *);
void conformar_vectores(double *, double *, double *, double *, int);
double * gauss(double *, double *, double *, int);
int grabar(double *, int, char *);
double pow1(double, int);
char * readFile(char *);
double chopit(double, int);
double roundit(double, int);
void show1D(double *, int);
void show2D(double *, int, int);

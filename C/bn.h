// batalla naval, framework
// gck, 1809, 2010

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define TRUE -1
#define FALSE 0

#define FILS 10 // filas del tablero
#define COLS 10 // columnas del tablero
#define BLANCOS 20 // tamaño de la flota en cantidad de casillas
#define JUGADORES 2 // cantidad de jugadores

// modos de trabajo del radar
#define RADAR 1 // activa lectura de radar y registro
#define REPORTE 2 // activa reporte de registro

#define JUGADOR1 1 // id del jugador
#define JUGADOR2 2 // id del jugador
#define JUGADOR3 3 // id del jugador
#define JUGADOR4 4 // id del jugador
#define JUGADOR5 5 // id del jugador

// marcas en el tablero
#define AGUA 0 	// IMPORTANTE que sea 0, valor por defecto de las variables estáticas
#define NAVE -3 // marcas en el tablero
#define INVALIDO -2 // hit previo
#define TOUCHE -1 // hit exitoso

// screen codes
#define CTRLL "\033[2J"  // CTRL-L, clear screen
#define KNRM  "\x1B[0m"  // reset to default
#define KRED  "\x1B[31m" // red
#define KGRN  "\x1B[32m" // green
#define KYEL  "\x1B[33m" // yellow
#define KBLU  "\x1B[34m" // blue
#define KMAG  "\x1B[35m" // magenta
#define KCYN  "\x1B[36m" // cyan
#define KWHT  "\033[37m" // white

int initS(int [FILS][COLS], int);
void mostrar(int [FILS][COLS], int);
int disparar(int [FILS][COLS], int);
int radar(int, int);
void stat(int [FILS][COLS], int, int);
int disp1(int [FILS][COLS]);
int disp2(int [FILS][COLS]);
int disp3(int [FILS][COLS]);
int disp4(int [FILS][COLS]);
int disp5(int [FILS][COLS]);

int elegirFil(int);
int elegirCol(int);
int azarFil(void);
int azarCol(void);
int radarN(int [FILS][COLS], int, int, int);
int radarS(int [FILS][COLS], int, int, int);
int radarE(int [FILS][COLS], int, int, int);
int radarW(int [FILS][COLS], int, int, int);
int radarNE(int [FILS][COLS], int, int, int);
int radarNW(int [FILS][COLS], int, int, int);
int radarSE(int [FILS][COLS], int, int, int);
int radarSW(int [FILS][COLS], int, int, int);
int fuego(int [FILS][COLS], int, int, int);


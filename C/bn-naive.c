// batalla naval, framework
// gck, 1809, 2010
// Los jugadores escriben su estrategia en las fcs. disp1(), disp2(), ...
// Actualizar en los #define de <bn.h> la cantidad de jugadores y el tamaño del tablero.

// ** ATENTI que hay un BUG ESTRUCTURAL en esta versión: el tablero actualizado
// 	pasa íntegro como dato a cada jugador, por lo que cada uno puede saber en todo
// 	momento dónde están todos los blancos. Esto permite la estrategia óptima.
// 	Se debe modificar el esquema de manera que los jugadores NO TENGAN acceso
// 	a la ubicación global y simultánea de los todos blancos [1], O BIEN, en la estrategia
// 	de cada jugador se debe limitar al uso de las funciones solo a las válidas, impidiendo 
// 	el uso de otras y del acceso directo al tablero. Requiere de un árbitro (persona)
// 	que realice esta supervisión y valide o no las estrategias.
//
//	[1] esto requiere de otro paradigma, de un modelo basado en objetos, con más 
//      flexibilidad para manejar el encapsulado.
//
// posibles consignas:
// * análisis: determinar cómo funciona en general el esquema.
// * análisis: determinar cuál es el bug estructural del diseño.
// * diseño (alto nivel): diseñar estrategias para los jugadores.

#include "bn.h"


void main(void) {
  int S[FILS][COLS], jug, aFlote = BLANCOS, ch, t=0, sigue;

  srand(time(NULL));	// inicializa gen. aleatorio

  aFlote = initS(S, BLANCOS);
  mostrar(S, t++);

	sigue = TRUE;
  while (sigue)
    for (jug=1; jug<=JUGADORES; jug++) {
      if (disparar(S, jug) == TOUCHE)
        aFlote--;

      mostrar(S, t++);

      if ((ch = getchar()) == 'q')	// finaliza el juego
        aFlote = 0;

      if (aFlote == 0) {
        stat(S, FILS, COLS);
        sigue = FALSE;
        break;
      }
    }
}

// Inicializa el tablero ocupando no más de Blancos celdas con NAVE. El resto con AGUA.
// Devuelve la cantidad de celdas ocupadas con NAVE (blancos a hundir).
int initS(int Mar[FILS][COLS], int Blancos) {
  int f, c, Eslora, i, Bl=0;

  for (f = 0; f < FILS; f++)
    for (c = 0; c < COLS; c++)
      Mar[f][c] = AGUA;

  while (Blancos>0) {
    Eslora = 2 + (rand() % 3);	// eslora (2..4)
    Blancos -= Eslora;
    f = rand() % FILS;
    c = rand() % COLS;
 
    if (rand() % 2)  // horizontal
      if (c + Eslora > COLS - 1)  // excede al tablero
        for (i = 0; i < Eslora; i++)
          Mar[f][(COLS - Eslora) + i] = NAVE;
      else
        for (i=0; i < Eslora; i++)
          Mar[f][c + i] = NAVE;

    else  // vertical
      if (f + Eslora > FILS - 1)  // excede al tablero
        for (i = 0; i < Eslora; i++)
          Mar[(FILS - Eslora) + i][c] = NAVE;
      else
        for (i = 0; i < Eslora; i++)
          Mar[f + i][c] = NAVE;
  }

  // dado que los NAVEs se pueden haber superpuesto es necesario contar la cantidad de celdas con blancos
  for (f = 0; f < FILS; f++)
    for (c = 0; c < COLS; c++)
      if (Mar[f][c] == NAVE)
        Bl++;

  return(Bl);
}

// muestra el tablero general en su estado actual
void mostrar(int Mar[FILS][COLS], int T) {
  int f, c;

  printf(CTRLL); // limpiar la pantalla

  // borde superior del tablero
  printf(KWHT);
  printf(">> batalla naval ([ENTER] siguiente; [q] finaliza) <<\n\n");
  for (c=0; c<COLS*2; c++)
    printf("=");
  printf("\n");

  // tablero actual
  for (f=0; f<FILS; f++) {
    for (c=0; c<COLS; c++)
      switch(Mar[f][c]) {
      case NAVE:
        printf("%sO ", KWHT);
        break;
      case AGUA:
        printf("%s  ", KWHT);
        break;
      case JUGADOR1:
        printf("%s1 ", KRED);
        break;
      case JUGADOR2:
        printf("%s2 ", KGRN);
        break;
      case JUGADOR3:
        printf("%s3 ", KBLU);
        break;
      case JUGADOR4:
        printf("%s4 ", KYEL);
        break;
      case JUGADOR5:
        printf("%s5 ", KMAG);
        break;
      default:
        break;
    }
    printf("\n");
  }

  // borde inferior del tablero
  printf(KWHT);
  for (c=0; c<COLS*2; c++)
    printf("=");
  printf(" <<%d>>\n",T);
}

// presenta la estadística de resultados
void stat(int Mar[FILS][COLS], int Fils, int Cols) {
  int f, c, Jug, puntaje[JUGADORES+1], win, consultas, winner=0;

  printf("\n\n");

  for (Jug=1; Jug<=JUGADORES; Jug++)	// inicializa registro de puntos logrados
    puntaje[Jug] = 0;

  for (f=0; f<Fils; f++)
    for (c=0; c<Cols; c++)
      switch(Mar[f][c]) {
      case NAVE:
      case AGUA:
        break;
      default:
        puntaje[Mar[f][c]]++;
        break;
    }

	// contabilidad de blancos
	float mxRate = 0.0, Rate;
  for (Jug=1; Jug<=JUGADORES; Jug++) {
    printf("jugador %d ==> %d aciertos, %d consultas al tablero, rel: %f.\n", Jug, puntaje[Jug], radar(Jug, REPORTE), Rate = (float) puntaje[Jug] / radar(Jug, REPORTE));
	  if (Rate > mxRate) {
	  	winner = Jug;
	  	mxRate = Rate;
	  }
  }

	/* ---------------------
	win = 0;
  for (Jug=1; Jug<=JUGADORES; Jug++)
    if (puntaje[Jug] > win)
			win = puntaje[Jug];

	// contabilidad de consultas al tablero
	consultas = INT_MAX;	// máximo valor posible para un entero
  for (Jug=1; Jug<=JUGADORES; Jug++) {
    if (puntaje[Jug] == win) {
    	if (radar(Jug, REPORTE) < consultas) {
		    winner = Jug;
				consultas = radar(Jug, REPORTE);
    	}
		}
  }
	-------------- */
	
  printf("\n...and the winner is... %sTADAAA.... %sEL #%d !!!!\n", KRED, KGRN, winner);
  printf("\n%sGame over.\n",KNRM);
}

int disparar(int Mar[FILS][COLS], int JugNo) {
  switch(JugNo) {
    case JUGADOR1:
      return(disp1(Mar));
    case JUGADOR2:
      return(disp2(Mar));
    case JUGADOR3:
      return(disp3(Mar));
    case JUGADOR4:
      return(disp4(Mar));
    case JUGADOR5:
      return(disp5(Mar));
  }
}

////////////////////////////////////////////
// estrategias de disparo de cada jugador //
////////////////////////////////////////////

int disp1(int Mar[FILS][COLS]) {
  // resultados posibles: TOUCHE, AGUA, INVALIDO
  int f, c, tol;
  static int map_aux[FILS][COLS]={0};

	// válidas: elegirFil(), elegirCol(); azarFil(); azarCol()
	// válidas: radarS(), radarN(); radarE(); radarW(), radarSE(), radarSW(); radarNE(); radarNW()
	// válidas: fuego()
	// válido: utilizar un mapa (estático) local
	// INválido: acceder a Mar[][] de manera directa o iterar sobre la misma

  tol=0; //para cuando se completan todas las filas impares

  f=azarFil();
  if ((f%2==0)){
    f+=1;
  }
  c=0;

  if (f==0){
    f++;
  }

  while((map_aux[f][c]==-1) && tol<10){

    while(((f%2)==0)){
      f+=1;
    }
    c=azarCol(); 

    if (tol=9){
      while (((f%2)!=0) && (map_aux[f][c]==-1))
      {
        f=azarFil();
        tol=0;
      }
      
    }   
    tol++;
  }

  map_aux[f][c]=-1;

  /*
   // tablero auxiliar
    printf("(%d  %d)\n",f,c);

    elegirFil(f);
    elegirCol(c);
    for (int i = 0; i < 10; i++){
      for (int j = 0; j < 10; j++){
        printf("%d ",map_aux[i][j]);
      }
      printf("\n");
    }
  */

  return fuego(Mar, f, c, JUGADOR1);
}

int disp2(int Mar[FILS][COLS]) {
  // resultados posibles: TOUCHE, AGUA, INVALIDO
  int f, c;

	// válidas: elegirFil(), elegirCol(); azarFil(); azarCol()
	// válidas: radarS(), radarN(); radarE(); radarW(), radarSE(), radarSW(); radarNE(); radarNW()
	// válidas: fuego()
	// válido: utilizar un mapa (estático) local
	// INválido: acceder a Mar[][] de manera directa o iterar sobre la misma

  // ejm - estrategia: disparos al azar
  f = azarFil();
  c = azarCol();
  return fuego(Mar, f, c, JUGADOR2);
}

int disp3(int Mar[FILS][COLS]) {
  // resultados posibles: TOUCHE, AGUA, INVALIDO
  int f, c;

	// válidas: elegirFil(), elegirCol(); azarFil(); azarCol()
	// válidas: radarS(), radarN(); radarE(); radarW(), radarSE(), radarSW(); radarNE(); radarNW()
	// válidas: fuego()
	// válido: utilizar un mapa (estático) local
	// INválido: acceder a Mar[][] de manera directa o iterar sobre la misma

  // ejm - estrategia: disparos al azar
  f = azarFil();
  c = azarCol();
  return fuego(Mar, f, c, JUGADOR3);
}

int disp4(int Mar[FILS][COLS]) {
  // resultados posibles: TOUCHE, AGUA, INVALIDO
  int f, c;

	// válidas: elegirFil(), elegirCol(); azarFil(); azarCol()
	// válidas: radarS(), radarN(); radarE(); radarW(), radarSE(), radarSW(); radarNE(); radarNW()
	// válidas: fuego()
	// válido: utilizar un mapa (estático) local
	// INválido: acceder a Mar[][] de manera directa o iterar sobre la misma

  // ejm - estrategia: disparos al azar
  f = azarFil();
  c = azarCol();
  return fuego(Mar, f, c, JUGADOR4);
}

int disp5(int Mar[FILS][COLS]) {
  // resultados posibles: TOUCHE, AGUA, INVALIDO
  int f, c;

	// válidas: elegirFil(), elegirCol(); azarFil(); azarCol()
	// válidas: radarS(), radarN(); radarE(); radarW(), radarSE(), radarSW(); radarNE(); radarNW()
	// válidas: fuego()
	// válido: utilizar un mapa (estático) local
	// INválido: acceder a Mar[][] de manera directa o iterar sobre la misma

  // ejm - estrategia: disparos al azar
  f = azarFil();
  c = azarCol();
  return fuego(Mar, f, c, JUGADOR5);
}

//////////////////////////////////////////////////
// funciones válidas, auxiliares a los disparos //
//////////////////////////////////////////////////

int elegirFil(int f) {
	if (f < 0)
		f = 0;

	if (f > FILS)
		f = FILS;

  return f;
}

int elegirCol(int c) {
	if (c < 0)
		c = 0;

	if (c > COLS)
		c = COLS;

  return c;
}

int azarFil(void) {
  return rand() % FILS;
}

int azarCol(void) {
  return rand() % COLS;
}

int radarN(int Mar[FILS][COLS], int Jug, int f, int c) {
	radar(Jug, RADAR);
	if (f == 0)
		return INVALIDO;
	else
		return Mar[f-1][c];
}

int radarS(int Mar[FILS][COLS], int Jug, int f, int c) {
	radar(Jug, RADAR);
	if (f == FILS-1)
		return INVALIDO;
	else
		return Mar[f+1][c];
}

int radarE(int Mar[FILS][COLS], int Jug, int f, int c) {
	radar(Jug, RADAR);
	if (c == COLS-1)
		return INVALIDO;
	else
		return Mar[f][c+1];
}

int radarW(int Mar[FILS][COLS], int Jug, int f, int c) {
	radar(Jug, RADAR);
	if (c == 0)
		return INVALIDO;
	else
		return Mar[f][c-1];
}

int radarNE(int Mar[FILS][COLS], int Jug, int f, int c) {
	radar(Jug, RADAR);
	if (f == 0 || c == COLS-1)
		return INVALIDO;
	else
		return Mar[f-1][c+1];
}

int radarNW(int Mar[FILS][COLS], int Jug, int f, int c) {
	radar(Jug, RADAR);
	if (f == 0 || c == 0)
		return INVALIDO;
	else
		return Mar[f-1][c-1];
}

int radarSE(int Mar[FILS][COLS], int Jug, int f, int c) {
	radar(Jug, RADAR);
	if (f == FILS-1 || c == COLS-1)
		return INVALIDO;
	else
		return Mar[f+1][c+1];
}

int radarSW(int Mar[FILS][COLS], int Jug, int f, int c) {
	radar(Jug, RADAR);
	if (f == FILS-1 || c == 0)
		return INVALIDO;
	else
		return Mar[f+1][c-1];
}

int radar(int Jug, int Modo) {
	// mantiene, para cada jugador, un registro de las veces que consultó posiciones en el tablero.
	// ganar el juego requiere mínima cantidad de rondas y a al vez mínima cantidad de consultas.
	static int cuentaConsultas[JUGADORES+1];

	// Jug > 0: actualiza la cuenta;	Jug <= 0: solo consulta la cuenta
	if (Modo == RADAR)
		cuentaConsultas[Jug]++;

	return cuentaConsultas[Jug];
}

int fuego(int Mar[FILS][COLS], int f, int c, int Jug) {
	// devuelve TOUCHE, AGUA o INVALIDO

	radar(Jug, RADAR);	//cada tiro cuenta también como acceso al tablero

  switch(Mar[f][c]) {
  case NAVE:
		// en el blanco!
    Mar[f][c] = Jug;
    return TOUCHE;
  case AGUA:
		// fue al agua
    return AGUA;
  default:
		// tenía ya un acierto
    return INVALIDO;
  }
}


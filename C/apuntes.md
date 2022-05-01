# Tipos de datos

## Primitivos
    void

## Escalares ( <limits.h> )
    * signed / unsigned -- tipo char

    * long / short / signed / unsigned -- tipo int

    valor escalar == 0 es False / != 0 es True

    En C no existe un true o false, se hace con variables escalares, se puede usar #define una variable FALSE y asignarle 0.
    
    #define FALSE (1==0);
    #define TRUE (1==1);

## Con parte fraccionaria ( <float.h> )

    * float
    * (long) double

## derivados 

    * arreglos
    * referencias(&)
    * punteros(*)

## definidos por el usuario

    * Estructuras (struct)
    * union(union)
    * enumerados (enum)

# Visibilidad

    * globales
    * locales

# Tiempo de vida

Durante cuanto tiempo ocupan lugar en memoria.

    * automáticas 
    * estáticas (que no se borran por mas que sea local (static) )

# Almacenamiento

memoria lejana (heap)

    - variables globales
    - variables estáticas
    - memoria libre

pila (stack)

    - variables locales
    - direcciones de retorno

código

    En ejecución

# Arreglos

    La primer celda es la número 0, y la última es N-1 y el operador de acceso es '[ ]'

    se declaran como:
    
     
     - float f[40]; 
      
     - char c1[]={14,28,'@`,'x',124};

    para saber el tamaño del arreglo: 
    
    ``
    (int)sizeof(nombreArreglo)/sizeof(tipoDeDatoDelArreglo)
    ``

## Estructuras

````
typedef struct{
    int dia;
    int mes;
    int anio;
}tyFecha;

typedef struct{
    int nombre;
    int edad;
    int peso;
    tyFecha fecha_nacimiento;
}tyPaciente;

````

para acceder a los campos es con ' . ', y para inicializar la variable es con 

`tyPaciente paciente1={datos};`

```
void paciente1(tyPaciente);
paciente1.nombre;

```

## Uniones

Como los struct pero estan en un solo registro de memoria
para acceder a los campos es con ' . '

```

typedef union{
    int i;
    float f;
}tyU;

```

## Enumerados

```

enum = Dias{Lun = 1, Mar = 2};

```

## Punteros

C no cuenta con pasaje por referencia, hay que implementarlos manualmente

```
& - direccion en la memoria de una variable

* - contenido de un espacio en la memoria (apuntado)

```

char *pC es la direccion de memoria del char, pC es la variable

pC = &C devuelve la direccion de memoria

con *pC=0, asigno 0


el nombre de un arreglo es un puntero a la primera celda


## punteros con arreglos

````
void f1(float A[], int N);  o  void f1(float *A, int N);

f1(A,500);

````

## memoria lejana

'stdlib.h' 'alloc.h' 'malloc.h'

void *calloc(int N, int B) // N celdas de B bytes
void *malloc(unsigned long B) // B bytes
void *realloc(void *, int B) // extiende a B bytes 
void free(void *) //libera

## strings

<string.h>

funciones:

strlen(),strcpy(), strcat(),strcmp(),strstr()

# Ficheros


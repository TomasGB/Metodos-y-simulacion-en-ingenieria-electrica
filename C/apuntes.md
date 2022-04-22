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
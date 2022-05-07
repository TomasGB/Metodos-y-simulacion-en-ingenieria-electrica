function distancia = dist( posicion,dim)
%{
    /*
        autores: Tomas Gomez, Franco del Pardo, Santiago Palma, Facundo
        Paez
        fecha: 17/04
        finalidad: calcular la distancia de la posicion al eje del centro
        argumentos de entrada:
            + posicion: posicion en el tablero
            + dim: dimension del tablero    
        argumentos de salida: 
            + distancia: distancia de la posicion al eje del centro
        ejemplo de invocacion: dist(i,dim/2)
    */

%}
    distancia=abs((dim)-posicion);
end


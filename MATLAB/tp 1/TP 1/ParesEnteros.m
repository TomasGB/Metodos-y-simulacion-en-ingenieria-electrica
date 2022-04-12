function b=ParesEnteros(N)
    %{
        Autores: Gomez, Tomás y Palma, Santiago
        Fecha: 26/03/2022
        Argumentos de entrada: * N :Numero entero del cual se quiere conocer sus
        ternas.
        Argumentos de Salida: * b: Matriz de dos columnas conteniendo las ternas.
        línea de invocación: ParesEnteros(5)

        Ejemplo:
                ParesEnteros(5)

                ans =

                     1     4
                     2     3
                     3     2
                     4     1
    %}

    clc
    %Pares
    b=([]); %matriz vacía en la que se concatenan las filas con los pares
    for a=1:(N-1) 
        b(a,:)=([a,N-a]);
    end
end
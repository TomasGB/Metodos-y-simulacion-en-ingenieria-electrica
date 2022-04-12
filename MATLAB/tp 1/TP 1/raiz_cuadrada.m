function res = raiz_cuadrada(N)
%{
        Autores: Del Pardo, Franco y Paez, Facundo
        Fecha: 25/03/2022
        Argumentos de entrada: * N :Numero entero del cual se quiere calcular su raiz cuadrada.
        Argumentos de Salida: * res: Matriz de tres columnas conteniendo las ternas.
        
        línea de invocación: raiz_cuadrada(2)

        Ejemplo:
                raiz_cuadrada(2)
                
                ans =

                    1.4142
%}


    a=N;
    error = 0.0001;
    res=0;

    while (res*res)<a && (a-(res*res))> error
        res=res+error;
    end
    
    
end
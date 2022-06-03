function res = raiz_cuadrada(N)
%{
        Autores: Del Pardo, Franco y Paez, Facundo
        Fecha: 25/03/2022
        Argumentos de entrada: * N :Numero entero del cual se quiere calcular su raiz cuadrada.
        Argumentos de Salida: * res: Matriz de tres columnas conteniendo las ternas.
        
        l�nea de invocaci�n: raiz_cuadrada(2)

        Ejemplo:
                raiz_cuadrada(2)
                
                ans =

                    1.4142
%}

    tol = 0.0001;
    res=N/2;

    if (N-(res*res)) < 0
        error=-1*((N-(res*res)));
    end
    
    while error > tol
        
        if(res*res)>N
            res=res-(res/2);
        else
            res=res+(res/2);
        end
        
        if (N-(res*res)) < 0
            error=-1*((N-(res*res)));
        else
            error=((N-(res*res)));

        end

        
    end
    
    
end
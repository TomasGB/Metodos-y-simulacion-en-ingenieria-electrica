function F = TernasEnteros(N)
    %{
        Autores: Gomez, Tomás  y Palma, Santiago
        Fecha: 26/03/2022
        Argumentos de entrada: * N :Numero entero del cual se quiere conocer sus
                                    ternas.
        Argumentos de Salida: * F: Matriz de tres columnas conteniendo las ternas.
        línea de invocación: TernasEnteros(7)

        Ejemplo:
                TernasEnteros(5)
                
                ans =

                     1     1     3
                     1     2     2
                     1     3     1
                     2     1     2
                     2     2     1
                     3     1     1
    %}
    clc
    %ternas
    
    f=[]; %matriz vacía en la que se concatenan las filas con las ternas
    for a_2 = 1:N-2 %hasta N-2 para poder armar ternas
        for b_2 = 1:N-(a_2)-1 %se le resta 1 para completar la terna
            f=[f;[(a_2),(b_2),N-((a_2)+(b_2))]];      
        end
    end
    F=f;
end
    
    
    
    
    
    
    
function [matriz_A,matriz_B,promedio,dif,proporcion] = Matrices(Dim)
    %{
        Autores: Gomez, Tomás
        Fecha: 01/04/2022
        Argumentos de entrada: * Dim: Dimension de la matriz A.

        Argumentos de Salida: * matriz_A: Matriz exterior de dimension Dim.
                              * matriz_B: Matriz inscripta dentro de la matriz A.
                              * promedio: promedio de valores en las celdas de la matriz B.
                              * dif: diferencia entre la suma de los valores en las filas 
                                     pares y la suma de los valores en las columnas impares
                                     de la matriz B.
                              * proporcion: proporcion entre la suma de las diagonales de B 
                                            y la suma de la diagonal de A.

        línea de invocación: [matriz_A,matriz_B,promedio,dif,proporcion] = Matrices(10)

        Ejemplo:
                [matriz_A,matriz_B,promedio,dif,proporcion] = Matrices(10)
                
                coord_1
                     1     2

                coord_2
                     7     8


                matriz_A =

                    62    91    86    21    58    47    94    26    12    91
                    86    99    29    28    50    28    76    46    86    20
                    77    79    60    23    21    96    77    22    60    99
                    63    62    67    27    54    17    15    12    87    59
                    32    94    12    13    87    19    88    95    41    74
                    70    62    65    67    89    22    95    37    50   100
                    17    11    42    35    34    25    99    36    14    36
                    66    20    14    59    28    66    88    40    26    47
                    70    88    54    73    61    62    81    52    70    52
                    76    54    27    55    68    14    56    68    40    79


                matriz_B =

                    91    86    21    58    47    94    26
                    99    29    28    50    28    76    46
                    79    60    23    21    96    77    22
                    62    67    27    54    17    15    12
                    94    12    13    87    19    88    95
                    62    65    67    89    22    95    37
                    11    42    35    34    25    99    36


                promedio =

                   51.7959


                dif =

                  -444


                proporcion =

                    3.8775
    %}
    clc

    matriz_A=randi([10,100],Dim);

    %genera las coordenadas aleatoriamente 

    y_1=randi([2,Dim-1],1);

    if y_1 <=5
        y_2=randi([y_1+1,Dim-1],1);
    else
        y_2=randi([2,y_1-1],1);
    end

    r=abs(y_2-y_1);

    x_1= randi([r+1,Dim-1],1);

    if x_1 <=5
        x_2=x_1+abs(y_2-y_1);
    else
        x_2=x_1-abs(y_2-y_1);
    end

    if x_1 < x_2
        if y_1 < y_2
            coord_1=[x_1,y_1];
            coord_2=[x_2,y_2];
        else
            coord_1=[x_1,y_2];
            coord_2=[x_2,y_1];
        end
    else
        if y_1 < y_2
            coord_1=[x_2,y_1];
            coord_2=[x_1,y_2];
        else
            coord_1=[x_2,y_2];
            coord_2=[x_1,y_1];
        end
    end

    disp('')
    disp('coord_1')
    disp(coord_1)
    disp('coord_2')
    disp(coord_2)


    matriz_B=matriz_A(coord_1(1):coord_2(1),coord_1(2):coord_2(2));

    promedio=mean(matriz_B(:));

    impares=matriz_B(1:2:end,:);
    %disp(impares)

    pares=matriz_B(2:2:end,:);
    %disp(pares)

    %{
    la funcion sum() aplicada a una matriz devuelve un vector
    con las sumas de cada fila, y le aplicamos sum() otra vez
    para hacer la suma total
    %}

    dif=sum(sum(pares))-sum(sum(impares));

    %genera las diagonal principal multiplicando la matriz
    %por la matriz identidad elemento a elemento

    diagonal_A=matriz_A.*eye(length(matriz_A));

    %{
    la suma de las diagonales de la matriz B va a ser la suma de todos
    los elementos de la matriz, menos el elemento de la primer columna y 
    ultima fila y el elemento de la ultima columna y primer fila

    ejemplo

    matriz B          | Diagonales          | suma de las diagonales
    85    26    48    | 42 + 11 = 53        | 53 + 216 + 74 = 343
    42    79    48    | 85 + 79 + 52 = 216  |
    23    11    52    | 26 + 48 = 74

    %}
    
    suma_diag_B=sum(sum(matriz_B))-matriz_B(1,end)-matriz_B(end,1);
    suma_diag_A=sum(sum(diagonal_A));
    
    %calcula la proporcion
    proporcion=suma_diag_B/suma_diag_A;
end




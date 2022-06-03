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
                     5     2

                coord_2
                     6     3


                matriz_A =

                    57    94    79    87    30    86    68    82    30    11
                    39    24    71    56    69    76    26    77    83    72
                    59    93    75    67    65    61    14    83    99    81
                    46    82    68    96    45    26    75    44    12    58
                    47    62    48    50    22    97    41    66    58    90
                    26    50    45    15    12    34    70    62    17    91
                    33    33    84    88    48    94    44    58    82    66
                    11    78    38    67    26    30    67    35   100    22
                    94    30    84    42    76    43    11    32    16    29
                    69    15    81   100    43    17    92    51    95    26


                matriz_B =

                    62    48
                    50    45


                promedio =

                   51.2500


                dif =

                   -17


                proporcion =

                    0.1604
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

    impares=matriz_B(:,1:2:end,:);
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

    diagonal_ppal_A=diag(matriz_A);
    diagonal_secundaria_A=diag(matriz_A,-1);
    
    diagonal_ppal_B=diag(matriz_B);
    diagonal_secundaria_B=diag(matriz_B,-1);
    
    suma_diag_B=sum(diagonal_ppal_B)+sum(diagonal_secundaria_B);
    suma_diag_A=sum(diagonal_ppal_A)+sum(diagonal_secundaria_A);
    
    %calcula la proporcion
    proporcion=suma_diag_B/suma_diag_A;
end




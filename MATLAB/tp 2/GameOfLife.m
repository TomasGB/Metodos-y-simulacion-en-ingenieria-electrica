function T=GameOfLife(tablero,dim,generaciones)
%{
    /*
        autores: Tomas Gomez, Franco del Pardo, Santiago Palma, Facundo
        Paez
        fecha: 17/04
        finalidad: Simular el 'Juego de la vida' en version esferica
        argumentos de entrada:
            + tablero: tablero con el estado inicial
            + dim: dimension del tablero
            + generaciones: numero de generaciones a simular
        
        argumentos de salida: la funcion no posee argumentos de salida.
        ejemplo de invocacion: GameOfLife(tablero,dim,200)
    */

%}
%{
    Antes de llamar la funcion, definir las dimensiones del tablero
    en una variable llamada 'dim' y despues generar un tablero con:
 
    tablero=rand(dim,dim)>.4;

    o leerlo de un archivo con: tablero=dlmread('tablero.txt');

    para guardar un tablero: dlmwrite('tablero_2.txt',tablero)
%}
    
    clc
    diametro=dim-5; %para evitar problemas en los bordes del tablero
    radio=diametro/2;
    centro=dim/2;

    tablero_aux(1:dim,1:dim)=0.5;

    for generacion=1:generaciones
    vivos=0;

        for i=1:dim
            for j=1:dim
                if ((i-centro)^2)+((j-centro)^2)<((radio)^2)
                    %adentro del circulo
                    tablero_aux(i,j)=CheckInterior(i,j,tablero);
                elseif ((i-centro)^2)+((j-centro)^2)==(radio^2)
                    %en el borde
                    tablero_aux(i,j)=CheckBorder(i,j,tablero,dim);
                    %tablero_aux(i,j)=1;
                    
                elseif ((i-centro)^2)+((j-centro)^2)>(radio^2)
                    %fuera de la esfera mueren automaticamente
                    %tablero_aux(i,j)=0.5;
                end %if
            end %end for j
        end %end for i

        imshow(tablero_aux,'InitialMagnification',350)
        title(strcat({'generacion: '},num2str(generacion)));
        drawnow();
        tablero=tablero_aux;
    end%end for
end

    
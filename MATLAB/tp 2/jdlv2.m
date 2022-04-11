clear
clc


dim=100;
tablero=rand(dim,dim)>.4;%randi([0,1],dim,dim);

diametro=dim-10;%para evitar problemas en los bordes
radio=diametro/2;
centro=dim/2;

tablero_aux=[];

for generacion=1:100
vivos=0;

    for i=1:dim
        for j=1:dim
            if ((i-centro)^2)+((j-centro)^2)<((radio)^2)
                %adentro del circulo
                res=check(i,j,tablero);
                tablero_aux(i,j)=res;
            elseif ((i-centro)^2)+((j-centro)^2)==(radio^2)
                %en el borde
                tablero_aux(i,j)=0;
            elseif ((i-centro)^2)+((j-centro)^2)>((radio)^2)
                %fuera de la esfera mueren automaticamente
                tablero_aux(i,j)=0.5;
                
            end %if
        end %end for j
    end %end for i

    imshow(tablero_aux,'InitialMagnification',350)
    title(strcat({'generacion: '},num2str(generacion)));
    drawnow();
    tablero=tablero_aux;
end%end for

    
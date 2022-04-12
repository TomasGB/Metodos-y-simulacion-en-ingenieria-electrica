diametro=100;

tablero=zeros(diametro,diametro);

for i=1:diametro
    for j=1:diametro
        if ((i-(diametro/2))^2)+((j-(diametro/2))^2)<((diametro/2)^2);
            %juego de la vida funcion
            tablero(i,j)=rand(1)>.9;
            
        elseif ((i-(diametro/2))^2)+((j-(diametro/2))^2)==((diametro/2)^2)
            tablero(i,j)=0;
        else ((i-(diametro/2))^2)+((j-(diametro/2))^2)>=((diametro/2)^2);
            tablero(i,j)=0.5;
        end
    end
end

imshow(tablero,'Initialmagnification',350);
drawnow();
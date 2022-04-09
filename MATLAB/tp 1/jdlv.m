clear
clc

dim=100;
tablero=rand(dim,dim)>.4;%randi([0,1],dim,dim);
tablero(1,:)=0;
tablero(dim,:)=0;
tablero(:,1)=0;
tablero(:,dim)=0;

tablero_aux=[];

for l=1:300
vivos=0;

for i=2:dim-1
    for j=2:dim-1
        if tablero(i+1,j) == 0
            vivos=vivos;
        else
            vivos=vivos+1;
        end
        
        if tablero(i+1,j+1) == 0
            vivos=vivos;
        else
            vivos=vivos+1;
        end
        if tablero(i,j+1) == 0
            vivos=vivos;
        else
            vivos=vivos+1;
        end
        if tablero(i-1,j+1) == 0
            vivos=vivos;
        else
            vivos=vivos+1;
        end
        if tablero(i-1,j) == 0
            vivos=vivos;
        else
            vivos=vivos+1;
        end
        if tablero(i-1,j-1) == 0
            vivos=vivos;
        else
            vivos=vivos+1;
        end
        if tablero(i,j-1) == 0
            vivos=vivos;
        else
            vivos=vivos+1;
        end
        if tablero(i+1,j-1) == 0
            vivos=vivos;
        else
            vivos=vivos+1;
        end
        
        
        % controla si para la proxima generacion vive o muere
        if tablero(i,j)==0 && vivos== 3
            tablero_aux(i,j)=1;
        end
        
        if tablero(i,j)==0 && (vivos<3 || vivos > 3)
            tablero_aux(i,j)=0;
        end
        
        if tablero(i,j)==1 && (vivos<2 || vivos>3) 
            tablero_aux(i,j)=0;
        end
        
        if tablero(i,j)==1 && (vivos== 3 || vivos==2)
            tablero_aux(i,j)=1;
        end
    vivos=0;
        
    end %end for
end
    
    %disp('tablero original')
    %disp(tablero)
    
    %disp('tablero nuevo')
    tablero_aux(dim,:)=0;
    tablero_aux(:,dim)=0;
    %disp(tablero_aux)
  
 
 imshow(tablero_aux,'InitialMagnification',350)
 title(strcat({'generacion: '},num2str(l)));
 drawnow();
 tablero=tablero_aux;
end
    
    
function H = CheckBorder(i,j,tablero,dim)
    vivos=0;
    
    if (i>=(dim/2))&&(j>=(dim/2))
        %1er cuadrante
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
        
        if tablero(i,(dim/2)-abs((dim/2)-j)) == 0
        %if tablero(i,j+1) == 0
            vivos=vivos;
        else
            vivos=vivos+1;
        end
        
        %if tablero(i-1,j+1) == 0
        if tablero(i-1,(dim/2)-abs((dim/2)-j)+1) == 0
            vivos=vivos;
        else
            vivos=vivos+1;
        end
        
        %if tablero(i-1,j) == 0
        if tablero(i-1,(dim/2)-abs((dim/2)-j)) == 0
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
        
    elseif (i<=(dim/2))&&(j>=(dim/2))
        %2do cuadrante
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
        
        if tablero((dim/2)-abs((dim/2)-i)-1,j)==0
        %if tablero(i-1,j) == 0
            vivos=vivos;
        else
            vivos=vivos+1;
        end
        
        if tablero((dim/2)-abs((dim/2)-i)-1,j-1) == 0
        %if tablero(i-1,j-1) == 0
            vivos=vivos;
        else
            vivos=vivos+1;
        end
        
        if tablero(i,(dim/2)-abs((dim/2)-j)-1) == 0
        %if tablero(i,j-1) == 0
            vivos=vivos;
        else
            vivos=vivos+1;
        end
        if tablero(i+1,j-1) == 0
            vivos=vivos;
        else
            vivos=vivos+1;
        end
        
    elseif (i<(dim/2))&&(j<(dim/2))
        %3er cuadrante
        
        if tablero((dim/2)-abs((dim/2)-i)+1,j)==0
        %if tablero(i+1,j) == 0
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
        
        if tablero(i,(dim/2)-abs((dim/2)-j)-1)==0
        %if tablero(i,j-1) == 0
            vivos=vivos;
        else
            vivos=vivos+1;
        end
        
        if tablero((dim/2)-abs((dim/2)-i)+1,(dim/2)-abs((dim/2)-j)-1)==0
        %if tablero(i+1,j-1) == 0
            vivos=vivos;
        else
            vivos=vivos+1;
        end
    elseif (i>(dim/2))&&(j<(dim/2))
        %4to cuadrante
        
        if tablero((dim/2)-abs((dim/2)-i)+1,j)==0
        %if tablero(i+1,j) == 0
            vivos=vivos;
        else
            vivos=vivos+1;
        end
        
        if tablero((dim/2)-abs((dim/2)-i)+1,(dim/2)-abs((dim/2)-j)+1)==0
        %if tablero(i+1,j+1) == 0
            vivos=vivos;
        else
            vivos=vivos+1;
        end
        
        if tablero(i,(dim/2)-abs((dim/2)-j)+1)==0
        %if tablero(i,j+1) == 0
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
 
        if tablero(i,(dim/2)-abs((dim/2)-j)-1)==0
        %if tablero(i,j-1) == 0
            vivos=vivos;
        else
            vivos=vivos+1;
        end
        
        if tablero((dim/2)-abs((dim/2)-i)+1,(dim/2)-abs((dim/2)-j)-1)==0
        %if tablero(i+1,j-1) == 0
            vivos=vivos;
        else
            vivos=vivos+1;
        end
    end
    

    % controla si para la proxima generacion vive o muere
    if tablero(i,j)==0 && vivos== 3
        H=1;
    end

    if tablero(i,j)==0 && (vivos<3 || vivos > 3)
        H=0;
    end

    if tablero(i,j)==1 && (vivos<2 || vivos>3) 
        H=0;
    end

    if tablero(i,j)==1 && (vivos== 3 || vivos==2)
        H=1;
    end

end
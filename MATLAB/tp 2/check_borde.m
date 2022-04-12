function H = check_borde(i,j,tablero)
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
        %cambiar
        if tablero(i,j+1) == 0
            vivos=vivos;
        else
            vivos=vivos+1;
        end
        %cambiar
        if tablero(i-1,j+1) == 0
            vivos=vivos;
        else
            vivos=vivos+1;
        end
        %cambiar
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
        %cambiar
        if tablero(i-1,j) == 0
            vivos=vivos;
        else
            vivos=vivos+1;
        end
        %cambiar
        if tablero(i-1,j-1) == 0
            vivos=vivos;
        else
            vivos=vivos+1;
        end
        %cambiar
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
        
    elseif (i<(dim/2))&&(j<(dim/2))
        %3er cuadrante
        %cambiar
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
        %cambiar
        if tablero(i,j-1) == 0
            vivos=vivos;
        else
            vivos=vivos+1;
        end
        %cambiar
        if tablero(i+1,j-1) == 0
            vivos=vivos;
        else
            vivos=vivos+1;
        end
    elseif (i>(dim/2))&&(j<(dim/2))
        %4to cuadrante
        %cambiar
        if tablero(i+1,j) == 0
            vivos=vivos;
        else
            vivos=vivos+1;
        end
        %cambiar
        if tablero(i+1,j+1) == 0
            vivos=vivos;
        else
            vivos=vivos+1;
        end
        %cambiar
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
        %cambiar
        if tablero(i,j-1) == 0
            vivos=vivos;
        else
            vivos=vivos+1;
        end
        %cambiar
        if tablero(i+1,j-1) == 0
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
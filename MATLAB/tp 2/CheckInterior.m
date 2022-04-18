function H = CheckInterior(i,j,tablero)
    vivos=0;
    %control de celdas vecinas
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
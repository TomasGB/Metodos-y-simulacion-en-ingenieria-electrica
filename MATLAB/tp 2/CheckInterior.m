function H = CheckInterior(i,j,tablero)
    vivos=0;
    %control de celdas vecinas
    if tablero(i+1,j) == 1
        vivos=vivos+1;
    else
        vivos=vivos;
    end

    if tablero(i+1,j+1) == 1
        vivos=vivos+1;
    else
        vivos=vivos;
    end
    if tablero(i,j+1) == 1
        vivos=vivos+1;
    else
        vivos=vivos;
    end
    if tablero(i-1,j+1) == 1
        vivos=vivos+1;
    else
        vivos=vivos;
    end
    if tablero(i-1,j) == 1
        vivos=vivos+1;
    else
        vivos=vivos;
    end
    if tablero(i-1,j-1) == 1
        vivos=vivos+1;
    else
        vivos=vivos;
    end
    if tablero(i,j-1) == 1
        vivos=vivos+1;
    else
        vivos=vivos;
    end
    if tablero(i+1,j-1) == 1
       vivos=vivos+1;
    else
        vivos=vivos;
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
function raiz = FalsePosition(funcion,xi,xf,iteraciones,error)
%{
    /*
        autores:Santiago Palma, Facundo Paez
        fecha: 29/04
        finalidad: Encontrar la raiz mediante el metodo de Falsa posicion
        argumentos de entrada:
            + funcion: Funcion a la que se le quiere encontrar sus raices
            + xi: Valor inicial
            + xf: Valor inicial
            + iteraciones: Numero de iteraciones
            + error: Error de corte
        argumentos de salida: 
            + raiz: Raiz de la funcion
        ejemplo de invocacion: FalsePosition(fnuminput,0,20,100,0.001)
    */

%}
      contador=0;
      f= inline(funcion);
      error_raiz=100;
     
if f(xi)*f(xf)<=0

    while  ((contador<iteraciones) && (error_raiz>error))
        
        xr = xf-((f(xf)*(xi-xf))/(f(xi)-f(xf)));
        
        contador=contador+1;
        
        if (f(xi)*f(xr)>0)
            error_raiz_old=error_raiz;
            error_raiz = abs(((xr-xi)/xr)*100);
            xi=xr;
        elseif f(xi)*f(xr)<0
            error_raiz_old=error_raiz;
            error_raiz = abs(((xr-xf)/xr)*100);
            xf=xr;
        else 
            xr=0;
            error_raiz=0;  
            end 
    end
    if error_raiz>error 
        c=['La cantidad de iteraciones son: ',num2str(contador)];  
        disp(c)
        %disp('------------------------------------------------')
        e=['Con un error de: nuevo ', num2str(error_raiz)];
        disp(e)
        %disp('------------------------------------------------')
        r=['La raiz es: ',num2str(xr)];
        disp(r)
    else 
        c=['La cantidad de iteraciones son: ',num2str(contador)];  
        disp(c)
        %disp('------------------------------------------------')
        e=['Con un error de: viejo ', num2str(error_raiz_old)];
        disp(e)
        %disp('------------------------------------------------')
        r=['La raiz es: ',num2str(xr)];
        disp(r)
    end
else
    disp('no tiene raiz en este intervalo');
end 
end

    
    

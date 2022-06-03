function raiz = NewtonRaphson (funcion,x0,error)
%{
    /*
        autores:Santiago Palma, Facundo Paez
        fecha: 29/04
        finalidad: Encontrar la raiz mediante el metodo Newton-Raphson
        argumentos de entrada:
            + funcion: Funcion a la que se le quiere encontrar sus raices
            + x0: Valor inicial
            + error: Error de corte
        argumentos de salida: 
            + raiz: raiz de la funcion
        ejemplo de invocacion: NewtonRaphson(fnuminput,5,0.001)
    */

%}
syms x
f=inline(funcion);
dfun=diff(funcion,x);
df=inline(dfun);
error_raiz=100;
contador=1;
    
while error_raiz>=error
    
    xi=x0-(f(x0)/df(x0));
    
    error_raiz=abs(xi-x0);
    
    x0=xi;
    contador=contador + 1;
    
end

r=['La raiz es: ', num2str(x0)];
disp(r)

c=['en ',num2str(contador), ' iteraciones'];
disp(c)

e=['Con un error de: ', num2str(error_raiz)];
disp(e)
 


end
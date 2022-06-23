function x = raiz_babilonica(error,numero)
x=1;
x_2=10;


while abs(x_2-x) > error
    x_2=x;  
    x=((numero/x)+x)/2;
    
    
end

        
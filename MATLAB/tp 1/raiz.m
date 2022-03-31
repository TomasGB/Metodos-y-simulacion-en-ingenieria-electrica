a=double(input('ingrese un numero '));
error = 0.0001;
b=0;
 
while (b*b)<a && (a-(b*b))> error
    b=b+error;
end
disp(b)




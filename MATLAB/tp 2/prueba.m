clc
clear

syms x
fnuminput=input('Introduzca numerador de FT: ')
fdeninput=input('Introduzca denominador de FT: ')
fnum=inline(fnuminput);%numerador
fden=inline(fdeninput);%denominador
f0x=inline(x*0); %eje x
hold on
ezplot(fnum,[-100;100]);
ezplot(fden,[-100;100]);
ezplot(f0x,[-100;100]);
hold off
axis([-100 100 -500 500])%espacio donde se grafica
title('Funciones')
grid on %grillas on



disp('----------------------')
disp('M�todo Falsa Posici�n')
disp('----------------------')


FalsePosition(fnuminput,0,20,100,0.001)
FalsePosition(fdeninput,-20,20,100,0.001)


disp('----------------------')
disp('M�todo Newton-Raphson')
disp('----------------------')

NewtonRaphson(fnuminput,5,0.001)
NewtonRaphson(fdeninput,-15,0.001)


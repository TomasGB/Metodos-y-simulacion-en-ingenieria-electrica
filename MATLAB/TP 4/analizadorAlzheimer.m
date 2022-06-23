clear
close all
clc

F=[0.0 0.1 0.2 0.5 0.7 1.0 2.0 5.0 7.0 10.0 20.0 50.0];
B=[0.0 10.57 19.03 36.61 -15.22 552.93 68.15 80.65 86.31 89.35 94.35 101.0];
datos=[F;B]';
disp('datos originales')
disp(datos)

N=length(F);

% formula interpolacion
% y=y0+((y1-y0)/(x1-x0))*(x-x0)

B_interpolados=Interpolation(F,B);

datos_interpolados=[F;B_interpolados]';

%calculo de errores
for i=1:N
    error(i)=abs(B(i)-B_interpolados(i));
end

errores_interpolacion=[F;error]';


disp('errores respecto a los interpolados')
disp(errores_interpolacion)

% correciones a los datos

B_corregidos=B;

for i=1:length(F)

    if error(i) > 20 || B(i)<0
        j=i;
        while error(j)>5
            j=j+1;
        end
        correccion=puntual_Interpolation(F,B_corregidos,i-1,j);
        B_corregidos(i)=correccion;
    else
        B_corregidos(i)=B(i);
    end
end

disp('datos corregidos')
datos_corregidos=[F;B_corregidos]';
disp(datos_corregidos)
datos;

disp('datos transformados')
% se aplica log a F para observar mejor el comportamiento lineal
F_transformados=log(F(2:end));
B_transformados=B_corregidos(2:end);
datos_transformados=[F_transformados;B_transformados]';
disp(datos_transformados)


%GRAFICOS

figure('Name','Datos originales vs Datos corregidos','NumberTitle','off');
% datos originales
subplot(2,1,1)
plot(F,B,'linewidth',2)
grid on
title('datos originales')
xlabel ('F(nM)')
ylabel('B(nM)')

% datos interpolados
subplot(2,1,2)
plot(F,B_corregidos,'linewidth',2)
grid on
title('datos corregidos')
xlabel ('F(nM)')
ylabel('B(nM)')

hold on

figure('Name','Datos originales vs Datos transformados','NumberTitle','off');
% datos originales
subplot(2,1,1)
plot(F,B,'linewidth',2)
grid on
title('datos originales')
xlabel ('F(nM)')
ylabel('B(nM)')

% datos corregidos transformados
subplot(2,1,2)
plot(F_transformados,B_transformados,'linewidth',2)
grid on
title('datos corregidos transformados')
xlabel ('F(nM)')
ylabel('B(nM)')


figure('Name','Regresión lineal','NumberTitle','off');
LinearRegression(F,B_corregidos)
grid on
title('Regresión lineal')


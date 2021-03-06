clear
clc

% hacer regresiones para cada planeta sacando el dato de ese planeta 
% y calcular el valor aproximado y compararlo respecto al real

% 1:mercurio  5:jupiter
% 2:venus     6:saturno
% 3:tierra    7:urano
% 4:marte     8:neptuno
 
planetas=[1 2 3 4 5 6 7 8];
distancias=[0.39 0.72 1 1.52 5.20 9.54 19.18 30.06];
periodos=[0.24 0.62 1 1.88 11.86 29.46 84.01 164.8];

datos=[planetas' distancias' periodos'];
disp('Datos')
disp('   Planeta  Distancia   Periodo')
disp(datos)

for i=3:3
    
    [coef, func]=PolynomialRegression(distancias,periodos,i);

    periodos_aprox=polyval(coef,distancias)';
    grado=num2str(i);
    disp(strcat('aproximacion polinomial de grado:',grado))
    disp('  Periodo   Periodo_aprox')
    disp([periodos',periodos_aprox])

    errores=abs(periodos'-periodos_aprox);

    disp('errores')
    disp(errores)

end

% interpolacion por spline cubico

periodos_spline=spline(distancias,periodos,distancias);

figure('Name','Distancia vs Periodo','NumberTitle','off');
plot(distancias,periodos_spline,'-b','linewidth',2);
xlim([-5 35])
ylim([-5 180])
hold on
scatter(distancias,periodos,'k','filled');

grid on
title('Interpolaci?n por spline c?bico')
xlabel ('Distancia (AU)')
ylabel('Periodo orbital (A?os de la tierra)')

errores_spline=abs(periodos-periodos_spline)';
disp('errores spline cubico')
disp(errores_spline)







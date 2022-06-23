clear
clc

res_VanDerMonde_original=dlmread('resultados.txt');
res_VanDerMonde=dlmread('resultados_chopit_roundit/resultados_chopit_7decimales.txt');

distancias=[-63,-33,-3,27,57];
frecuencias=[3,9,30,14,4];

%genera la matriz de Van der Monde
matriz_VanDerMonde=ones(length(distancias),1);
for i=1:length(distancias)-1
    matriz_VanDerMonde=[matriz_VanDerMonde ((distancias.^i)')];
end

disp('matriz VanDerMonde')
disp(matriz_VanDerMonde)

disp('res VanDerMonde (codigo C sin modificar)')
disp(res_VanDerMonde_original)

disp('res VanDerMonde (codigo C modificado)')
disp(res_VanDerMonde)

disp('Frecuencias (originales)')
disp(frecuencias')


disp('Coeficientes a_i')
% calcula los coeficientes despejando la ecuacion matricial
% matriz_VanDerMonde * matriz_coef = matriz_frecuencias
% matriz_coef = matriz_VanDerMonde_inversa * matriz_frecuencias

coef=inv(matriz_VanDerMonde)*frecuencias';
disp(coef)

disp('error entre codigo C (sin modificar) y Matlab')
% el codigo en C devuelve los coeficientes
% error con los calculados de despejar la ecuacion matricial
for i=1:length(res_VanDerMonde)
    error(i)=abs(res_VanDerMonde(i)-coef(i));
end
disp(error')
disp('error promedio')
disp(mean(error))

disp('error entre codigo C modificado y original')
% el codigo en C devuelve los coeficientes
% error con los calculados de despejar la ecuacion matricial
for i=1:length(res_VanDerMonde)
    error_mod(i)=abs(res_VanDerMonde(i)-res_VanDerMonde_original(i));
end
disp(error_mod')
disp('error de los promedio coeficientes con el codigo C modificado')
disp(mean(error_mod))

disp('frecuencias (Calculadas)')
% calcula las frecuencias multiplicando
% matriz_VanDerMonde * matriz_coeficientes 
frec_calculadas=round(matriz_VanDerMonde*coef);
disp(frec_calculadas)

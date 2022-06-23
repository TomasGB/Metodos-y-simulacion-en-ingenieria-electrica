function [ coef, func ] = PolynomialRegression(x,y,n)
%chapra pag 494 (518)
Z=ones(length(x),n+1);
for i=n:-1:1
    Z(:,i)=Z(:,i+1).*(x(:));
end

coef=((Z'*Z)\(Z'*y'));
coef=coef';

poly= poly2sym(coef); 
func=inline(poly);


figure('Name','Distancia vs Periodo','NumberTitle','off');

hold on
p=ezplot(func, [min(x),max(x),min(y),max(y)]);
xlim([-5 35])
ylim([-5 180])
set(p,'LineWidth',2)
xlabel ('Distancia (AU)')
ylabel('Periodo orbital (Años de la tierra)')
titulo=strcat('Regresión polinomial de grado:',num2str(n));
title(titulo)
grid on
scatter(x,y,'k','filled');


end


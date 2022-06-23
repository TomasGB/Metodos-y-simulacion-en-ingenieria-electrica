function LinearRegression( F,B )

%chapra pag 494 (518)

% se guarda a partir del segundo elemento para evitar el log(0)
x = log(F(2:end))';
y = B(2:end)';
Z=[x ones(length(y),1)];

A0=Z'*Z;
A1=Z'*y;
coef=A0\A1; % \ operador de division izquierda de matrices

x1=linspace(min(x),max(x),10000);
y1=coef(1).*x1+coef(2);

hold on
plot(log(F),B,'ok','linewidth',2)
plot(x1,y1,'b','linewidth',2)
grid on



end


polinomio = [1 0 0 0 1];
derivada = polyder(polinomio);
len = 10;

dominio=(-len:len);

pol=polyval(polinomio,dominio(:));
der=polyval(derivada,dominio(:));
dif=polyval(diff(polinomio),dominio(:));

hold on
plot(pol,'-r')
plot(der,':b')
plot(dif,'--k')

legend('polinomio','polyder','diff')
hold off

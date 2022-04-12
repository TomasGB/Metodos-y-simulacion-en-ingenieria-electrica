function d =ej_4(polinomio)
    derivada = polyder(polinomio);
    funcion_diff = diff(polinomio);
    largo = 500;

    dominio=(-largo:largo);

    pol=polyval(polinomio,dominio(:));
    der=polyval(derivada,dominio(:));
    dif=polyval(funcion_diff,dominio(:));

    %{
    derivada por definicion

    lim x->0 (f(x+h)-f(x))/h

    a = f(x+h)
    b = f(x)
    c = h
    %}

    a = polyval(polinomio,dominio(:)+0.0001);
    b = polyval(polinomio,dominio(:));
    c = 0.0001;

    der_def = (a-b)/c;

    hold on
    plot(pol,'-k','linewidth',2)
    plot(der,':b','linewidth',2)
    plot(dif,':r','linewidth',2)
    plot(der_def,':m','linewidth',2)
    
    disp(length(polinomio));
    disp(length(derivada));
    disp(length(funcion_diff));
    disp(length(der_def));

    legend('polinomio','polyder','diff','def')
    hold off

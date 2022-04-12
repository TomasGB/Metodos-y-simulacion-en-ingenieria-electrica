function [derivada_polyder,derivada_diff,derivada_operaciones] =derivadas(polinomio,valores)
%{
        Autores: Palma, Santiago
        Fecha: 30/03/2022
        Argumentos de entrada: * Polinomio: Matriz con los coeficientes del polinomio.

                               * Valores: Número de valores sobre los que se calculara 
                                          los valores del polinomio y lasderivadas.

        Argumentos de Salida: * derivada_polyder: Matriz con los coeficientes de la derivada
                                                  generada por la función polyder().

                              * derivada_diff: Matriz con los coeficientes de la derivada
                                               generada por la función diff().

                              * derivada_operaciones: Matriz con los coeficientes de la derivada
                                                      generada por operaciones aritméticas básicas.

        línea de invocación: [derivada_polyder,derivada_diff,derivada_operaciones]=derivadas(polinomio,500)

        Ejemplo:
                [derivada_polyder,derivada_diff,derivada_operaciones]=derivadas(polinomio,500)
                
                    'longitud arreglo polinomio: 6'

                'longitud arreglo derivada_polyder: 5'

                'longitud arreglo derivada_diff: 5'

                'longitud arreglo derivada_operaciones: 5'


            derivada_polyder =

                25     8     0     6     1


            derivada_diff =

                -3    -2     3    -2     8


            derivada_operaciones =

                25     8     0     6     1
    %}

    derivada_polyder = polyder(polinomio);
    derivada_diff = diff(polinomio);

    grado_polinomio=length(polinomio)-1;
    
    derivada_operaciones=[];
    for it=1:grado_polinomio
        derivada_operaciones=[derivada_operaciones,(polinomio(it)*(grado_polinomio-it+1))];
    end

    dominio=(-(valores/2):(valores/2));

    valores_polinomio=polyval(polinomio,dominio(:));
    valores_derivada_polyder=polyval(derivada_polyder,dominio(:));
    valores_derivada_diff=polyval(derivada_diff,dominio(:));
    valores_derivada_operaciones=polyval(derivada_operaciones,dominio(:));

    disp(strcat({'longitud arreglo polinomio: '},num2str(length(polinomio))));
    disp(strcat({'longitud arreglo derivada_polyder: '},num2str(length(derivada_polyder))));
    disp(strcat({'longitud arreglo derivada_diff: '},num2str(length(derivada_diff))));
    disp(strcat({'longitud arreglo derivada_operaciones: '},num2str(length(derivada_operaciones))));

    disp(sum(abs(valores_polinomio-valores_derivada_polyder)));
    disp(sum(abs(valores_polinomio-valores_derivada_diff)));
    disp(sum(abs(valores_polinomio-valores_derivada_operaciones)));
    
    %graficos
    hold on
    plot(valores_polinomio,'-k','linewidth',2)
    plot(valores_derivada_polyder,':b','linewidth',2)
    plot(valores_derivada_diff,':r','linewidth',2)
    plot(valores_derivada_operaciones,':m','linewidth',2)
    legend('polinomio','polyder','diff','operaciones')
    hold off
   
end

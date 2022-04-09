function b = raiz()
    a=input('ingrese un numero ');
    error = 0.0001;
    b=0;
    
    if imag(a)==0
        while (b*b)<a && (a-(b*b))> error
            b=b+error;
        end
    else
        parte_re=real(a);
        parte_im=imag(a);
        
        % calcula el modulo del numero complejo
        suma_cuadrado =(parte_re*parte_re)+(parte_im*parte_im);
        modulo = 0;
        while (modulo*modulo)<suma_cuadrado && (suma_cuadrado-(modulo*modulo))>error
            modulo=modulo+error;
        end

        % calcula la raiz del modulo
        raiz_mod=0;
        while (raiz_mod*raiz_mod)<modulo && (modulo-(raiz_mod*raiz_mod))> error
            raiz_mod=raiz_mod+error;
        end
        
        angulo=angle(a);
        %{
        if real(a)>=0 && imag(a)>=0
            angulo=angle(a);
        else
            if real(a)<0 && imag(a)>=0
                angulo=pi-angulo;
            else
                if real(a)<0 && imag(a)<0
                    angulo= pi+angulo;
                else 
                    if real(a)>=0 && imag(a)<0
                        angulo = (2*pi)-angulo;
                    end
                end
            end
        end
        %}
    
        ang_1=angulo/2;
        ang_2=(angulo+2*pi)/2;

        
        raiz_1=[raiz_mod,ang_1];
        raiz_2=[raiz_mod,ang_2];
        
        disp(modulo)
        disp(angulo)
        disp(raiz_1)
        disp(raiz_2)
        
        b=[strcat(num2str(raiz_mod),{'e^i '},num2str(ang_1)),strcat(num2str(raiz_mod),{'e^i '},num2str(ang_2))];
    end


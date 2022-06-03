function [ decimal ] = TransformC2toDec( C2 )
%{
    autor: Tomas Gomez
    fecha: 29/05
    finalidad: Realizar la conversión de un string binario en complemento
               a 2 dado por el equipo "CDPP", a sistema decimal.
    argumentos de entrada: 
                           + C2: String binario dado por el equipo "CDPP"
    argumentos de salida: 
                           + decimal: Conversion del string binario a
                                      sistema decimal
%}

% Adapta el string binario del equipo “CDPP”

len_C2=length(C2);
binario=zeros(1,len_C2);
C1=zeros(1,len_C2);

for i=1:length(C2)
    binario(i)=str2num(C2(i));
end
C2=0;
C2=binario;

if C2(1)==1
    signo=1;
else
    signo=0;
end


disp('-------------------- C2 --------------------')
disp(' ')
disp(C2)

% conversion de C2 a C1

if signo==1
    %invierte los bits del C2

    for i=len_C2:-1:1
        if C2(i)==1
            C1(i)=0;
        else
            C1(i)=1;
        end
    end

    %suma uno al C2 invertido

    acarreo=0;
    for i=len_C2:-1:1
        if i==(len_C2)
            if C1(i)<1
                C1(i)=1;
            else
                C1(i)=0;
                acarreo=1;
            end

        else
            if (C1(i)+acarreo)<=1
                C1(i)=C1(i)+acarreo;
                acarreo=0;
            else
                C1(i)=0;
                acarreo=1;
            end
        end
    end


    % convierte a decimal

    decimal=0;
    aux=0;

    if(C1(len_C2)==1)
        decimal=decimal+1;
        aux=aux+2;
    else
        aux=aux+2;
    end

    for j=len_C2-1:-1:1
        if(C1(j)==1)
            decimal=decimal+aux;
            aux=aux*2;
        else
            aux=aux*2;
        end

    end

    if (C2(1)==1)
        decimal=-1*decimal;
    end
    
else
    
    decimal=0;
    aux=0;

    if(C2(len_C2)==1)
        decimal=decimal+1;
        aux=aux+2;
    else
        aux=aux+2;
    end

    for j=len_C2-1:-1:1
        if(C2(j)==1)
            decimal=decimal+aux;
            aux=aux*2;
        else
            aux=aux*2;
        end

    end

    if (signo==1)
        decimal=-1*decimal;
    end
end
    

disp('-------------- Decimal --------------------')
disp(' ')
disp(decimal)

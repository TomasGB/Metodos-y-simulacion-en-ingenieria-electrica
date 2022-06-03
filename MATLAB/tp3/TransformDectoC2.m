function [ C2 ] = TransformDectoC2( num ,nro_bits )
%{
    autor: Tomas Gomez
    fecha: 29/05
    finalidad: Realizar la conversión de un numero en sistema decimal a
               complemento a 2, con una cantidad especificada de bits.
    argumentos de entrada: 
                           + num: Número en sistema decimal
                           + nro_bits: Número de bits deseados
    argumentos de salida: 
                           + C2: String binario con la conversión a
                           complemento a dos.
%}

if num>=0
    signo=0;
else
    signo=1;
end

% convierte el numero a binario

res=0;
aux=0;
exp=0;

while(num~=0)
    aux=mod(num,2);
    res=res+aux*10^exp;
    num=fix(num/2);
    exp=exp+1;
end

len=length(num2str(res));

binario=zeros(1,len+1);

% asigna el bit de signo al primer elemento
binario(1)=signo;

for i=len+1:-1:2
    binario(i)=mod(res,10);
    res=fix(res/10);
end

disp('--------------- binario --------------------')
disp(' ')
disp(binario)

if signo ==0
        C2=binario;
else

    % convierte a complemento a 1

    disp('-------------------- C1 --------------------')
    disp(' ')

    C1=zeros(1,len+1);

    for i=1:len+1
        if binario(i)==0
            C1(i)=1;
        else
            C1(i)=0;
        end
    end

    disp(C1)

    if signo == 0
        C2=num2str(C1);
    else
        % convierte a complemento a 2

        C2=zeros(1,len+1);
        acarreo=0;

        for i=len+1:-1:1
            %suma uno al ultimo bit
            if i==(len+1)
                if C1(i)<1
                    C2(i)=1;
                else
                    C2(i)=0;
                    acarreo=1;
                end

            else
                if (C1(i)+acarreo)<=1
                    C2(i)=C1(i)+acarreo;
                    acarreo=0;
                else
                    C2(i)=0;
                    acarreo=1;
                end
            end
        end
    end
end

% Adapta al numero de bits deseados
if length(C2)>nro_bits
    nro_bits=length(C2);
end

if (length(C2)<nro_bits)
    C2_aux=zeros(1,nro_bits);
    
    i=nro_bits;
    j=length(C2);
    
    while (i > 0) && (j~= 0)
        C2_aux(i)=C2(j);
        i=i-1;
        j=j-1;
    end
    
    % completa los bits restantes con el signo
    while i>0
        C2_aux(i)=signo;
        i=i-1;
    end
    
    C2=C2_aux;

end

disp('-------------------- C2 --------------------')
disp(' ')
disp(C2)
disp('--------------------------------------------')
disp(strcat('La cantidad mínima de bits es: ',num2str(length(C2))))
C2=num2str(C2);










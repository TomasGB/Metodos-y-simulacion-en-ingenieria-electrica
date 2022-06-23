function circuito(R,L,Vo)
%syms t
%funcion=(Vo/R)*(1-(exp((-R/L)*t)));

%funcion2=t+(1/L)*(Vo-R*t)*((t+1)-t);

%ezplot(funcion,[0;0.001]);

t=linspace(0,0.001,500);
I1=Vo/R*(1-exp(-R/L*t));

t2=linspace(0,0.001,500);
I2(1)=0;

t3=linspace(0,0.001,500);
I3(1)=0;

for i=2:500
    I2(i)=I2(i-1)+1/L*(Vo-R*I2(i-1))*(t2(i)-t2(i-1));
    I3(i)=I3(i-1)+1/L*(Vo-R*I3(i-1))*(t2(i)-t2(i-1));
end


hold on
plot(t,I1,'-r','linewidth',2)
plot(t2,I2,'-b','linewidth',2)
hold off


%{
hold on
plot(t,I1,'-c','linewidth',20)
plot(t2,I2,'-w','linewidth',10)
plot(t3,I3,'*y','linewidth',1)
hold off
%}





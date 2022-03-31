
Dim = 10;

%A=[zeros(Dim)];

A=randi([10,100],Dim,Dim);
%disp(A);

x_1=randi([1,Dim],1);
y_1=randi([1,Dim],1);

x_2 = x_1;

while x_2 == x_1 && abs(x_1-x_2)==0
    x_2=randi([1,Dim],1);
end

y_2=randi([1,Dim],1);

while y_2 == y_1 && abs(y_1-y_2)==0
    y_2=randi([1,Dim],1);
end


coord_1=[x_1,y_1];
coord_2=[x_2,y_2];

disp('')
disp('coords')
disp(coord_1)
disp(coord_2)


B=randi([10,100],abs(y_1-y_2)+1,abs(x_1-x_2)+1);

disp('Matriz A')
disp(A)
disp('Matriz B')
disp(B)




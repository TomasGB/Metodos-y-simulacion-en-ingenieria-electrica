function [ B_interpolated ] = Interpolation( F,B )

B_interpolated(1)=B(1);
for i=2:length(F)-1
    B_interpolated(i)=B(i-1)+((B(i+1)-B(i-1))/(F(i+1)-F(i-1)))*(F(i)-F(i-1));
    error(i)=abs(B(i)-B_interpolated(i));
    
    if error(i)>20
        j=i;
        while (abs(B(j)-B_interpolated(j)))>5
            j=j+1;
        end
    B_interpolated(i)=B(i-1)+((B(j)-B(i-1))/(F(j)-F(i-1)))*(F(i)-F(i-1));
        
end
B_interpolated(length(B))=B(length(B));

end


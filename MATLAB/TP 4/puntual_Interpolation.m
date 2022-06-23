function [ B_interpolated ] = puntual_Interpolation( F,B,i,j)

B_interpolated=B(i)+((B(j)-B(i))/(F(j)-F(i)))*(F(i+1)-F(i));

end


function [ B_interpolated ] = cubicInterpolation( F,B )

%xx = min(F):.25:max(F);
yy=spline(F,B,F);

plot(F,yy,'-b','linewidth',2);
hold on
scatter(F,B,'k','filled');
grid on

errores=abs(B-yy);
disp(errores)

disp(yy')
end


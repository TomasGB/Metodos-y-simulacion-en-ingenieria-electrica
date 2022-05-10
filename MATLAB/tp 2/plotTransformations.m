function p = plotTransformations(dimension)
    a=dlmread('fig_original.txt');
    b=dlmread('fig_transformada.txt');
    if dimension == 2
        hold on
        plot(a(1,:),a(2,:),'-b','linewidth',2)
        plot(b(1,:),b(2,:),'-r','linewidth',2)
        xlabel('Eje x')
        ylabel('Eje y')
        hold off
    elseif dimension == 3
        hold on
        plot3(a(1,:),a(2,:),a(3,:),'-b','linewidth',2)
        plot3(b(1,:),b(2,:),b(3,:),'-r','linewidth',2)
        xlabel('Eje x')
        ylabel('Eje y')
        zlabel('Eje z')
        hold off
    end
end
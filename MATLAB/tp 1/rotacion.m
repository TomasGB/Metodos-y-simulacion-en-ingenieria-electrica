x=[ -6 -6 -7 0 7 6 6 -3 -3 0 0 -6];
y=[-7 2 1 8 1 2 -7 -7 -2 -2 -7 -7];

m=[x;y];

a=pi/2;
n=[cos(a),-sin(a);sin(a), cos(a)]*m;
n(1,:)=n(1,:)+15;
n(2,:)=n(2,:)+15;


hold on
plot(m(1,:),m(2,:),'-');
plot(n(1,:),n(2,:),'-');
hold off

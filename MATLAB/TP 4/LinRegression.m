function [ r2,a ] = LinRegression( x,y )
n=length(x);
sx=sum(x);
sy=sum(y);
sx2=sum(x.*y);
sxy=sum(x.*y);
sy2=sum(y.*y);
a(1)=(n*sxy-sx*sy)/(n*sx2-sx^2);
a(2)=sy/n-a(1)*sx/n;

sr2=y-(a(2)+a(1).*x);
sr=sum(sr2.*sr2);
st2=y-mean(y);
st=sum(st2.*st2);
r2=(st-sr)/st;

end


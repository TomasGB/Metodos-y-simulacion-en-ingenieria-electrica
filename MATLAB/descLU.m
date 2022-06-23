function [ L,U,Perm ] = descLU( A )
n=size(A);
L=Perm=eye(n);
U=A;

for k=1:n-1
    [mx,i]=max(abs(U(k:n,k)));
    ipr=i+k-1;
    if ipr ~= k
        U([k,ipr],:)=U
end


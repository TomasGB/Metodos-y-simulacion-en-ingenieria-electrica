function [ sol ] = Gauss_Jordan( A,B)
n=size(A,1);
    Au= [A B];
    nb =n+1;

    for k=1:n-1
        for i=k+1:n
            f=Au(i,k)/Au(k,k);
            Au(i,k:nb)=Au(i,k:nb)-f*Au(k,k:nb);
        end
        
    end
    
    x=zeros(n,1);
    x(n) = Au(n,nb)/Au(n,n);
    for i=n-1:-1:1
        x(i)=(Au(i,nb)-Au(i,i+1:n)*x(i+1:n))/Au(i,i);
    end
    
    
    for k=n:-1:1
        for i=k-1:-1:1
            f=Au(i,k)/Au(k,k);
            Au(i,nb:-1:k)=Au(i,nb:-1:k)-f*Au(k,nb:-1:k);
        end
        
    end
    

    
    
    
    sol=Au;
end


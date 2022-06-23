function sol= GaussJordan(A,B)
    n=size(A);
    Au= [A B];
    nb =n+1;

    for k=1:n-1
        for i=k+1:n
            f=Au(i,k)/Au(k,k);
            Au(i,k:nb)=Au(i,k:nb)-f*Au(k,k:nb);
        end
    end
    sol=Au;
end
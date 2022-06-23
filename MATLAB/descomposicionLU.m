function descomposicionLU(A)
	n=size(A);
	for i=1:n
		for j=1:n
			U(i,j)=0;
			L(i,j)=0;
			if i==j
				L(i,j)=1;
			end
		end
	end
	for i=1:n
		for j=1:n
			U(i,j)=A(i,j);
			for k=1:i-1
				U(i,j)=U(i,j)-L(i,k)*U(k,j);
			end
			U(i,j)=U(i,j)/L(i,i);
		end
		for t=i+1:n
			L(t,i)=A(t,i);
			for k=1:i-1
				L(t,i)=L(t,i)-L(t,k)*U(k,1);
			end
			L(t,i)=L(t,i)/U(i,i);
		end
    end
    L
    U
   
	
end


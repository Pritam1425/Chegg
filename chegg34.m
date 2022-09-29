A = [-2 1 0 0 0;1 -2 1 0 0;0 1 -2 1 0;0 0 1 -2 1;0 0 0 1 -1];
B = [0.03125;0.00625;0.009375;0.0125;0.0078125];
%w = relaxation factor >1 and the closer to 1 the accurate the answer
w = 1.00001;
%Divide the matriz A = diagonal+lower triangle+upper triangle
D = diag(diag(A));
L = tril(A)- D;
U = triu(A)- D;
%Check if the calculation converges over successive  over-relaxation
conv = max(eig((D+w*L)\(D*(1-w)-w*U)));
if abs(conv) >=1
    disp('Not convergent.')
    return
end

%initial guess
u = [0;0;0;0;0];
%error
error = 1;
%tolerant for loop termination purpose
tol = 0.00001;
%prevu stores the prev value of u
prevu = u;

while error>=tol
    prevu = u;
    %Formula for SOR calculation
    u = (D+w*L)\(D*(1-w)-w*U)*u+(D+w*L)\B;%A\B = inv(A)*B
    %the the absolute max error between the new and old values of u
    error = max(abs(u-prevu));
end
disp(u);%display the result u vector
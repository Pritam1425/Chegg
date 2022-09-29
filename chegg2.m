x = xlsread('grades.xlsx');
% Initialise all variable to zero
fa = 0;
pa = 0;
cr = 0;
di = 0;
hd = 0;

% Write your code here to count the number of each grade contained in 'x'

for i=1:length(x)
    if x(i)<50
        fa = fa+1;
    elseif x(i)<60
        pa = pa+1;
    elseif x(i)<70
        cr = cr+1;
    elseif x(i)<80
        di = di+1;
    else
        hd = hd+1;
    end
end

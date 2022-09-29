function dates = dategen(N)

dates = zeros(N,2);%Nx2 matrix to hold date and month of each date
for i=1:N
    month = randi(12);%Generate random month from 1 to 12
    dates(i,2) = month;%Store the month in result
    
    if month==4|month==6|month==9|month==11%if the month is apr,jun,sep,nov, generate random number upto 30
        dates(i,1) = randi(30);
    elseif month==2%For feb it is 28.
        dates(i,1) = randi(28);
    else%Rest of the months have 31 days. So generate date upto 31
        dates(i,1) = randi(31);
    end
end
end
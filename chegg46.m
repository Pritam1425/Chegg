%linearly spcaed point calculation of y
x1 = linspace(0,10,30);%evenly spaced 30 points in linear scale
y1 = 2.*x1.*x1-15.*x1+25;

%logscale calculation of y
x2 = logspace(-1,1,30);%evenly spaced 30 points in log scale
y2 = 2.*x2.*x2-15.*x2+25;

%subplot 1
subplot(1,2,1)
plot(x1,y1,'-o','Color','k','LineWidth',2,'MarkerSize',6,'MarkerEdgeColor','g','MarkerFaceColor','r');
%-o denotes solid line with circular marker
%Color of the line 'k' denotes black
%LineWidth is 2 point wide
%MarkerSize is 6 point wide
%MarkerEdgeColor is green 'g'
%MarkerFaceColor is red 'r'

%labels
xlabel('0<x<10')
ylabel('y value')

%title
title('Linear plot of y = 2x^{2}-15x+25')

%subplot 2
subplot(1,2,2)
semilogx(x2,y2,'-o','Color','k','LineWidth',2,'MarkerSize',6,'MarkerEdgeColor','g','MarkerFaceColor','r');

xlabel('10^{-1}<x<10^{1}')
ylabel('y value')

title('Semilogarithmic plot of y = 2x^{2}-15x+25')
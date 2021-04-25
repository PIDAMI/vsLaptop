h = [0.1, 0.25];
a = 0;
b = 1;

for i = 1:2

n = 1 / h(i);
com = "diff_eq_boundary.exe " + num2str(h(i)) + ' ' + num2str(1) + ' ' + num2str(1);
system(com);
fp = fopen("d.txt","r");
x = fscanf(fp,"%lf ", n + 1);
y = fscanf(fp,"%lf ", n + 1);

hold on 
plot(x,y);
end

xx = (a:h(2):b);
yy = xx.^2;
plot(xx,yy,'--');

xlabel('x');
ylabel('y');
legend('h = 0.2', 'h = 0.1','exact solution');
title("reduction method, y(a) = A, 0.3 y(b) + 0.9 y'(b) = B");


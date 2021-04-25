%ATAPformats;
h = [0.1, 0.25];
a = 0;
b = 1;
boundary_type = 1;
for i = 1:2

n = 1 / h(i);
com = "diff_eq_boundary.exe " + num2str(h(i)) + ' ' + num2str(2) + ' ' + num2str(boundary_type);
system(com);
fp = fopen("d.txt","r");
x = fscanf(fp,"%lf ", n + 1);
y = fscanf(fp,"%lf ", n + 1);

hold on 
plot(x,y);
end


xlabel('x');
ylabel('error');
legend('h = 0.1', 'h = 0.25');
title("reduction method, y(a) = A, 0.3 y(b) + 0.9 y'(b) = B");
hold off;
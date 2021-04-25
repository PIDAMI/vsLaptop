n = 5;

boundary_type = 1;
com = "diff_eq_boundary.exe " + int2str(n) + " " + num2str(3) + " " + num2str(boundary_type);
system(com);
fp = fopen("d.txt","r");
max_error1 = fscanf(fp,"%lf ", n);

boundary_type = 2;
com = "diff_eq_boundary.exe " + int2str(n) + " " + num2str(3) + " " + num2str(boundary_type);
system(com);
fp = fopen("d.txt","r");
max_error2 = fscanf(fp,"%lf ", n);

eps = (1:n);
for i=1:n
    eps(i) = 10^(-i);
end

id = eps.^3;

loglog(eps, max_error1,eps,max_error2,eps,id);
xlabel('h');
ylabel('actual error');
legend('1 type','3 type','h^3');
title('reduction method');

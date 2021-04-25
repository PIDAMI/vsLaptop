n = 12;

boundary_type = 1;
com = "diff_eq_boundary.exe " + int2str(n) + " " + num2str(4) + " " + num2str(boundary_type);
system(com);
fp = fopen("d.txt","r");
init_v = fscanf(fp,"%lf ", n);
mx_er = fscanf(fp,"%lf ", n);

loglog(init_v,mx_er);
xlabel('initial value error');
ylabel('actual error');
title('reduction, 1 type boundary condition');


function H = max_er(n, mody)
i=(0:1:n);
x = 5.5 + 2.5*cos(pi()*(2*i+1)./(2*n+2))-mody*5/12*i.^2./n.^4;
y = tan(0.5*x+0.2)-x.^2;
yy=0.5/cos(0.5 *x + 2)^2-2*x;
for j=


end
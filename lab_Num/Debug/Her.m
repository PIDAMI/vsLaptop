function h = Her(t,n)
k = [0:1:n];
x = 11/2 + 2.5 * cos(pi*(2*k+1)/((n+1)*2));
y = tan(x./2+0.2)-x.^2;
yy = 0.5./(cos(x./2+0.2)).^2 - 2*x;
sum = 0;
for i=1:n+1
tmp = (t - x(i)).*yy(i);
sum_lang = 0;
for k=1:n+1
if (k ~= i)
sum_lang = sum_lang + (t-x(i))./(x(i)-x(k));
end
end
sum_lang = (1 - sum_lang.*2).*y(i);
product = 1;
for k=1:n+1
if (k~=i)
product = product.* ((t-x(k))./(x(i)-x(k))).^2;
end
end
sum = sum + (tmp+sum_lang).*product;

end
h = sum;
end


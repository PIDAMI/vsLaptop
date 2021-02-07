
%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%
%initial graphics
tmp1 = (1:1:500);
tmp2=(1:1:500);
i=3;
j=3;
% p = [plot(tmp1,tmp2),plot(tmp1,tmp2),plot(tmp1,tmp2)];
for n=i:j
com = "lab_Num.exe " + int2str(n);
system(com);
fp = fopen("d.txt","r");
%nodex =fscanf(fp,"%f ",n+1);
%nodey =fscanf(fp,"%f ",n+1);
x=fscanf(fp,"%f ",n);
y=fscanf(fp,"%f ",n);
xmod=fscanf(fp,"%f ",n);
ymod=fscanf(fp,"%f ",n);

hold on
% p(n-i+1)=plot(x,y);
% plot(nodex,nodey,'o')
plot(x,y,'g');
plot(xmod,ymod,'r');
end
title("tan(0.5 x + 0.2)-x^2 Hermitian interpolation Chebyshev grid");
% legend(p,{'3 nodes','4 nodes','5 nodes'});
xlabel("x");
ylabel("error");
%axis([3 8 -0.1 0.8])
hold off





% %init graph no error
% tmp1 = (1:1:500);
% tmp2=(1:1:500);
% i=3;
% j=5;
% % p = [plot(tmp2,tmp1),plot(tmp1,tmp2),plot(tmp1,tmp2),plot(tmp1,tmp2)];
% exact_x = (3:0.01:8);
% exact_y = tan(exact_x./2+0.2)-exact_x.^2;
% for n=i:j
% com = "lab_Num.exe " + int2str(n);
% system(com);
% fp = fopen("d.txt","r");
% nodex =fscanf(fp,"%f ",n+1);
% nodey =fscanf(fp,"%f ",n+1);
% x=fscanf(fp,"%f ",501);
% y=fscanf(fp,"%f ",501);
% hold on
% p(n-i+2)=plot(x,y);
% plot(nodex,nodey,'o')
% end
% p(1)=plot(exact_x,exact_y);
% title("tan(0.5 x + 0.2)-x^2 Hermitian interpolation Chebyshev grid");
% legend(p,{'tan(0.5 x + 0.2) - x^2','3 nodes','4 nodes','5 nodes'});
% xlabel("x");
% ylabel("y");
% %axis([3 8 -0.1 0.8])
% hold off

% i=5;
% j=40;
% %max_error_graph
% err = (i:1:j);
% errMod = (i:1:j);
% numb = (i:1:j);
% for n=i:j
% com = "lab_Num.exe " + int2str(n);
% system(com);
% fp = fopen("d.txt","r");
% %nodex =fscanf(fp,"%f ",n+1);
% %nodey =fscanf(fp,"%f ",n+1);
% yMod=fscanf(fp,"%e ",1);
% y=fscanf(fp,"%e ",1);
% err(n-i+1)=y;
% errMod(n-i+1)=yMod;
% 
% end
% %hold on
% % semilogy(numb,err,'g',numb,errMod,'b');
% semilogy(numb,err);
% title("tan(0.5 x + 0.2)-x^2 Hermitian interpolation Chebyshev grid");
% xlabel("# nodes");
% ylabel("max error");

%hold off




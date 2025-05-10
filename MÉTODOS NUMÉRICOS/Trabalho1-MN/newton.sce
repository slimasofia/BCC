clear

deff('y=f(x)','y=');
deff('ylinha=g(x)','ylinha=-sin(x)');

x0=3

epsilon=0.000001;

x1=x0-f(x0)/g(x0);

erro=abs(f(x1));

while erro > epsilon
    x0=x1;
    x1=x0-f(x0)/g(x0);
    erro=abs(f(x1));
end

disp('A raiz da função é: ', x1)




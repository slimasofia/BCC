deff('y=f(x)','y=4*cos(x)-exp(x)');
a=0.5;
b=1;
epsilon=0.01;
x=(a+b)/2;
erro=(b-a);
while abs(f(x)) > epsilon
    if f(a)*f(x) < 0
        b=x;
    else
        a=x;
    end
    x=(a+b)/2;
    erro=(b-a);
end
disp('A raiz da função é: ', x)



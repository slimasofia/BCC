clear

deff('y=f(x)','y=4*cos(x)-exp(x)');
a=0.5;
b=1;
i = 0;
epsilon=0.01;
x=(a+b)/2;
erro=(b-a);
while erro > epsilon
    if f(a)*f(x) < 0
        b=x;
    else
        a=x;
    end
    x=(a+b)/2;
    erro=(b-a);
    i = i + 1;
end
disp('A raiz da função é: ', x)
disp('O número de interações necessárias foi: ', i)





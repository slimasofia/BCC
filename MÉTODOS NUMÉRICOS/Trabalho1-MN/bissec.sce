deff('y=f(x)','y=(x/2)^2-sin(x)');
a=1.5;
b=2;
epsilon=0.0001;
x=(a+b)/2;
erro=(b-a);

// vetor pra tabela
tabela = [];

while erro > epsilon
    // salvando os dados de cada iteração:
    tabela($+1,:) = [a, b, x, erro];
    
    if f(a)*f(x) < 0
        b=x;
    else
        a=x;
    end
    x=(a+b)/2;
    erro=(b-a);
end
disp('A raiz da função é: ', x)
disp('Tabela [a, b, x, erro]:')
disp(tabela)


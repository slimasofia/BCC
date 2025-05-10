clear

//Método de Newton
//Entrada: f: função, 
//         f': derivada de f
//         x0: aproximação inicial
//         epsilon: precisão
//Saída: aproximação para a raiz da função

deff('y=f(x)','y=x^2-5');
deff('ylinha=g(x)','ylinha=2*x');

x0=3;
epsilon=0.01;
x1=x0-f(x0)/g(x0);
erro=abs(f(x1));

// vetor para as soluções (já começa com x0)
solucoes = x0;

while erro > epsilon
    x0=x1;
    x1=x0-f(x0)/g(x0);
    erro=abs(f(x1));
    
    solucoes = [solucoes, x1]
end
disp('Soluções para cada iteração: ')
disp(solucoes)
disp('A raiz da função é: ', x1)

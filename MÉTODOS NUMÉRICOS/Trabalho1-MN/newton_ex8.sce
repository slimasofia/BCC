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
i = 1; // começando em 1 pois já houve 1 
       // iteração na linha anterior 

erro=abs(f(x1));

while erro > epsilon
    x0=x1;
    x1=x0-f(x0)/g(x0);
    erro=abs(f(x1));
    i = i + 1;
end
disp('O número de iterações necessárias foi: ', i)
disp('A raiz da função é: ', x1)





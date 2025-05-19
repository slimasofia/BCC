clear

//Método-de-Newton-para-sistemas-não-lineares
//Entrada: F: função não linear, 
//         JF: matriz jacobiana de F
//         x: solução inicial
//         epsilon: precisão
//Saída: aproximação para a solução do sistema não linear

function y=F(x)
    y(1) = (x(1))^2 + (x(2))^2 - 9
    y(2) = x(1) + x(2) - 3
endfunction

function y=JF(x)
    y(1,1) = 2*x(1)
    y(1,2) = 2*x(2)
    y(2,1) = 1
    y(2,2) = 1
endfunction

x = [2 1]'; //solução inicial
epsilon = 0.01; //tolerância
max_it = 20; //número max iterações
it = 0; //contador das iterações

while( norm(F(x), 'inf') > epsilon & it < max_it )
    s = JF(x)\(-F(x));
    x = x + s; 
    it = it +1;  
end
disp(x, 'A solucao do sistema não linear é: ')
disp(it, 'Quantidade de iterações: ')

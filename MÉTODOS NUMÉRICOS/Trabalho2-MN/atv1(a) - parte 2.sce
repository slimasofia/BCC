function y = F(x)
    y(1) = 3*(x(1))^2*x(2) - (x(2))^3 - 4;
    y(2) = (x(1))^2 + x(1)*(x(2))^3 - 9;
endfunction

function y = JF(x)
    y(1,1) = 6*(x(1))*x(2);
    y(1,2) = 3*(x(1))^2 - 3*(x(2))^2;
    y(2,1) = 2*(x(1)) + (x(2))^3;
    y(2,2) = 3*(x(1))*(x(2))^2;
endfunction

x = [2.1; 2.5]; // solução inicial
epsilon = 0.001; // tolerância
max_it = 20; // número max. iterações
it = 0; // contador das iterações

while (norm(F(x), 'inf') > epsilon & it < max_it)
    s = JF(x) \ (-F(x));
    x = x + s;
    it = it + 1;
end

disp('A solucao do sistema não linear é: ', x)
disp('Quantidade de iteracoes: ', it)

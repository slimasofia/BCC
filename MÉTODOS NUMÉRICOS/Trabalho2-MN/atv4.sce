function coeficientes = coeficientesNewton (x,y)
nPontos = length(x);            // número de elemetnos do vetor x
T = zeros(nPontos, nPontos)     // T contém a tabela de diferenças divididas
T(:,1) = y;                     // definir primeira coluna da tabela

for j = 2:nPontos               // para as colunas
for i = 1:(nPontos -j + 1)      // para as linhas
    
// calculando a diferença dividida
T(i, j) = ((T(i+1, j-1)) - T(i, j -1)) / ((x(j+i-1)) - x(i))
end
end
coeficientes = T(1,:);          // os coeficientes estão na primeira linha da tabela
endfunction

// função para avaliar o polinômio no ponto A
function y = PdeA(A,x,coeficientes)
y = coeficientes(1);		// o valor inicial de y é o primeiro coeficiente
for i=2:length(coeficientes)	// para cada termo do polinômio a partir do segundo coeficiente:
produto = coeficientes(i);
for j=1:i-1
produto = produto*(A - x(j))
end
y = y + produto
end
endfunction

x = [-2 -1 1 2]';
y = [0 1 -1 0]';

coeficientes = coeficientesNewton(x,y)

A = 0.5
y = PdeA(A,x,coeficientes)

disp('Coeficientes: ', coeficientes)
disp('Aproximação para f(0.5): ',y)



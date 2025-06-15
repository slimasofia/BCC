// definindo f(x) = 3xe^2x
deff('y=f(x)', 'y = 3*x*exp(2*x)')

// limites
a = 8
b = 13

// número de subintervalos
m = 20
n = m/2

// largura de cada subintervalo
h = (b - a)/m

soma_par = 0
soma_impar = 0

for i = 1:((m/2)-1)
	xi = a + (2*i * h)
	soma_par = soma_par + f(xi)
end

for i = 1:(m/2)
	xi = a + ((2*i)-1) * h
	soma_impar = soma_impar + f(xi)
end

// quarta derivada de f(x)
deff('y4=f4(x)', 'y4=48*exp(2*x)*(2 + x)')
// vetor para armazenar os valores f4(xi)
vetor = zeros(1, m + 1)

// calculando todos os pontos na quarta derivada
for i=1:(m+1)
    xi = a + (i - 1) * h
	valor = f4(xi)
	vetor(i) = valor
end

// procurando o vaor máximo
max_val = max(vetor)

// calculando o erro 
E = ((b - a)^5 / (2880 * n^4)) * max_val

// aplicando a Regra 1/3 de Simpson Repetida
I = (h/3) * (f(a) + f(b) + 2 * soma_par + 4 * soma_impar)

disp('A aproximação para a integral é: ', I)
disp('Estimativa para o erro: ', E)

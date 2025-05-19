//Interpolação de Lagrange

x = [1 3 4 5]';
y = [0 6 24 60]';

X = poly(0,"X"); // variável do polinômio

for i = 1:length(x) // calcula os coeficientes de Lagrange
    produto = 1;
    for j = 1:length(x)
        if(j~=i)
            produto = produto*((X-x(j))/(x(i)-x(j)))
        end
    end
    L(i) = produto; //coeficientes de Lagrange
end

pl = 0; // Monta o polinômio de Lagrange
for i = 1:length(x)
    pl = pl + L(i) * y(i);
end

disp('O polinômio de Lagrange é ', pl)

// Avaliação do polinômio de Lagrange em x=a

a = 3.5

disp('O valor do polinômio em a é ', horner(pl, a))



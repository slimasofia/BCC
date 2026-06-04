#include <iostream>
#include <vector>
#include <iomanip>
#include "Busca.hpp"

int main() {
    Busca b;

    std::cout << "\n--- PARTE 2 - TESTES COM VETORES PEQUENOS ---\n" << std::endl;

    // criar um vetor ordenado com 10 elementos e imprimir seu conteúdo
    std::cout << "Vetor ordenado: ";
    std::vector<int> vet = b.criaVetorOrdenado(10);
    b.imprimeVetor(vet);
    std::cout << std::endl;

    // valores escolhidos para os testes
    int elemInicio = 0;   // elemento que está no início do vetor
    int elemMeio = 8;     // elemento que está no meio do vetor
    int elemAusente = 7;  // elemento que não está no vetor (ímpar)

    // TESTE 1: Elemento no início do vetor
    std::cout << "--- TESTE 1: Buscando o elemento " << elemInicio << " (início) ---" << std::endl;
    
    // Busca Linear
    ResultadoBusca r1 = b.buscaLinear(vet, elemInicio);
    std::cout << "Busca Linear             -> Valor procurado: " << elemInicio 
              << " | Índice: " << r1.getIndice() 
              << " | Comparações: " << r1.getComp() << std::endl;

    // Busca Linear Ordenada
    ResultadoBusca r2 = b.buscaLinearOrdenada(vet, elemInicio);
    std::cout << "Busca Linear Ordenada    -> Valor procurado: " << elemInicio 
              << " | Índice: " << r2.getIndice() 
              << " | Comparações: " << r2.getComp() << std::endl;

    // Busca Binária Iterativa
    ResultadoBusca r3 = b.buscaBinaria(vet, elemInicio);
    std::cout << "Busca Binária Iterativa  -> Valor procurado: " << elemInicio 
              << " | Índice: " << r3.getIndice() 
              << " | Comparações: " << r3.getComp() << std::endl;

    // Busca Binária Recursiva
    ResultadoBusca r4 = b.buscaBinariaRecursiva(vet, elemInicio);
    std::cout << "Busca Binária Recursiva  -> Valor procurado: " << elemInicio 
              << " | Índice: " << r4.getIndice() 
              << " | Comparações: " << r4.getComp() << std::endl;
    std::cout << std::endl;


    // TESTE 2: Elemento no meio do vetor
    std::cout << "--- TESTE 2: Buscando o elemento " << elemMeio << " (meio) ---" << std::endl;
    
    // Busca Linear
    ResultadoBusca r5 = b.buscaLinear(vet, elemMeio);
    std::cout << "Busca Linear             -> Valor procurado: " << elemMeio 
              << " | Índice: " << r5.getIndice() 
              << " | Comparações: " << r5.getComp() << std::endl;

    // Busca Linear Ordenada
    ResultadoBusca r6 = b.buscaLinearOrdenada(vet, elemMeio);
    std::cout << "Busca Linear Ordenada    -> Valor procurado: " << elemMeio 
              << " | Índice: " << r6.getIndice() 
              << " | Comparações: " << r6.getComp() << std::endl;

    // Busca Binária Iterativa
    ResultadoBusca r7 = b.buscaBinaria(vet, elemMeio);
    std::cout << "Busca Binária Iterativa  -> Valor procurado: " << elemMeio 
              << " | Índice: " << r7.getIndice() 
              << " | Comparações: " << r7.getComp() << std::endl;

    // Busca Binária Recursiva
    ResultadoBusca r8 = b.buscaBinariaRecursiva(vet, elemMeio);
    std::cout << "Busca Binária Recursiva  -> Valor procurado: " << elemMeio 
              << " | Índice: " << r8.getIndice() 
              << " | Comparações: " << r8.getComp() << std::endl;
    std::cout << std::endl;


    // TESTE 3: Elemento que nao está no vetor
    std::cout << "--- TESTE 3: Buscando o elemento " << elemAusente << " (inexistente) ---" << std::endl;
    
    // Busca Linear
    ResultadoBusca r9 = b.buscaLinear(vet, elemAusente);
    std::cout << "Busca Linear             -> Valor procurado: " << elemAusente 
              << " | Índice: " << r9.getIndice() 
              << " | Comparações: " << r9.getComp() << std::endl;

    // Busca Linear Ordenada
    ResultadoBusca r10 = b.buscaLinearOrdenada(vet, elemAusente);
    std::cout << "Busca Linear Ordenada    -> Valor procurado: " << elemAusente 
              << " | Índice: " << r10.getIndice() 
              << " | Comparações: " << r10.getComp() << std::endl;

    // Busca Binária Iterativa
    ResultadoBusca r11 = b.buscaBinaria(vet, elemAusente);
    std::cout << "Busca Binária Iterativa  -> Valor procurado: " << elemAusente 
              << " | Índice: " << r11.getIndice() 
              << " | Comparações: " << r11.getComp() << std::endl;

    // Busca Binária Recursiva
    ResultadoBusca r12 = b.buscaBinariaRecursiva(vet, elemAusente);
    std::cout << "Busca Binária Recursiva  -> Valor procurado: " << elemAusente 
              << " | Índice: " << r12.getIndice() 
              << " | Comparações: " << r12.getComp() << std::endl;
    std::cout << std::endl;

    
    
    std::cout << "\n--- PARTE 3 - EXPERIMENTO COM TAMANHOS MAIORES ---\n" << std::endl;

    // Vetor com os tamanhos que serão testados
    int tamanhos[] = {10, 100, 1000, 10000, 100000};

    std::cout << "EXPERIMENTO 1: Buscando um elemento no final do vetor\n" << std::endl;
    
    std::cout << std::left 
              << std::setw(10) << "n"
              << std::setw(10) << "elem"
              << std::setw(10) << "linear"
              << std::setw(15) << "linear_ord"
              << std::setw(10) << "binaria"
              << std::setw(15) << "binaria_rec" << "\n";
    std::cout << "----------------------------------------------------------------------\n";

    for (int n : tamanhos) {
        std::vector<int> vet = b.criaVetorOrdenado(n);
        int elemFinal = (n - 1) * 2; // calcula o valor armazenado na última posição

        // pega apenas a quantidade de comparações de cada resultado
        int c_lin = b.buscaLinear(vet, elemFinal).getComp();
        int c_lin_ord = b.buscaLinearOrdenada(vet, elemFinal).getComp();
        int c_bin = b.buscaBinaria(vet, elemFinal).getComp();
        int c_bin_rec = b.buscaBinariaRecursiva(vet, elemFinal).getComp();

        std::cout << std::left 
                  << std::setw(10) << n
                  << std::setw(10) << elemFinal
                  << std::setw(10) << c_lin
                  << std::setw(15) << c_lin_ord
                  << std::setw(10) << c_bin
                  << std::setw(15) << c_bin_rec << "\n";
    }
    std::cout << "\n";


    // Tabela 2: Buscando um elemento inexistente
    std::cout << "EXPERIMENTO 2: Buscando um elemento inexistente no vetor\n" << std::endl;
    
    std::cout << std::left 
              << std::setw(10) << "n"
              << std::setw(10) << "elem"
              << std::setw(10) << "linear"
              << std::setw(15) << "linear_ord"
              << std::setw(10) << "binaria"
              << std::setw(15) << "binaria_rec" << "\n";
    std::cout << "----------------------------------------------------------------------\n";

    for (int n : tamanhos) {
        std::vector<int> vet = b.criaVetorOrdenado(n);
        
        // pega o último número par do vetor e soma um pra criar o próximo ímpar
        int elemInexistente = (n - 1) * 2 + 1; 

        // pega a quantidade de comparações
        int c_lin = b.buscaLinear(vet, elemInexistente).getComp();
        int c_lin_ord = b.buscaLinearOrdenada(vet, elemInexistente).getComp();
        int c_bin = b.buscaBinaria(vet, elemInexistente).getComp();
        int c_bin_rec = b.buscaBinariaRecursiva(vet, elemInexistente).getComp();

        // imprime a linha da tabela alinhada
        std::cout << std::left 
                  << std::setw(10) << n
                  << std::setw(10) << elemInexistente
                  << std::setw(10) << c_lin
                  << std::setw(15) << c_lin_ord
                  << std::setw(10) << c_bin
                  << std::setw(15) << c_bin_rec << "\n";
    }
    std::cout << std::endl;

    return 0;
}
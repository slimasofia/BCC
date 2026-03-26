#include <iostream>
#include "NoLista.h"
#include "Lista.h"

int main() {

    // --- 1. INSERÇÃO (ÍNÍCIO E FIM) ---
    std::cout << "\n--- 1. Inserção (Início e Fim) ---" << std::endl;
    Lista l1;
    l1.insere(30);
    l1.insere(20);
    l1.insere(10); 
    std::cout << "Inseridos 10, 20 e 30 no início: \n" << l1 << std::endl;

    l1.insereFim(40);
    l1.insereFim(50);
    std::cout << "Inseridos 40 e 50 no final: \n" << l1 << std::endl;

    // --- 2. REMOÇÃO (ITERATIVA) ---
    std::cout << "\n--- 2. Remoção Iterativa ---" << std::endl;
    l1.retira(10); // Remove o primeiro
    std::cout << "Após retirar o 10 (primeiro): \n" << l1 << std::endl;
    l1.retira(30); // Remove do meio
    std::cout << "Após retirar o 30 (meio): \n" << l1 << std::endl;

    // --- 3. TESTE DE MÉTODOS RECURSIVOS ---
    std::cout << "\n--- 3. Métodos Recursivos ---" << std::endl;
    std::cout << "Comprimento (Recursivo): " << l1.comprimentoRecursivo() << " elementos." << std::endl;
    std::cout << "Imprimindo a lista de forma recursiva:" << std::endl;
    l1.imprimeRecursivo();

    l1.retiraRecursivo(50); // Remove do fim
    std::cout << "Após retirar o 50 de forma recursiva: \n" << l1 << std::endl;

    // --- 4. TESTE DE COMPARAÇÃO DE LISTAS ---
    std::cout << "\n--- 4. Comparação de Listas ---" << std::endl;
    Lista l2;
    l2.insere(40);
    l2.insere(20);
    
    std::cout << "Lista 1: " << l1 << std::endl;
    std::cout << "Lista 2: " << l2 << std::endl;
    
    // Testa o igual recursivo
    std::cout << "As listas são iguais (Recursivo)? " << (l1.igualRecursivo(l2) ? "Sim" : "Não") << std::endl;

    // Modificando para testar o caso de listas diferentes
    l2.insereFim(32);
    std::cout << "\nAdicionando 32 na Lista 2..." << std::endl;
    std::cout << "Lista 1: " << l1 << std::endl;
    std::cout << "Lista 2: " << l2 << std::endl;
    std::cout << "As listas ainda são iguais? " << (l1.igualRecursivo(l2) ? "Sim" : "Não") << std::endl;

    // --- 5. LIBERAÇÃO DE MEMÓRIA ---
    std::cout << "\n--- 5. Limpeza de Memória ---" << std::endl;
    l1.libera();
    l2.libera(); 
    std::cout << "Listas liberadas da memória. Encerrando programa." << std::endl;
    
    return 0;
}
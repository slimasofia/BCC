#include <iostream>
#include <string>
#include "ListaDupla.h"

int main() {
    std::cout << std::endl;

    ListaDupla minhaPlaylist;

    // ==========================================
    // TESTE 1: Inserção Básica e Verificações
    // ==========================================
    std::cout << "--- TESTE 1: Adicionando músicas no final ---" << std::endl;
    if (minhaPlaylist.vazia()) {
        std::cout << "A playlist está vazia. Adicionando músicas...\n";
    }

    minhaPlaylist.insereFim("So Far Away");
    minhaPlaylist.insereFim("Only You");
    minhaPlaylist.insereFim("Limits");
    minhaPlaylist.insereFim("Aerials");
    minhaPlaylist.insereFim("Chains");
    
    minhaPlaylist.imprime();
    std::cout << "Comprimento atual: " << minhaPlaylist.comprimento() << "\n\n";

    // TESTE DE BUSCA:
    std::cout << "--- Buscando uma música ---" << std::endl;
    NoListaDupla* b = minhaPlaylist.busca("So Far Away");
    if (b != nullptr) {
        std::cout << "Música '" << b->getInfo() << "' encontrada no endereço: " << b << std::endl;
    }

    std::cout << std::endl;

    // ==========================================
    // TESTE 2: Inserções Específicas
    // ==========================================
    std::cout << "--- TESTE 2: Inserções em posições específicas ---" << std::endl;
    std::cout << ">> Inserindo 'Alive' na posição 1..." << std::endl;
    minhaPlaylist.insereNaPosicao("Alive", 1);
    
    std::cout << ">> Inserindo 'Patience' na posição 3..." << std::endl;
    minhaPlaylist.insereNaPosicao("Patience", 3);

    minhaPlaylist.imprime();
    std::cout << "Comprimento atual: " << minhaPlaylist.comprimento() << "\n\n";

    // ==========================================
    // TESTE 3: Validações de Erro
    // ==========================================
    std::cout << "--- TESTE 3: Forçando erros ---" << std::endl;
    std::cout << ">> Tentando inserir na posição 10:" << std::endl;
    minhaPlaylist.insereNaPosicao("Música Fantasma", 10);
    
    std::cout << ">> Tentando mover uma música que não existe:" << std::endl;
    minhaPlaylist.moverMusica("Música Inexistente", 2);
    std::cout << "\n";

    // ==========================================
    // TESTE 4: Remoções
    // ==========================================
    std::cout << "--- TESTE 4: Removendo músicas ---" << std::endl;
    std::cout << ">> Removendo 'Limits' (por nome)" << std::endl;
    minhaPlaylist.retira("Limits");

    std::cout << ">> Removendo a música da posição 2 (por posição)..." << std::endl;
    minhaPlaylist.retiraPorPosicao(2); 

    minhaPlaylist.imprime();
    std::cout << "Comprimento atual: " << minhaPlaylist.comprimento() << "\n\n";

    // ==========================================
    // TESTE 5: Movendo Músicas
    // ==========================================
    std::cout << "--- TESTE 5: Movendo músicas ---" << std::endl;
    std::cout << ">> Movendo 'Only You' para a posição 1..." << std::endl;
    minhaPlaylist.moverMusica("Only You", 1); 

    std::cout << "\nPLAYLIST FINAL" << std::endl;
    minhaPlaylist.imprime();
    std::cout << "Comprimento final: " << minhaPlaylist.comprimento() << "\n";

    std::cout << "\nEncerrando o programa. O destrutor será chamado automaticamente e liberará a memória." << std::endl;
    return 0;
}
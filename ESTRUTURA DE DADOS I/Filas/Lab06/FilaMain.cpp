#include <iostream>
#include <stdexcept>
#include "FilaVetor.hpp"

int main() {

    // DEMONSTRAÇÃO DO FUNCIONAMENTO DA ESTRUTURA FILA
    std::cout << "\n=== Teste das Operações da Fila ===\n" << std::endl;
    
    try {
        // criando a primeira fila
        FilaVetor f1(3);
        f1.enqueue(1);
        f1.enqueue(3);
        f1.enqueue(5);
        std::cout << "Fila 1 (f1): " << f1.toString() << std::endl;

        // criando a segunda fila 
        FilaVetor f2(4);
        f2.enqueue(2);
        f2.enqueue(4);
        f2.enqueue(6);
        f2.enqueue(7);
        std::cout << "Fila 2 (f2): " << f2.toString() << std::endl;

        // testando a concatenação
        FilaVetor f_concat = f1.concatena(f2);
        std::cout << "Fila Concatenada (f1 + f2): " << f_concat.toString() << std::endl;

        // testando o merge (intercalando)
        FilaVetor f_merge = f1.merge(f2);
        std::cout << "Fila Merge (f1 intercalada com f2): " << f_merge.toString() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "[ERRO NA FILA] " << e.what() << std::endl;
    }

    std::cout << "\n=====================================================\n\n";
    std::cout << "=== Sistema de Atendimento por Senhas ===\n" << std::endl;

    try {
        // 1. criar uma fila de atendimento informando sua capacidade máxima
        std::cout << "Capacidade da fila: 5" << std::endl;
        FilaVetor fila(5);

        // 2. inserir novas senhas no final da fila
        std::cout << "Chegam as senhas: 101, 102, 103, 104, 105" << std::endl;
        fila.enqueue(101);
        fila.enqueue(102);
        fila.enqueue(103);
        fila.enqueue(104);
        fila.enqueue(105);

        // demonstrar o que acontece se tentar estourar a capacidade
        std::cout << "\n[Teste] Tentando inserir a senha 106..." << std::endl;
        try {
            fila.enqueue(999); 
        } catch (const std::exception& e) {
            // captura o erro do throw criado no FilaVetor.cpp
            std::cout << e.what() << std::endl; 
        }

        // 3. chamar a próxima senha para atendimento (remove do início)
        std::cout << "\nAtende uma senha: " << fila.dequeue() << std::endl;

        // inserir uma nova senha
        std::cout << "Chega a senha 106" << std::endl;
        fila.enqueue(106);

        // 4. exibir a fila atual de senhas na ordem de atendimento
        std::cout << "Exibe a fila atual: " << fila.toString() << std::endl;

        // 5. reiniciar o atendimento do guichê, esvaziando completamente a fila
        std::cout << "\nReinicia o atendimento..." << std::endl;
        fila.reset();

        // 6. exibe a fila vazia
        std::cout << "Exibe a fila vazia: \n" << fila.toString() << std::endl;

    } catch (const std::exception& e) {
        // captura qualquer outro erro inesperado que possa acontecer na aplicação
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n=== Sistema Encerrado ===" << std::endl;

    return 0;
}
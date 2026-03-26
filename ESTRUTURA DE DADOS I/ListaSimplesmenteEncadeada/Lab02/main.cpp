#include <iostream>
#include "Node.h"
#include "List.h"

int main() {

    // --------------- TESTES -------------- 

    List list;
    // inserir valores na lista
    list.insert(50);
    list.insert(40);
    list.insert(30);
    list.insert(20);
    list.insert(10);

    // exibindo a lista
    std::cout << "Lista: " << list << std::endl;

    // buscando o último elemento
    std::cout << "O último elemento da lista é: " << list.getTail()->getData() << std::endl;

    // removendo alguns elementos
    list.remove(30); // remover um elemento do meio
    list.remove(50); // remover um elemento do fim
    std::cout << "Lista após a remoção dos elementos 30 e 50: " << list << std::endl;

    std::cout << std::endl;

    // buscando um elemento
    int data = 10;
    std::cout << "Buscando o elemento " << data << "..." << std::endl;
    
    if(list.search(data)) {
        std::cout << "O elemento " << data << " foi encontrado!" << std::endl;
    } else {
        std::cout << "O elemento " << data << " não foi encontrado." << std::endl;
    }

    std::cout << std::endl;

    // verifica se a lista está vazia, se não estiver, imprime o comprimento dela
    if(list.isEmpty()) {
        std::cout << "A lista está vazia" << std::endl;
    } else {
        std::cout << "A lista não está vazia, seu comprimento é " << list.length() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Testando o método imprime(): " << std::endl;
    list.print();

    list.clear();

    return 0;
}

#include <iostream>
#include <string>
#include "List.h"

// inicializar uma lista vazia
List::List() {
    this->head = NULL;
}

void List::insert(int data) {
    // o "prox" do novo nó vai apontar para o que era o primeiro nó
    Node* newNode = new Node(data, head);
    // e o novo nó será o primeiro 
    this->head = newNode;
}

// imprime os valores armazenados nos nós
void List::print() {
    // referência pra armazenar o endereço de cada elemento
    Node* temp = head;
    while (temp != NULL) {
        // aponta pra cada um dos elementos da lista
        std::cout << temp->getData() << std::endl;
        temp = temp->getNext();
    } 
}

bool List::isEmpty() {
    if (head == NULL) {
        return true;
    } else {
        return false;   
    }
}       

int List::length() {
    Node* temp = head;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->getNext();
    }

    return count;
}

// recebe a informação referente ao elemento a pesquisar
Node* List::search(int data) {
    Node* temp = head;
    while (temp != NULL) {
        // se o dado do nó atual for igual ao dado que procuramos
        if (temp->getData() == data) {
            // retorna o endereço do nó
            return temp;        
        }
        temp = temp->getNext();
    }
    // retorna null caso o elemento não seja encontrado 
    return NULL;
}

// retorna o endereço do último nó da lista
Node* List::getTail() {
    if (isEmpty()) {
        return NULL;
    }

    Node* temp = head;
    while (temp->getNext() != NULL) {
        temp = temp->getNext();
    }
    return temp;
}

std::ostream& operator<<(std::ostream& os, List& l) {
    os << "[ ";

    Node* current = l.head;

    while (current != NULL) {
        os << current->getData() << " ";
        current = current->getNext();
    }

    os << "]";
    return os;
}

void List::remove(int data) {
    // utiliza dois ponteiros caminhando pela lista
    Node* current = head; 
    Node* previous = NULL;

    while (current != NULL && current->getData() != data) {
        previous = current;
        current = current->getNext();
    }

    // não achou o elemento para remover
    if (current == NULL){
        return;
    }

    // se anterior é NULL então a busca não deu nenhum passo e o elemento a ser removido é o primeiro
    if (previous == NULL) {
        // o novo começo da lista passará a ser o segundo nó
        this->head = current->getNext();
    // o nó a ser removido não é o primeiro
    } else {
        // o "next" do anterior passa a apontar pra o que vem depois do atual
        // assim "pulamos" o nó "atual" e ele é ignorado
        previous->setNext(current->getNext());
    }
    delete current;
}

void List::clear() {
    Node* current = head;
    while (current != NULL) {
        Node* nextNode = current->getNext();
        delete current;
        current = nextNode;
    }
    head = NULL;
}
#include "ListaDupla.h"

ListaDupla::ListaDupla() {
    this->head = nullptr;
}

void ListaDupla::insere(std::string v){
    NoListaDupla* novoNo = new NoListaDupla(v);
    novoNo->setAnt(nullptr);
    novoNo->setProx(head);

    // se a lista não estiver vazia, atualiza o antigo head
    if (head != nullptr) {
        head->setAnt(novoNo);
    }

    head = novoNo;
}

void ListaDupla::imprime() {
    // referência pra armazenar o endereço de cada elemento
    NoListaDupla* aux = head;
    // para exibir a numeração da lista (para a playlist de músicas)
    int contador = 1;

    while (aux != nullptr) {
        // aponta pra cada um dos elementos da lista
        std::cout << contador << ". " << aux->getInfo() << std::endl;
        aux = aux->getProx();
        contador++;
    } 
}

bool ListaDupla::vazia() {
    if (head == nullptr) {
        return true;
    } else {
        return false;   
    }
}      

NoListaDupla* ListaDupla::busca(std::string v){
    NoListaDupla* aux = head;
    while(aux != nullptr) {
        if (aux->getInfo() == v) {
            return aux;
        }
        aux = aux->getProx();
    }
    return nullptr;
}

int ListaDupla::comprimento(){
    NoListaDupla* aux = head;
    int contador = 0;

    while(aux != nullptr){
        contador++;
        aux = aux->getProx();    
    }
    return contador;
}

NoListaDupla* ListaDupla::ultimo(){
   // ponteiro auxiliar para percorrer a lista
    NoListaDupla* aux = head;

    // se a lista for vazia
    if(head == nullptr) {
        return nullptr;
    }
    
    while(aux->getProx() != nullptr) {
        aux = aux->getProx();
    }
    return aux;
}

void ListaDupla::retira(std::string v){
    NoListaDupla* p = head;

    while (p != nullptr && p->getInfo() != v) {
        p = p->getProx();
    }

    // se p é null o nó não foi encontrado
    if(p == nullptr) {
        return;
    } else {
        // se p for o primeiro nó
        if (p == head) {
            head = p->getProx();
        }

        // se tiver um nó antes de p
        if (p->getAnt() != nullptr) {
            // o anterior para de apontar pra p e passa a apontar para o próximo de p
            p->getAnt()->setProx(p->getProx()); 
        }

        // se existir um nó depois de p
        if (p->getProx() != nullptr) {
            p->getProx()->setAnt(p->getAnt());
        }
    }
    delete p;
}

void ListaDupla::libera() {
    NoListaDupla* atual = head;
    while (atual != NULL) {
        NoListaDupla* proxNo = atual->getProx();
        delete atual;
        atual = proxNo;
    }
    head = NULL;
}

void ListaDupla::insereFim(std::string v){
    if(vazia()) {
        insere(v);
    } else {
        NoListaDupla* novoNo = new NoListaDupla(v);
        NoListaDupla* f = ultimo(); 

        // o antigo último aponta para o novo nó
        f->setProx(novoNo);
        // o anterior do novo nó aponta para o antigo último
        novoNo->setAnt(f);
        // como é novo fim, o próximo é nulo
        novoNo->setProx(nullptr);
    }
}

void ListaDupla::insereNaPosicao(std::string v, int pos) {
    if (pos < 1 || pos > comprimento() + 1) {
        std::cout << "A posição que você está tentando inserir é inválida!" << std::endl;
        return;
    } else if(pos == comprimento() + 1) {
        insereFim(v);
    } else if(pos == 1) {
        insere(v);
    } else {
        NoListaDupla* aux = head;
        int contador = 1;
        // caminha até o nó que atualmente ocupa a posição desejada
        while(pos != contador) {
            aux = aux->getProx();
            contador++;
        }
        NoListaDupla* novoNo = new NoListaDupla(v);
        
        novoNo->setProx(aux);          
        novoNo->setAnt(aux->getAnt());  

        aux->getAnt()->setProx(novoNo); // vizinho da esquerda aponta para o novo nó
        aux->setAnt(novoNo);            // vizinho da direita aponta de volta para o novo
    }
}

void ListaDupla::retiraPorPosicao(int pos) {
    if (pos < 1 || pos > comprimento()) {
        std::cout << "A posição que você está tentando remover é inválida!" << std::endl;
        return;
    }
    NoListaDupla* aux = head;
    int contador = 1;
    // caminha até a posição do nó que será removido
    while(pos != contador) {
        aux = aux->getProx();
        contador++;
    }

    if(aux == nullptr) {
        return;

    } else {
        if (aux == head) {
            head = aux->getProx();
        }

        if (aux->getAnt() != nullptr) {
            aux->getAnt()->setProx(aux->getProx()); 
        }

        if (aux->getProx() != nullptr) {
            aux->getProx()->setAnt(aux->getAnt());
        }
    }
    delete aux;
}

void ListaDupla::moverMusica(std::string titulo, int posNova) {

    // verifica se a posição que está tentando inserir existe
    if (posNova < 1 || posNova > comprimento()) {
        std::cout << "A posição para a qual você está tentando mover é inválida!" << std::endl;
        return;
    }

    // verifica se a música existe antes de tentar mover
    if (busca(titulo) != nullptr) {
        retira(titulo);
        insereNaPosicao(titulo, posNova);        
    } else {
        std::cout << "Você está tentando mover uma música que não existe!" << std::endl;
    }
}

ListaDupla::~ListaDupla() {
    libera(); 
}
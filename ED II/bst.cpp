#include <iostream>
#include <sstream>
using namespace std;

struct No{
    int valor;
    No* esq;
    No* dir;
    No(int valor) : valor(valor), esq(NULL), dir(NULL) {}
};

No* insere(No* raiz, int valor){
    if (raiz == nullptr){
        return new No(valor);
    }
    if (valor < raiz->valor){
        raiz->esq = insere(raiz->esq, valor);
    }
    
    else if(valor > raiz->valor){
        raiz->dir = insere(raiz->dir, valor);
    }
    return raiz;
}


void pre(No* raiz){
    if (raiz != NULL){
        cout << raiz->valor << " ";
        pre(raiz->esq);
        pre(raiz->dir);
    }
}

void in(No* raiz){
    if (raiz != NULL){
        in(raiz->esq);
        cout << raiz->valor << " ";
        in(raiz->dir);
    }
}

void post(No* raiz){
    if (raiz != NULL){
        post(raiz->esq);
        post(raiz->dir);
        cout << raiz->valor << " ";

    }
}

int main(){

    int casosTeste;
    cin >> casosTeste;

    for (int i = 0; i < casosTeste; i++){
        No* raiz = NULL;
        int n;
        cin >> n;

        cin.ignore();  // Limpa o '\n' que ainda está no buffer

        string linha;
        getline(cin, linha);  
        
        stringstream ss(linha);
        int numero;

        while (ss >> numero) {
            raiz = insere(raiz, numero);
        }
        
        cout << "Case " << i + 1 << ":" << endl;

        cout << "Pre.: "; 
        pre(raiz);
        cout << endl; 

        cout << "In..: ";
        in(raiz);
        cout << endl; // chamar função para percurso infixo

        cout << "Post: ";
        post(raiz);
        cout << endl;
        cout << endl;
    }

    return 0;
}

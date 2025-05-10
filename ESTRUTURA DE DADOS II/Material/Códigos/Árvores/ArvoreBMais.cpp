#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class NoBPlus {
public:
    vector<int> chaves;
    vector<NoBPlus*> filhos;
    NoBPlus* proximo;
    bool folha;

    NoBPlus(bool folha) {
        this->folha = folha;
        this->proximo = nullptr;
    }
};

class ArvoreBPlus {
private:
    NoBPlus* raiz;
    int t;

public:
    ArvoreBPlus(int t) {
        this->t = t;
        this->raiz = nullptr;
    }

    void percorrer() {
        if (raiz != nullptr)
            percorrer(raiz);
    }

    NoBPlus* buscar(int k) {
        if (raiz == nullptr)
            return nullptr;
        return buscar(raiz, k);
    }

    void inserir(int k) {
        if (raiz == nullptr) {
            raiz = new NoBPlus(true);
            raiz->chaves.push_back(k);
        }
        else {
            if (raiz->chaves.size() == 2 * t - 1) {
                NoBPlus* s = new NoBPlus(false);
                s->filhos.push_back(raiz);
                dividirFilho(s, 0, raiz);
                raiz = s;
            }
            inserirNaoCheio(raiz, k);
        }
    }

private:
    void percorrer(NoBPlus* no) {
        int i;
        for (i = 0; i < no->chaves.size(); i++) {
            if (!no->folha)
                percorrer(no->filhos[i]);
            cout << no->chaves[i] << " ";
        }
        if (!no->folha)
            percorrer(no->filhos[i]);
    }

    NoBPlus* buscar(NoBPlus* no, int k) {
        int i = 0;
        while (i < no->chaves.size() && k > no->chaves[i])
            i++;

        if (no->folha && i < no->chaves.size() && no->chaves[i] == k)
            return no;

        if (no->folha)
            return nullptr;

        return buscar(no->filhos[i], k);
    }

    void inserirNaoCheio(NoBPlus* no, int k) {
        int i = no->chaves.size() - 1;

        if (no->folha) {
            no->chaves.push_back(0);
            while (i >= 0 && no->chaves[i] > k) {
                no->chaves[i + 1] = no->chaves[i];
                i--;
            }
            no->chaves[i + 1] = k;
        }
        else {
            while (i >= 0 && no->chaves[i] > k)
                i--;

            i++;
            if (no->filhos[i]->chaves.size() == 2 * t - 1) {
                dividirFilho(no, i, no->filhos[i]);

                if (no->chaves[i] < k)
                    i++;
            }
            inserirNaoCheio(no->filhos[i], k);
        }
    }

    void dividirFilho(NoBPlus* pai, int i, NoBPlus* y) {
        NoBPlus* z = new NoBPlus(y->folha);
        z->chaves.resize(t - 1);

        for (int j = 0; j < t - 1; j++)
            z->chaves[j] = y->chaves[j + t];

        if (!y->folha) {
            z->filhos.resize(t);
            for (int j = 0; j < t; j++)
                z->filhos[j] = y->filhos[j + t];
        }

        y->chaves.resize(t - 1);

        pai->filhos.insert(pai->filhos.begin() + i + 1, z);
        pai->chaves.insert(pai->chaves.begin() + i, y->chaves[t - 1]);

        if (y->folha) {
            z->proximo = y->proximo;
            y->proximo = z;
        }
    }
};

int main() {
    ArvoreBPlus arvore(3);

    arvore.inserir(10);
    arvore.inserir(20);
    arvore.inserir(5);
    arvore.inserir(6);
    arvore.inserir(12);
    arvore.inserir(30);
    arvore.inserir(7);
    arvore.inserir(17);

    cout << "Percorrendo a árvore B+:" << endl;
    arvore.percorrer();

    int k = 6;
    cout << endl << "Elemento " << k;
    if (arvore.buscar(k) == nullptr)
        cout << " não";
    cout << " encontrado." << endl;

    return 0;
}
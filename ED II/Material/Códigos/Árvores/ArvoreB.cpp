#include <iostream>

using namespace std;

class NoArvoreB {
    int *chaves, t, n;
    bool folha;
    NoArvoreB **filhos;

public:
    NoArvoreB(int t, bool folha);

    void inserirNaoCheio(int k);
    void dividirFilho(int i, NoArvoreB *y);
    void percorrer();
    void remover(int k);

    NoArvoreB *buscar(int k);

    friend class ArvoreB;
};

class ArvoreB {
    NoArvoreB *raiz;
    int t;

public:
    ArvoreB(int t) {
        raiz = NULL;
        this->t = t;
    }

    void percorrer() {
        if (raiz != NULL)
            raiz->percorrer();
    }

    NoArvoreB *buscar(int k) {
        return (raiz == NULL) ? NULL : raiz->buscar(k);
    }

    void inserir(int k);
    void remover(int k);
};

NoArvoreB::NoArvoreB(int t1, bool folha1) {
    t = t1;
    folha = folha1;

    chaves = new int[2 * t - 1];
    filhos = new NoArvoreB *[2 * t];

    n = 0;
}

void NoArvoreB::percorrer() {
    int i;
    for (i = 0; i < n; i++) {
        if (!folha)
            filhos[i]->percorrer();
        cout << " " << chaves[i];
    }

    if (!folha)
        filhos[i]->percorrer();
}

NoArvoreB *NoArvoreB::buscar(int k) {
    int i = 0;
    while (i < n && k > chaves[i])
        i++;

    if (chaves[i] == k)
        return this;

    if (folha)
        return NULL;

    return filhos[i]->buscar(k);
}

void ArvoreB::inserir(int k) {
    if (raiz == NULL) {
        raiz = new NoArvoreB(t, true);
        raiz->chaves[0] = k;
        raiz->n = 1;
    } else {
        if (raiz->n == 2 * t - 1) {
            NoArvoreB *s = new NoArvoreB(t, false);

            s->filhos[0] = raiz;

            s->dividirFilho(0, raiz);

            int i = 0;
            if (s->chaves[0] < k)
                i++;
            s->filhos[i]->inserirNaoCheio(k);

            raiz = s;
        }
        else
            raiz->inserirNaoCheio(k);
    }
}

void NoArvoreB::inserirNaoCheio(int k) {
    int i = n - 1;

    if (folha) {
        while (i >= 0 && chaves[i] > k) {
            chaves[i + 1] = chaves[i];
            i--;
        }

        chaves[i + 1] = k;
        n = n + 1;
    }
    else {
        while (i >= 0 && chaves[i] > k)
            i--;

        if (filhos[i + 1]->n == 2 * t - 1) {
            dividirFilho(i + 1, filhos[i + 1]);

            if (chaves[i + 1] < k)
                i++;
        }
        filhos[i + 1]->inserirNaoCheio(k);
    }
}

void NoArvoreB::dividirFilho(int i, NoArvoreB *y) {
    NoArvoreB *z = new NoArvoreB(y->t, y->folha);
    z->n = t - 1;

    for (int j = 0; j < t - 1; j++)
        z->chaves[j] = y->chaves[j + t];

    if (!y->folha)
        for (int j = 0; j < t; j++)
            z->filhos[j] = y->filhos[j + t];

    y->n = t - 1;

    for (int j = n; j >= i + 1; j--)
        filhos[j + 1] = filhos[j];

    filhos[i + 1] = z;

    for (int j = n - 1; j >= i; j--)
        chaves[j + 1] = chaves[j];

    chaves[i] = y->chaves[t - 1];

    n = n + 1;
}

void ArvoreB::remover(int k) {
    if (!raiz) {
        cout << "A árvore está vazia!\n";
        return;
    }

    raiz->remover(k);

    if (raiz->n == 0) {
        NoArvoreB *tmp = raiz;
        if (raiz->folha)
            raiz = NULL;
        else
            raiz = raiz->filhos[0];

        delete tmp;
    }
}

void NoArvoreB::remover(int k) {
    int idx = 0;
    while (idx < n && chaves[idx] < k)
        ++idx;

    if (idx < n && chaves[idx] == k) {
        if (folha)
            for (int i = idx; i < n - 1; ++i)
                chaves[i] = chaves[i + 1];
        else {
            // Casos com filhos
        }
        n--;
    } else {
        if (folha) {
            cout << "A chave " << k << " não existe!\n";
            return;
        }

        bool flag = ((idx == n) ? true : false);

        // Implementar balanceamento

        if (flag && idx > n)
            filhos[idx - 1]->remover(k);
        else
            filhos[idx]->remover(k);
    }
}

int main() {
    ArvoreB arvore(3);

    arvore.inserir(10);
    arvore.inserir(20);
    arvore.inserir(5);
    arvore.inserir(6);
    arvore.inserir(12);
    arvore.inserir(30);
    arvore.inserir(7);
    arvore.inserir(17);

    cout << "Percorrendo a árvore B:" << endl;
    arvore.percorrer();

    int k = 6;
    cout << endl << "Elemento " << k;
    if (arvore.buscar(k) == NULL)
        cout << " não";
    cout << " encontrado." << endl;

    arvore.remover(6);
    cout << "Percorrendo a árvore B após remover 6:" << endl;
    arvore.percorrer();

    return 0;
}
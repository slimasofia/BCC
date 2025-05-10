class NoArvoreB:
    def __init__(self, t, folha):
        self.t = t
        self.folha = folha
        self.chaves = [None] * (2 * t - 1)
        self.filhos = [None] * (2 * t)
        self.n = 0

    def percorrer(self):
        for i in range(self.n):
            if not self.folha:
                self.filhos[i].percorrer()
            print(f" {self.chaves[i]}", end='')

        if not self.folha:
            self.filhos[self.n].percorrer()

    def buscar(self, k):
        i = 0
        while i < self.n and k > self.chaves[i]:
            i += 1

        if i < self.n and self.chaves[i] == k:
            return self

        if self.folha:
            return None

        return self.filhos[i].buscar(k)

    def inserirCaso1(self, k):
        i = self.n - 1

        if self.folha:
            while i >= 0 and self.chaves[i] > k:
                self.chaves[i + 1] = self.chaves[i]
                i -= 1
            self.chaves[i + 1] = k
            self.n += 1
        else:
            while i >= 0 and self.chaves[i] > k:
                i -= 1

            if self.filhos[i + 1].n == 2 * self.t - 1:
                self.dividirFilho(i + 1, self.filhos[i + 1])

                if self.chaves[i + 1] < k:
                    i += 1
            self.filhos[i + 1].inserirCaso1(k)

    def dividirFilho(self, i, y):
        z = NoArvoreB(y.t, y.folha)
        z.n = self.t - 1

        for j in range(self.t - 1):
            z.chaves[j] = y.chaves[j + self.t]

        if not y.folha:
            for j in range(self.t):
                z.filhos[j] = y.filhos[j + self.t]

        y.n = self.t - 1

        for j in range(self.n, i, -1):
            self.filhos[j + 1] = self.filhos[j]

        self.filhos[i + 1] = z

        for j in range(self.n - 1, i - 1, -1):
            self.chaves[j + 1] = self.chaves[j]

        self.chaves[i] = y.chaves[self.t - 1]
        self.n += 1

    def remover(self, k):
        indice = self.encontrarChave(k)

        if indice < self.n and self.chaves[indice] == k:
            if self.folha:
                self.removerFolha(indice)
            else:
                self.removerNaoFolha(indice)
        else:
            if self.folha:
                print(f"Chave {k} não encontrada.")
                return

            flag = indice == self.n

            if self.filhos[indice].n < self.t:
                self.preencher(indice)

            if flag and indice > self.n:
                self.filhos[indice - 1].remover(k)
            else:
                self.filhos[indice].remover(k)

    def removerFolha(self, indice):
        for i in range(indice + 1, self.n):
            self.chaves[i - 1] = self.chaves[i]
        self.n -= 1

    def removerNaoFolha(self, indice):
        k = self.chaves[indice]

        if self.filhos[indice].n >= self.t:
            pred = self.getPredecessor(indice)
            self.chaves[indice] = pred
            self.filhos[indice].remover(pred)
        elif self.filhos[indice + 1].n >= self.t:
            succ = self.getSucessor(indice)
            self.chaves[indice] = succ
            self.filhos[indice + 1].remover(succ)
        else:
            self.unir(indice)
            self.filhos[indice].remover(k)

    def getPredecessor(self, indice):
        cur = self.filhos[indice]
        while not cur.folha:
            cur = cur.filhos[cur.n]
        return cur.chaves[cur.n - 1]

    def getSucessor(self, indice):
        cur = self.filhos[indice + 1]
        while not cur.folha:
            cur = cur.filhos[0]
        return cur.chaves[0]

    def preencher(self, indice):
        if indice != 0 and self.filhos[indice - 1].n >= self.t:
            self.pegaEmprestadoAnterior(indice)
        elif indice != self.n and self.filhos[indice + 1].n >= self.t:
            self.pegaEmprestadoProximo(indice)
        else:
            if indice != self.n:
                self.unir(indice)
            else:
                self.unir(indice - 1)

    def pegaEmprestadoAnterior(self, indice):
        filho = self.filhos[indice]
        irmao = self.filhos[indice - 1]

        for i in range(filho.n - 1, -1, -1):
            filho.chaves[i + 1] = filho.chaves[i]

        if not filho.folha:
            for i in range(filho.n, -1, -1):
                filho.filhos[i + 1] = filho.filhos[i]

        filho.chaves[0] = self.chaves[indice - 1]

        if not self.filhos[indice].folha:
            filho.filhos[0] = irmao.filhos[irmao.n]

        self.chaves[indice - 1] = irmao.chaves[irmao.n - 1]
        filho.n += 1
        irmao.n -= 1

    def pegaEmprestadoProximo(self, indice):
        filho = self.filhos[indice]
        irmao = self.filhos[indice + 1]

        filho.chaves[filho.n] = self.chaves[indice]

        if not filho.folha:
            filho.filhos[filho.n + 1] = irmao.filhos[0]

        self.chaves[indice] = irmao.chaves[0]

        for i in range(1, irmao.n):
            irmao.chaves[i - 1] = irmao.chaves[i]

        if not irmao.folha:
            for i in range(1, irmao.n + 1):
                irmao.filhos[i - 1] = irmao.filhos[i]

        filho.n += 1
        irmao.n -= 1

    def unir(self, indice):
        filho = self.filhos[indice]
        irmao = self.filhos[indice + 1]

        filho.chaves[self.t - 1] = self.chaves[indice]

        for i in range(irmao.n):
            filho.chaves[i + self.t] = irmao.chaves[i]

        if not filho.folha:
            for i in range(irmao.n + 1):
                filho.filhos[i + self.t] = irmao.filhos[i]

        for i in range(indice + 1, self.n):
            self.chaves[i - 1] = self.chaves[i]

        for i in range(indice + 2, self.n + 1):
            self.filhos[i - 1] = self.filhos[i]

        filho.n += irmao.n + 1
        self.n -= 1

    def encontrarChave(self, k):
        indice = 0
        while indice < self.n and self.chaves[indice] < k:
            indice += 1
        return indice

class ArvoreB:
    def __init__(self, t):
        self.raiz = None
        self.t = t

    def percorrer(self):
        if self.raiz is not None:
            self.raiz.percorrer()

    def buscar(self, k):
        return None if self.raiz is None else self.raiz.buscar(k)

    def inserir(self, k):
        if self.raiz is None:
            self.raiz = NoArvoreB(self.t, True)
            self.raiz.chaves[0] = k
            self.raiz.n = 1
        else:
            if self.raiz.n == 2 * self.t - 1:
                s = NoArvoreB(self.t, False)
                s.filhos[0] = self.raiz
                s.dividirFilho(0, self.raiz)

                i = 0
                if s.chaves[0] < k:
                    i += 1
                s.filhos[i].inserirCaso1(k)

                self.raiz = s
            else:
                self.raiz.inserirCaso1(k)

    def remover(self, k):
        if not self.raiz:
            print("A árvore está vazia!")
            return

        self.raiz.remover(k)

        if self.raiz.n == 0:
            temp = self.raiz
            if self.raiz.folha:
                self.raiz = None
            else:
                self.raiz = self.raiz.filhos[0]
            temp = None

arvore = ArvoreB(3)
arvore.inserir(10)
arvore.inserir(20)
arvore.inserir(5)
arvore.inserir(6)
arvore.inserir(12)
arvore.inserir(30)
arvore.inserir(7)
arvore.inserir(17)

print("Percorrendo a árvore B:")
arvore.percorrer()

k = 6
print(f"\nElemento {k}", end='')
if arvore.buscar(k) is None:
    print(" não", end='')
print(" encontrado.")

arvore.remover(6)
print("Percorrendo a árvore B após remover o 6:")
arvore.percorrer()
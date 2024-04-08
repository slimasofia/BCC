#include <iostream>
#include <vector>

// Enumeração para representar os diferentes estados de uma pessoa
enum class Estado { Suscetivel, Infectado, Recuperado };

class Pessoa {
private:
    Estado estado;

public:
    Pessoa() : estado(Estado::Suscetivel) {}

    Estado getEstado() const {
        return estado;
    }

    void setEstado(Estado novoEstado) {
        estado = novoEstado;
    }
};

class Populacao {
private:
    std::vector<Pessoa> pessoas;

public:
    void adicionarPessoa(const Pessoa& pessoa) {
        pessoas.push_back(pessoa);
    }

    void atualizarEstado() {
        // Implemente a lógica para atualizar o estado de todas as pessoas na população
    }
};

class Simulacao {
private:
    Populacao populacao;
    int tempoSimulado;

public:
    Simulacao() : tempoSimulado(0) {}

    void iniciar() {
        // Implemente a inicialização da simulação
    }

    void avancarTempo() {
        // Implemente o avanço do tempo na simulação
    }
};

int main() {
    Simulacao simulacao;
    simulacao.iniciar();
    
    // Loop principal da simulação
    for (int i = 0; i < 10; ++i) {
        simulacao.avancarTempo();
    }
    
    return 0;
}

#include "Aluno.hpp"

Aluno::Aluno(int matricula, std::string nome, std::string email, double mediaGeral) {
    this->matricula = matricula;
    this->nome = nome;
    this->email = email;
    this->mediaGeral = mediaGeral;
    this->prox = nullptr;
}

// getters, setters e toString
int Aluno::getMatricula() {
    return matricula;
}

std::string Aluno::getNome() {
    return nome;
}   

std::string Aluno::getEmail() {
    return email;
}

double Aluno::getMediaGeral() {
    return mediaGeral;
}   

Aluno* Aluno::getProx() {
    return prox;
}

void Aluno::setMatricula(int matricula) {
    this->matricula = matricula;
}

void Aluno::setNome(std::string nome) {
    this->nome = nome;
}

void Aluno::setEmail(std::string email) {
    this->email = email;
}

void Aluno::setMediaGeral(double mediaGeral) {
    this->mediaGeral = mediaGeral;
}

void Aluno::setProx(Aluno* prox) {
    this->prox = prox;
}

std::string Aluno::toString() {
    return "Matricula: " + std::to_string(matricula) + "\nNome: " + nome + "\nEmail: " + email + "\nMedia Geral: " + std::to_string(mediaGeral) + "\n";
}

Aluno::~Aluno() {}

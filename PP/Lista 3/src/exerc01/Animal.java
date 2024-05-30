/*
Em linguagem de programação Java, uma interface é um tipo de referência, similar a
uma classe, que pode conter apenas constantes, assinaturas de métodos, métodos padrão,
métodos estáticos e tipos aninhados. Corpos de métodos existem apenas para métodos padrão
e métodos estáticos. Interfaces não podem ser instanciadas – elas só podem ser implementadas
por classes ou estendidas por outras interfaces.
Referência: (https://docs.oracle.com/javase/tutorial/java/IandI/createinterface.html)

O exemplo abaixo cria uma interface Animal com os métodos andar, comer e correr.
A classe Gato implementa a interface Animal, ou seja, a classe estabeleceu um "contrato"
com a interface, e agora deve definir todos os métodos declarados em Animal.
*/

package exerc01;

public interface Animal {
    void andar();
    void comer();
    void correr();
}


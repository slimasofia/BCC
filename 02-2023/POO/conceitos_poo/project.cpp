#include <iostream>
using namespace std;
#include <string>

class Livro{
    public:
    string title;
    string autor;
    int pages;
    int anoPub;

    Livro(string tit, string aut, int pag, int ano): title(tit), autor(aut), pages(pag), anoPub(ano){ }
    ~Livro(){}
};

class Biblioteca{
    public:
    Livro *livroPtr; // um ponteiro que armazena objetos da classe livro
    Biblioteca() {
        livroPtr = new Livro("", "", 0, 0); 
    }
    ~Biblioteca(){ 
    delete livroPtr;
    }
    //int adicionar(); 
    //int remover();
};
/*
int Biblioteca::adicionar(){

}

int Biblioteca::remover(){

}
*/

int main(){
    Biblioteca obj;
    Livro livro1("livro um", "sofia", 123, 2023);
    cout << livro1.autor;

}
// Classes para representar o conceito de herança

#include <iostream> 
using namespace std; 

// A classe person define 2 funções que mostram id e nome de uma pessoa na tela;
class Person { 
	int id; 
	char name[100]; 

public: 
	void set_p() 
	{ 
		cout << "Enter the Id:"; 
		cin >> id; 
		cout << "Enter the Name:"; 
		cin >> name; 
	} 

	void display_p() 
	{ 
		cout << endl <<"Id: "<< id << "\nName: " << name <<endl; 
	} 
}; 

class Student : private Person { // \a classe Student herda como privado os membros public e protected da classe Person 
	char course[50]; 
	int fee; 

public: 
	void set_s() 
	{ 
		set_p(); // por causa da herança posso chamar a função set_p() da classe Person aqui
		cout << "Enter the Course Name:"; 
		cin >> course; 
		cout << "Enter the Course Fee:"; 
		cin >> fee; 
	} 

	void display_s() 
	{ 
		display_p(); 
		cout <<"Course: "<< course << "\nFee: " << fee << endl; 
	} 
}; 

int main() 
{ 
	Student s; 
	s.set_s(); 
	s.display_s(); 
	return 0; 
}

// é o processo de derivar uma ou mais classes de uma classe existente
// reutilizar atributos e métodos de uma classe existente quando eu quero criar uma nova classe.
// posso derivar de uma classe que já é derivada
// posso derivar de mais de uma classe de uma vez só

#include <iostream>
using namespace std;

class Point {
private:
	int x, y;

public:
	Point(int x1, int y1)
	{
		x = x1;
		y = y1;
	}
    ~Point(){}; // destructor

	Point(const Point &p1) // Copy constructor
	{
		x = p1.x;
		y = p1.y;
	}

	int getX() { return x; }
	int getY() { return y; }
};



int main()
{
	Point p1(10, 15); // Normal constructor is called here
	Point p2 = p1; // Copy constructor is called here
	Point p3 = p1; // and here

	// Let us access values assigned by constructors
	cout << "p1.x = " << p1.getX() << ", p1.y = " << p1.getY() << endl;
	cout << "p2.x = " << p2.getX() << ", p2.y = " << p2.getY() << endl;
	cout << "p3.x = " << p3.getX() << ", p3.y = " << p3.getY() << endl;
	return 0;
}

/* usar quando quiser inicializar 

O construtor de cópia usa uma referência a um objeto da mesma classe como argumento.


class Exemplo{
    ...
    Exemplo() { }; padrão
    Exemplo(const Exemplo &obj) { } de cópia
    explicit Exemplo(int valor) { } explícito
    Exemplo(Exemplo &&outro) noexcept { } de movimentação

}; */

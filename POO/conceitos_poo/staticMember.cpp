// C++ Program to demonstrate static member in a class
#include <iostream>
using namespace std;

class Student {
public:
	// static member - apenas uma instância da variável é compartilhada dentre todas as instâncias da classe.
	static int total;


	// Constructor called
	Student() { total += 1; }
};

int Student::total = 0;
 
int main()
{
    //Class Student

	// Student 1 declared
	Student s1;
	cout << "Number of students:" << s1.total << endl;

	// Student 2 declared
	Student s2;
	cout << "Number of students:" << s2.total << endl;

	// Student 3 declared
	Student s3;
	cout << "Number of students:" << s3.total << endl;


	return 0;
}

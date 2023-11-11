#include <iostream>
using namespace std;

class salario{
    private:
    int salary;

    public:
    void setSalary(int s){
        salary = s;
    }

    int getSalary(){
        return salary;
    }

};

int main(){
    salario obj;
    obj.setSalary(3500);
    cout << obj.getSalary() << endl;

}
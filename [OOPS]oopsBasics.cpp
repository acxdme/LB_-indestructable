#include <iostream>
using namespace std;

class Animal {
public:
    int age;
    string name;
    int weight;
    Animal() {
        this->age = 0;
        this->name = "";
        this->weight = 0;
    }

     void eat() {
        cout << "Eating" << endl;
     }

     ~Animal() {
         cout << "Destructor called" << endl;
     }

};

int main()
{
    //int n;
    //cin >> n;
    //cout << n << endl;
    cout << "The size of empty class is "<<sizeof(Animal)<<endl;
    //static way of intialization
    Animal a;
    cout << "age of a " << a.age << endl;

    Animal* b = new Animal;

    cout << "age of b " << b->age << endl;
    delete b;
    
}

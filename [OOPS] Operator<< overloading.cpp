#include <iostream>
#include <string>
using namespace std;


class Human {
public:
    int age = 18;
    double height = 6.2;
    string color = "brown";
};

void operator<<(ostream& os, const Human& obj) {
    cout << obj.age << endl;
    cout << obj.height << endl;
    cout << obj.color << endl;
    
}

int main() {
    Human a;
    cout << a;
    return 0;
}

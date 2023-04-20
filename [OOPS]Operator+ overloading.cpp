
#include <iostream>
using namespace std;


int main()
{
    class Number {
    public :
        int val = 12;
        // function for operator overloading
        void operator+(Number& obj) {
            cout << "the addition of two values is : " << this->val + obj.val << endl;
     }
    };

    Number a;
    Number b;
    a + b;
}

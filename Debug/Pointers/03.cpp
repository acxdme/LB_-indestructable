#include<iostream>
using namespace std;


int* foo() {
    int x = 1000;
    int* p = &x;
    return p;
}

int main() {
    int* q = foo();
    cout << *q << endl; // working fine without any change.
    return 0;
}

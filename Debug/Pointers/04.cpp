#include<iostream>
using namespace std;


int main() {
    int *p = new int; // new int
    *p = 10;
    cout<<p <<" "<<*p;
    delete p;
    return 0;
}

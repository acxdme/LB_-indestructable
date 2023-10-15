
int a = 5;
int *p = &a;
int *q = p;

cout<< a<< endl;
cout << *p << endl;
cout << q <<endl;
cout << &q <<endl;

        int a = 10;
        int* p = &a;
        int* q = p;
        int* r = q;

        cout << a << endl; //10
        cout << &a << endl; //address of a 
        cout << p << endl; //address of a 
        cout << &p << endl; //address of p
        cout << *p << endl; //10
        cout << q << endl; //address of a
        cout << &q << endl; //address of q
        cout << *q << endl; //10
        cout << r << endl; //address of a
        cout << &r << endl; //address of r
        cout << *r << endl; //10
        cout << (*p + *q + *r) << endl; //30
        cout << (*p)*2 + (*r)*3 << endl; //50
        cout << (*p/2) - (*q)/2 << endl; //0


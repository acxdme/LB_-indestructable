// gcd of two numbers

int gcd(int a, int b)
{

    if (b == 0)
        return a;
    return gcd(b,a% b);
}

int main() {
    
    int _gcd = gcd(20,3);
    cout<<"gcd is : "<<_gcd <<endl;

    return 0;
}

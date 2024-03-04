//ugly numbers , pata nahi kaha se aa gaya

#include <iostream>
using namespace std;

bool isUgly(int n)
{
    if (n <= 1) // fix : value of n
        return false; 
    int temp = n;
    while (n != 1)
    {
        if (n % 2 == 0)
            n /= 2;
        else if (n % 3 == 0)
            n /= 3;
        else if (n % 5 == 0)
            n /= 5;
        if (temp == n)
            return false; // fix : return statement
        temp = n;
    }
    return true; // fix : return statement
}

int main()
{
    int n = 9;
    cout << "The answer is : " << isUgly(n) << endl;
    return 0;
}

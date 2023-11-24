
#include<iostream>

using namespace std;

int multiplyNumbers(int m, int n) {
    if (n <= 0) // base case condition modified.
        return 0;
    return m + multiplyNumbers(m, n - 1);
}

int main() {
    int ans = multiplyNumbers(2, 1);
    cout << ans << endl;
    return 0;
}

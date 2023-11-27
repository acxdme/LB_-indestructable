// time-complexity : O(N)
// Space-complexity : O(N) , considering recursion stack

#include <iostream>
using namespace std;

void countNumbers(int n){
  if (n == 0) return ;
  countNumbers(n-1);
  cout << n << " ";

}

int main() {
    int n = 10;
    countNumbers(n);  
    cout << endl;
    return 0;
}

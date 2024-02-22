/ counting stairs debugging
#include <iostream>
using namespace std;

int climbStairs(int n) {
        int a = 1; // prev2
        int b = 1; // prev1

        for(int i = 2 ; i <= n ; i++){
           int c = a + b; // fix : c = a + b;
            a = b;
            b = c;
        }
        return b;
    }

int main() {
  int res = climbStairs(3);

  cout<< res << endl;
  return 0;
}

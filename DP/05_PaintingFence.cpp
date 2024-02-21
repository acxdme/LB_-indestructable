// gfg- https://www.geeksforgeeks.org/problems/painting-the-fence3727/1
// Revisit the logic 

#include<iostream>
#include<vector>

using namespace std;
int solveRec(int n,int k){
    // Base case
    if(n == 1){
        return k;
    }
    if(n == 2){
        return k + k*(k-1);
    }
    // Recursive call
    int ans = (solveRec(n-2,k) + solveRec(n-1,k))*(k-1);
    return ans;
}

// Maximum Area of Square with 1.

#include <iostream>
#include <vector>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
    int n=matrix.size();
    int m=matrix[0].size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    int maxi=0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (matrix[i-1][j-1] == '1'){ // fix : the indexing for matrix will be 0 based.
                dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
                maxi = max(maxi, dp[i][j]);
            }
        }
    }
    return maxi;
}

int main() {
//   vector<vector<char>> matrix = {{'1','1','1','1'},{'0','1','1','1'},{'1','1','1','1'},{'1','1','1','0'}};
vector<vector<char>> matrix = {{'0','1'},{'1','0'}};
  int answer = maximalSquare(matrix);

  cout<<"The answer is : "<<answer<<endl;
  return 0;
}

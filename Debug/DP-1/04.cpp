// Minimum Path sum , debugging problem

#include <iostream>
#include <vector>
#include<limits.h>

using namespace std;

int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, INT_MAX));
        dp[0][0] = grid[0][0]; // fix : dp[0][0]
        for(int r = 1 ; r < m ;r++){ //fix:  populate 1st row
            dp[r][0] = grid[r][0] + dp[r-1][0];
        }
        for(int c = 1 ; c < n ;c++){ // fix : populate 1st column
            dp[0][c] = grid[0][c] + dp[0][c-1];
        }
        for(int i=1; i<m; i++){ // fix : 1 to m
            for(int j=1; j<n; j++){ // fix 1 to n
                dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i][j]; //fix : dp[i][j]
             }
        }
        return dp[m-1][n-1];
    }

int main() {
  vector<vector<int>> grid = {{1,2,3},{4,5,6}};
  int answer = minPathSum(grid);
  cout << "answer is :" <<answer << endl;
  return 0;
}

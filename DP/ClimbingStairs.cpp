/*
  Method : T.C -- S.C
  Recursion : Exponential -  Exponential
  Top-Down : O(N) -- O(N) + O(N) , recursive space + dp
  Bottom-up : O(N) -- O(N) , dp array
  Space-Optimization : O(N) -- O(1)
*/

class Solution {
public:
    int solveRec(int n){
        if( n == 0 || n == 1) return 1;

        return solveRec(n-1) + solveRec(n-2);
    }

    int solveMemo(int n , vector<int>&dp){
        if( n == 0 || n == 1) return 1;
        if(dp[n] != -1) return dp[n];

        return dp[n] = solveRec(n-1) + solveRec(n-2);

    }

    int solveTab(int n , vector<int>& dp){
        //base-cases
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2 ; i<=n ;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];

    }

    int solveSpaceOp(int n){
        int prev1 = 1;
        int prev2 = 1;

        int curr ;
        for(int i =2 ;i<=n ; i++){
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    int climbStairs(int n) {
        if(n == 1) return 1;

        // recursive approach
        // int ans = solveRec(n);
        // return ans;

        // Top-down approach
        // vector<int> dp(n+1,-1);
        // int ans = solveMemo(n,dp);
        // return ans;

        // Bottom-up approach(Tabulation)
        // vector<int> dp(n+1,-1);
        // int ans = solveTab(n,dp);
        // return ans;

        //Space-optimized approach
         int ans = solveSpaceOp(n);
         return ans;



    }
};

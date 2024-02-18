// lc - 509

class Solution {
public:
    int solveRec(int n){
        //base-case
        if(n == 0 || n == 1){
            return n;
        }

        // f(n) = f(n-1) + f(n-2)
        int result = solveRec(n-1) + solveRec(n-2);

        return result;
    }

    int solveMem(int n , vector<int> &dp){
        //base-case
        if(n == 0 || n == 1){
            return n;
        }
        if(dp[n] != -1){
            return dp[n];
        }

        // f(n) = f(n-1) + f(n-2)
        int result = solveMem(n-1,dp) + solveMem(n-2,dp);
        dp[n] = result;

        return dp[n];
    }

    int solveTab(int n){
        vector<int> dp(n+2,-1);
        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2 ; i <= n ; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }

    int spaceOpt(int n){

        if(n == 0 || n == 1){
            return n;
        }
        int prev2 = 0;
        int prev1 = 1;
        for(int i = 2 ; i<=n ; i++){
            int curr = prev2 + prev1;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    int fib(int n) {

        // Recursion
        // int answer = solveRec(n);
        // return answer;

        // Recursion + Memoization
        // vector<int> dp(n+1,-1);
        // int answer = solveMem(n,dp);
        // return answer;

        // Tabulation approach
        // int answer = solveTab(n);
        // return answer;

        //Space optimization approach 
        int answer = spaceOpt(n);
        return answer;
        
    }
};

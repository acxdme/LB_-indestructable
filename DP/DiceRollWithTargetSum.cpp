class Solution {
public:

    int MOD = 100000007;

    int solveRec(int n , int k , int target){
        if(target < 0  || n <  0) return 0;

        if(target == 0 && n == 0 ) return 1;

        int ans = 0;
        n--;
        for(int i = 1 ; i <= k ; i ++){
           ans  = ((ans) % MOD + (solveRec(n,k,target - i)) % MOD) % MOD;
        }

        return ans;
    }

    int solveMem(int n , int k , int target, vector<vector<int>>& dp){

        if(n<0) 
            return 0;
        if(n == 0 && target == 0)
            return 1;
        if(n == 0 && target != 0)
            return 0;
        if(n!=0 && target == 0)
            return 0;

        if(dp[n][target] != -1) return dp[n][target];

        int ans = 0;
        n--;
        for(int i = 1 ; i <= k ; i ++){
         if(target - i >= 0){
            ans  = ((ans) % MOD + (solveMem(n,k,target - i,dp)) % MOD) % MOD;
         }
        }
        dp[n][target] = ans;
        return dp[n][target];
    }
    int numRollsToTarget(int n, int k, int target) {

        if (target > n*k || target < 1*n) return 0;
        // int ans = solveRec(n,k,target);

        //Memoization
        vector<vector<int>>dp(n+10,vector<int>(target+10,-1));
        int ans = solveMem(n,k,target,dp);

        return ans;
    }
};

// Coin change leetcode 332
class Solution {
public:
    int findMinCoinsUsingRecursion(vector<int>& coins , int target){
        if(target == 0) return 0;
        
        int ans =  10001; // max as per given constraint
        for(auto coin : coins){
          if(target-coin >= 0){
              ans = min(ans,1+findMinCoinsUsingRecursion(coins,target-coin));
          }
            
        }

        return ans;

    }

    int solveMem(vector<int>& coins, int target ,vector<int>& dp){

        if(target == 0) return 0;
        if(dp[target] != -1) return dp[target];
        
        int ans =  10001;
        for(auto coin : coins){
          if(target-coin >= 0){
              ans = min(ans,1+solveMem(coins,target-coin,dp));
          }
            
        }
        dp[target] = ans;
        return dp[target];

    }

    int coinChange(vector<int>& coins, int amount) {

        //Recursive approch
        // int ans = findMinCoinsUsingRecursion(coins,amount);
        // if( ans == 10001) ans = -1;

        //Memoization(top-down)
        vector<int>dp(amount+1,-1);
        int ans = solveMem(coins,amount,dp);
        if( ans == 10001) ans = -1;

        return ans;
        
    }
};

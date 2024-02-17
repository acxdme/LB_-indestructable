// lc -322
// Recursion Logic : 0 -> amount.
// resolved tle with tabulation approach.

class Solution {
public:

    long long int solveRecursion(vector<int>& coins , long long int curr, int& amount){
        if(curr > amount){
            return INT_MAX;
        }
        if(curr == amount ){
            return 0;
        }

        long long  int mini = INT_MAX;
        for(int i = 0 ; i< coins.size() ;i++){
           long long int sum = curr + coins[i];
           long long int ans = solveRecursion(coins,sum,amount);
           if(ans != INT_MAX){
             mini = min(mini, 1 + ans);
           }
        }

        return mini;
    }

    long long int solveMem(vector<int>& coins , long long int curr, int& amount ,vector<long long int>& dp){
        if(curr > amount){
            return INT_MAX;
        }
        if(curr == amount ){
            return 0;
        }
        if(dp[curr] != INT_MAX){
            return dp[curr];
        }

        long long  int mini = INT_MAX;
        for(int i = 0 ; i< coins.size() ;i++){

           long long int ans = solveMem(coins,curr + coins[i],amount,dp);
           if(ans != INT_MAX){
             mini = min(mini, 1 + ans);
           }
             dp[curr] = mini;
        }

        return dp[curr];
    }

    // solve tab
    long long int solveTab(vector<int>& coins , int amount){
        vector<int> dp(amount+1 , INT_MAX);
        // base-case
        dp[amount] = 0;


        for(int total = amount - 1; total >=0 ; total--){
            long long  int mini = INT_MAX;
            for(int i = 0 ; i< coins.size() ;i++){
            long long int ans = INT_MAX;
                if(coins[i] <= amount &&  total + coins[i] <= amount){
                     ans = dp[total + coins[i]];
                }
                if(ans != INT_MAX){
                    mini = min(mini, 1 + ans);
                }
            }
                dp[total] = mini;
        }

        return dp[0];


    }

    int coinChange(vector<int>& coins, int amount) {

        //solveRecursion
        //  long long int curr = 0;
        //  long long int ans =  solveRecursion(coins,curr,amount);

        // if(ans == INT_MAX){
        //     return -1;
        // }

        // return ans;

        // solveMem
        // long long int curr = 0;
        // vector<long long int> dp(amount+1 , INT_MAX);
        // long long int ans =  solveMem(coins,curr,amount,dp);

        // if(ans == INT_MAX){
        //     return -1;
        // }

        long long int curr = 0;
        long long int ans =  solveTab(coins,amount);

        if(ans == INT_MAX){
            return -1;
        }

        return ans;

    }
};

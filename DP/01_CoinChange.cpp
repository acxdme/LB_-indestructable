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
           long long int sum = curr + coins[i];
           long long int ans = solveMem(coins,sum,amount,dp);
           if(ans != INT_MAX){
             mini = min(mini, 1 + ans);
             dp[curr] = mini;
           }
        }

        return dp[curr];
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
        long long int curr = 0;
        vector<long long int> dp(amount+1 , INT_MAX);
        long long int ans =  solveMem(coins,curr,amount,dp);

        if(ans == INT_MAX){
            return -1;
        }

        return ans;


        
    }
};

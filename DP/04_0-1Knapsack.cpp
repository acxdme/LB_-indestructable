// gfg - https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

class Solution
{
    public:
    
    int MaximumTotalValueRecursion(int wt[] , int val[] ,int C,int index ){
        
        if(index == 0){
            if(wt[index] <= C){
                return val[index];
            }
            else{
                return 0;
            }
        }
        
        
        //include 
        int inc = 0;
        if(wt[index] <= C )
        inc = val[index] +  MaximumTotalValueRecursion(wt,val,C - wt[index],index -1);
        
        //exlcude
        int exc = 0 + MaximumTotalValueRecursion(wt,val,C,index -1);
        
        int res = max(inc,exc);
        
        
        return res;
    }
    
    int MaximumTotalValueMemo(int wt[] , int val[] ,int C,int index ,vector<vector<int>> &dp ){
        
        if(index == 0){
            if(wt[index] <= C){
                return val[index];
            }
            else{
                return 0;
            }
        }
        if(dp[index][C] != -1){
            return dp[index][C];
        }
        
        
        //include 
        int inc = 0;
        if(wt[index] <= C )
        inc = val[index] +  MaximumTotalValueMemo(wt,val,C - wt[index],index -1,dp);
        
        //exlcude
        int exc = 0 + MaximumTotalValueMemo(wt,val,C,index -1,dp);
        
        dp[index][C] = max(inc,exc);
        
        
        return dp[index][C];
    }
    
    int MaximumTotalValueTabulation(int weight[] , int value[] ,int maxWeight,int index ){
        
        vector<vector<int>>dp(index + 2 , vector<int>(maxWeight+2 ,0));
        
        //base case
        for(int i= 1 ;i<= maxWeight;i++){
          if( weight[0] <= i  )
              dp[0][i] = value[0];
        }
        
        int n = index + 1;
        for(int row = 1 ;row < n;row ++){
            for(int w = 1; w <= maxWeight;w++){
                int inclusive = 0;
                if(weight[row] <= w )
                    inclusive = value[row] + dp[row-1][w-weight[row]];
                int exclusive = 0 + dp[row-1][w];
                    dp[row][w] = max(inclusive,exclusive); 
            }
        }
        return dp[n-1][maxWeight];
        
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        int index = n - 1;
        
        // // Recursion
        // int ans = MaximumTotalValueRecursion(wt,val,W,index);
        
        //vRecursion + Memoization
        // vector<vector<int>>dp(n + 1 , vector<int>(W+1 ,-1));
        // int ans = MaximumTotalValueMemo(wt,val,W,index,dp);
        
        // Tabulation
        
        int ans = MaximumTotalValueTabulation(wt,val,W,index);
        
        
        
        
        return ans;
    }
};

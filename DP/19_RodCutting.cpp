// TC : O(N^2) {Memoization approach}
// SC : O(N)
// gfg : https://www.geeksforgeeks.org/problems/rod-cutting0840/

class Solution{
  public:
  
    int getPriceRecursive(int& n , int rodLen,int price[]){
        //base-case
        if(rodLen <= 0){
            return 0;
        }
        
        int maxi = -1e9;
        for(int i = 1 ; i <= rodLen ; i++){
            int p = price[i -1] + getPriceRecursive(n,rodLen - i ,price);
            maxi = max(maxi ,p);
        }
        
        return maxi;
    }
    
    int getPriceMemo(int rodLen, int price[] ,vector<int>& dp){
        //base-case
        if(rodLen <= 0){
            return 0;
        }
        if(dp[rodLen] != -1){
            return dp[rodLen];
        }
        
        int maxi = -1e9;
        for(int i = 1 ; i <= rodLen ; i++){
            int p = price[i -1] + getPriceMemo(rodLen - i ,price,dp);
            maxi = max(maxi ,p);
        }
        
        dp[rodLen] = maxi;
        
        return dp[rodLen];
        
    }
    
    int cutRod(int price[], int n) {
        
        // recursive approach
        // return getPriceRecursive(n,n,price);

        // memoization
        vector<int> dp(n+1,-1);
        int ans = getPriceMemo(n,price,dp);
        
        
        return ans;
        
        
    }
};

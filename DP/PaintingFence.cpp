    public:
    long long int temp = 1000000007;
    long long int  solveRecursion(int n , int k){
        if( n == 1) return k;
        if( n == 2) return k*k;
        
        long long int ans = ((k-1) % temp * (solveRecursion(n-1,k) % temp + solveRecursion(n-2,k) % temp))%temp;
        
        
        return ans;
        
    }
    
    long long int  solveMem(int n , int k,vector<int>& dp){
        if( n == 1) return k;
        if( n == 2) return k*k;
        if(dp[n] != -1) return dp[n];
        
        long long int ans = ((k-1) % temp * (solveMem(n-1,k,dp) + solveMem(n-2,k,dp)) % temp)%temp;
        
        dp[n] = ans;
        
        
        return dp[n];
        
    }
    
    long long int  solveTab(int n , int k){
        
        vector<long long int>dp(n+1,0);
        dp[1] = k;
        dp[2] = k*k;
        
        for(int post = 3 ; post <= n ;post++){
            
         long long int ans = ((k-1) % temp * (dp[post-1] + dp[post-2]) % temp) % temp;
         dp[post] = ans;
         
        }
        
        return dp[n];
        
    }
    
    long long int  solveSO(int n , int k){
        
        long long int prev1=0, prev2=0;
        prev2 = k;
        prev1 = k*k;
        
        if(n == 1) return prev2;
        if(n == 2) return prev1;
        for(int post = 3 ; post <= n ;post++){
            
         long long int curr = ( (k-1) % temp * (prev1 % temp + prev2 % temp) % temp ) % temp;
         
         //shifting logic
         prev2 = prev1;
         prev1 = curr;
         
        }
        
        return prev1;
        
    }
    
    
    
    
    long long countWays(int n, int k){
        long long int  ans = 0;
        
        // Recursion
        // ans = solveRecursion(n,k);
        
        // Memoisation
        // vector<int>dp(n+1,-1);
        // ans = solveMem(n,k,dp);
        // return ans;
        
        // Tabulation
        // ans = solveTab(n,k);
        // return ans;
        
        // Space optimization
        ans = solveSO(n,k);
        return ans;
        
    }

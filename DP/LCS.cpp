//LCS attempt-1 (from n-1 to 0 , struck at Tabulation formation )

class Solution
{
    public:
    
    // int solveRec(int i , int j , string& s1 , string &s2 , vector<vector<int>>& dp){
    //     if(i < 0 or j < 0 ) return 0;
        
    //     int include = 0;
    //     int exclude = 0;
    //     if(s1[i]==s2[j]){
    //         include = 1 + solveRec(i-1,j-1,s1,s2);
    //     }else{
    //         exclude = max(solveRec(i-1,j,s1,s2),solveRec(i,j-1,s1,s2));
    //     }
        
    //     return max(include,exclude);
    // }
    
    int solveMem(int i , int j , string& s1 , string &s2,vector<vector<int>>& dp){
        
        if(i < 0 or j < 0 ) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int include = 0;
        int exclude = 0;
        
        if(s1[i]==s2[j]){
            include = 1 + solveMem(i-1,j-1,s1,s2,dp);
        }else{
            exclude = max(solveMem(i-1,j,s1,s2,dp),solveMem(i,j-1,s1,s2,dp));
        }
        
        dp[i][j] = max(include,exclude);
        return dp[i][j];
    }
    
    
    int solveTab(int i , int j , string& s1 , string &s2){ // need to dry-run
        
        
        vector<vector<int>> dp(i,vector<int>(j,0));
        
        if(s1[0] == s2[0]) dp[0][0] = 1;
        
        
        for(int u = 1 ; u < i; u++){
            for(int v = 1 ; v < j ; v++){
                int include = 0;
                int exclude = 0;
                
                if(s1[u]==s2[v]){
                    include = 1 + dp[u-1][v-1];
                }else{
                    exclude = max(dp[u-1][v],dp[u][v-1]);
                }
                
                dp[u][v] = max(include,exclude);
                
            }
        }
        

        return dp[i-1][j-1];
    }
    
    
    
    
    
    
    
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        //Recursive approach
        // int ans = solveRec(x-1,y-1,s1,s2);
        
        //Memoization
        // vector<vector<int>> dp(x,vector<int>(y,-1));
        // int ans = solveMem(x-1,y-1,s1,s2,dp);
        
        int ans = solveTab(x,y,s1,s2);
        
        return ans;
    }
};

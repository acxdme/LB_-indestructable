/*
  Recursive approach : 0 ---> n 
  
*/

class Solution {
public:
    int solveMem(string& s ,string& t,int i,int j,int& size,vector<vector<int>>&dp){
        if(i >= size || j >= size) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int include = 0;
        int exclude = 0;
        if(s[i]== t[j]){
            include =  1 + solveMem(s,t,i+1,j+1,size,dp);
        }
        else{
            exclude = max(solveMem(s,t,i,j+1,size,dp),solveMem(s,t,i+1,j,size,dp));
        }

        return dp[i][j] = max(include,exclude);
    }

    int solveRec(string& s ,string& t,int i,int j,int& size){
        if(i >= size || j >= size) return 0;

        int include = 0;
        int exclude = 0;
        if(s[i]== t[j]){
            include =  1 + solveRec(s,t,i+1,j+1,size);
        }
        else{
            exclude = max(solveRec(s,t,i,j+1,size),solveRec(s,t,i+1,j,size));
        }

        return max(include,exclude);
    }
    int longestPalindromeSubseq(string s) {
        string t  = s;
        reverse(t.begin(),t.end());

        // Recursive 
        // int n = t.size();
        // int ans = solveRec(s,t,0,0,n);

        //Memoization
         int n = t.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int ans = solveMem(s,t,0,0,n,dp);


        return ans;
        
    }
};

class Solution {
public:


    int findMaxRobbery(vector<int>& nums,int start,int end){
        if(start >= end){
            return 0;
        }

        int include = nums[start] + findMaxRobbery(nums,start+2,end);
        int exclude = 0 + findMaxRobbery(nums,start+1,end);

        int ans = max(include,exclude);

        return ans;
    }

    int solveMem(vector<int>& nums,int start,int end,vector<int>&dp){
        if(start >= end){
            return 0;
        }
        if(dp[start] != -1) return dp[start];

        int include = nums[start] + solveMem(nums,start+2,end,dp);
        int exclude = 0 + solveMem(nums,start+1,end,dp);

        int ans = max(include,exclude); 

        dp[start] = ans;

        return dp[start];
    }


    int rob(vector<int>& nums) {

        int n = nums.size();

        // Recursive approach
        // int ans = findMaxRobbery(nums,0,n);

        //Memoisation
        vector<int> dp(n,-1);
        int ans = solveMem(nums,0,n,dp);

        return ans;
        
    }
};

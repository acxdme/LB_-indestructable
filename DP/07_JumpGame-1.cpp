// Recursive &  Recursion + Memoization approach added
// lc - 55
class Solution {
public:

    // Recursion
    bool canReach(vector<int>& nums , int index , int size ){
        // base-case
        if(index == size -1){
            return true;
        }

        bool answer = false;
        for(int jump = 1 ; jump <= nums[index] ; jump++){
            answer = canReach(nums,index + jump,size);
            if(answer){
                return true;
            }
        }

        return answer;

    }

    // Memoization
    bool canReach2(vector<int>& nums , int index , int size, vector<int> &dp){
        // base-case
        if(index == size -1){
            return true;
        }
        if(dp[index] != -1)
        {
            return dp[index];
        }

        bool answer = false;
        dp[index] = answer;
        for(int jump = 1 ; jump <= nums[index] ; jump++){
            answer = canReach2(nums,index + jump,size,dp);
            if(answer){
                dp[index] = answer;
                return dp[index];
            }
        }

        return dp[index];

    }

    bool canJump(vector<int>& nums) {

        int n = nums.size();
        
        // Recursive approach
        // bool  res =  canReach(nums,0,n);

        // Memoization approach 
        vector<int> dp(n+1,-1);
        bool  res =  canReach2(nums,0,n,dp);

        
        return res;
    }
};

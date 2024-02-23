// Recursive &  Recursion + Memoization approach added
// lc - 55
// space optimization not possible.
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

    // Tabulation approach 
        bool canReach3(vector<int>& nums , int size){

        //declare vector
        vector<int> dp(size+1 , 0); // {0,0,0,0}
        // base-case
        dp[size-1] = true;

        for(int index = size - 2 ; index >= 0 ; index--){
            bool answer = false;
            dp[index] = answer;
            for(int jump = 1 ; jump <= nums[index] ; jump++){
                if(index + jump < size)
                  answer = dp[index + jump];
                if(answer){
                    dp[index] = answer;
                    break;
                }
            }
        }


        return dp[0];

    }


    bool canJump(vector<int>& nums) {

        int n = nums.size();
        
        // Recursive approach
        // bool  res =  canReach(nums,0,n);

        // Memoization approach 
        // vector<int> dp(n+1,-1);
        // bool  res =  canReach2(nums,0,n,dp);

        bool res = canReach3(nums,n);

        
        return res;
    }
};

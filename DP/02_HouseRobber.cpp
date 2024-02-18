//lc -198
class Solution {
public:

    int solveRec(vector<int>& nums,int &size ,int index){
        if(index >= size){ return 0 ;}

        //include
        int inc =  nums[index] + solveRec(nums,size,index +2);

        // exclude
        int exl =  0 + solveRec(nums,size,index+1);

        return max(inc , exl);
    }

    int solveMem(vector<int>& nums,int &size ,int i,vector<int> &dp){
        if(i >= size){ return 0 ;}
        if(dp[i] != -1 ) return dp[i]; // nums can be {0,0,0,0} , but they can't be -ve

        //include
        int inc =  nums[i] + solveRec(nums,size,i +2);

        // exclude
        int exl =  0 + solveRec(nums,size,i+1);
        
        dp[i] = max(inc,exl);
        return dp[i];
    }

    int solveTab(vector<int>& nums,int &size){
        // n -> 0

        vector<int>dp(size+1, INT_MIN); // -1 can be also used
        dp[size] = 0;

        for(int i = size - 1 ; i >=0 ; i--){
            //include
            int inc = nums[i];
            if(i + 2 < size && dp[i+2] != INT_MIN)
            inc +=   dp[i +2];

            // exclude
            int exl =  0 + dp[i+1];
            
            dp[i] = max(inc,exl);

        }
        return dp[0];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];


        // Recursion
        // int ans = solveRec(nums,n,0);
        // return ans;
        

        // solveMemoization
        // vector<int> dp(n+1,-1);
        // int ans = solveMem(nums,n,0,dp);
        // return ans;

        // solveTab
        int ans = solveTab(nums,n);
        return ans;

        
    }
};

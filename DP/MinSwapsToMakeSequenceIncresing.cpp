class Solution {
public:

    int solveRecursive(vector<int>& nums1 ,vector<int>& nums2 , int index , int& n,bool swapped){
        if(index >= n) return 0;

        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];

        int ans = INT_MAX;
        if(swapped){
            swap(prev1,prev2);
        }

        if(nums1[index] > prev1 && nums2[index] > prev2){
            ans = 0 + solveRecursive(nums1,nums2,index+1,n,false);
        }
        if(nums1[index] > prev2 && nums2[index] > prev1){
            ans = min(ans,1+solveRecursive(nums1,nums2,index+1,n,true));
        }


        return ans;
    }

    int solveMem(vector<int>& nums1 ,vector<int>& nums2 , int index , int& n,int swapped,vector<vector<int>>& dp){
        if(index >= n) return 0;
        if(dp[swapped][index] != -1)
         return dp[swapped][index];


        int prev1 = nums1[index-1];
        int prev2 = nums2[index-1];

        int ans = INT_MAX;
        if(swapped){
            swap(prev1,prev2);
        }

        if(nums1[index] > prev1 && nums2[index] > prev2){
            ans = 0 + solveMem(nums1,nums2,index+1,n,0,dp);
        }
        if(nums1[index] > prev2 && nums2[index] > prev1){
            ans = min(ans,1+solveMem(nums1,nums2,index+1,n,1,dp));
        }

        dp[swapped][index] = ans;
        return dp[swapped][index];
    }


    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);

        int n = nums1.size();
        //Recursion
        // int ans = solveRecursive(nums1,nums2,1,n,0);

        // Memoization(Top-down)
        vector<vector<int>>dp(2,vector<int>(n,-1));
        int ans = solveMem(nums1,nums2,1,n,0,dp);

        return ans;

    }
};

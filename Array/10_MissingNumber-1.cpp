// lc (268)
// TC : O(N)
// SC : O(1)

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ;i++){
            sum += nums[i];
        }
        
        int ans =  (n * (n+1))/2 - sum;
        return ans;
    }
};

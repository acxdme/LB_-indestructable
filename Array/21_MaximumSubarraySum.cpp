// lc-53
// Maximum Subarray Sum
// TC : O(N) , SC : O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int global_sum = nums[0];
        int local_sum = 0;
        for (int i = 0; i < nums.size(); i++) {

            local_sum += nums[i];
            global_sum = max(global_sum, local_sum);

            local_sum = max(0,local_sum);
        }

        return global_sum;
    }
};

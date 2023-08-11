// Time complexity : O(N)
// space complexity : O(N)
// lc-442

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();

        for(int i =0 ; i< n ; i++){
            if(nums[abs(nums[i]) - 1] < 0)
            {
                return abs(nums[i]);
            }
            nums[abs(nums[i]) - 1] *= -1;
        }
        
        return -1;
    }
};

// lc - 53
// tc - O(N)
// sc - O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = nums[0];
        int sum = nums[0];
        for(int i = 1 ; i < nums.size() ; i++){
            int currVal = nums[i];
            sum = max(sum+currVal , currVal);
            maxi = max(maxi,sum);
        }

        return maxi;
        
    }
};

// Easy nahi hai beta , lc-136
// TC- O(N)
// SC- O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = nums[0] ;
        for(int i = 1; i < nums.size();i++){
            ans = ans ^ nums[i];
        }

        return ans;
    }
};

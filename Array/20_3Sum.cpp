// T.C : O( nlog(n) + O(n^2)
// S.C : O(1)
// lc - 15 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        // sort the nums vector
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        for (int i = 0; i < n - 2; i++) {

            // remove duplicate
            if (i != 0 && nums[i] == nums[i - 1])
                continue;
            int target = -nums[i];
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                if (nums[j] + nums[k] == target) {
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    // remove duplicates
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                } else if (nums[j] + nums[k] > target) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return result;
    }
};

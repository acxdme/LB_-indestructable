// Unable to formulate logic for 0 -> target approach
class Solution {
public:
    bool findSubsetSumRecursion(vector<int>& nums, int& size, int index,
                                int sum, int& targetSum) {
        // base-case
        if (index >= size || sum > targetSum) {
            return false;
        }
        if (sum == targetSum) {
            return true;
        }

        bool take = findSubsetSumRecursion(nums, size, index + 1,
                                           sum + nums[index], targetSum);
        if (take) {
            return true;
        }

        bool notTake =
            findSubsetSumRecursion(nums, size, index + 1, sum + 0, targetSum);

        bool res = (take || notTake);

        return res;
    }

    bool findSubsetSumMemo(vector<int>& nums, int& size, int index, int sum,
                           int& targetSum, vector<vector<int>>& dp) {
        // base-case
        if (index == size || sum > targetSum) {
            return false;
        }
        if (sum == targetSum) {
            return true;
        }
        if (dp[index][sum] != -1) {
            return dp[index][targetSum];
        }

        bool take = findSubsetSumMemo(nums, size, index + 1, sum + nums[index],
                                      targetSum, dp);

        bool notTake =
            findSubsetSumMemo(nums, size, index + 1, sum, targetSum, dp);

        dp[index][sum] = (take || notTake);

        return dp[index][sum];
    }
    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        if (n <= 1)
            return false;
        int totalSum = 0;
        for (int i = 0; i < n; i++) {
            totalSum += nums[i];
        }

        if (totalSum & 1) { // return false if sum is odd.
            return false;
        }
        int targetSum = totalSum / 2;
        int sum = 0;

        // Recursion
        // bool ans = findSubsetSumRecursion(nums, n, 0, sum, targetSum);

        // Memoization
        vector<vector<int>> dp(n + 1, vector<int>(targetSum + 1, -1));
        bool ans = findSubsetSumMemo(nums, n, 0, sum, targetSum, dp);

        return ans;
    }
};

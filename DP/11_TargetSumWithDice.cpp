// lc - 1155
// Number of Dice Rolls with Target Sum

#define MOD 1000000007
class Solution {
public:
    int findWaysRecursive(int n, int k, int target) {
        // base-case
        if (n == 0 && target == 0) { // all dices used and target matched
            return 1;
        }
        if (n == 0 && target != 0) { // all dices used ,target not found
            return 0;
        }
        if (n != 0 && target == 0) { // target matched but , dices remains
            return 0;
        }

        int ans = 0;
        for (int face = 1; face <= k; face++) {
            ans = ((ans % MOD) +
                   (findWaysRecursive(n - 1, k, target - face) % MOD)) %
                  MOD;
        }

        return ans;
    }

    int findWaysMemo(int n, int k, int target, vector<vector<int>>& dp) {
        // base-case
        if ( n < 0) // dices are zero
        {
            return 0;
        }
        if ( target < 0){ // target becomes negative
            return 0;
        }
        if (n == 0 && target == 0) { // all dices used and target matched
            return 1;
        }
        if (n == 0 && target != 0) { // all dices used ,target not found
            return 0;
        }
        if (n != 0 && target == 0) { // target matched but , dices remains
            return 0;
        }
        if (dp[n][target] != -1) {
            return dp[n][target];
        }

        int ans = 0;
        for (int face = 1; face <= k; face++) {
            ans = ((ans % MOD) +
                   (findWaysMemo(n - 1, k, target - face, dp) % MOD)) %
                  MOD;
        }
        dp[n][target] = ans;

        return dp[n][target];
    }
    int numRollsToTarget(int n, int k, int target) {

        if (target > n * k) { // impossible to make target
            return 0;
        }

        // Recursion
        // int res = findWaysRecursive(n, k, target);

        // Memoization
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        int res = findWaysMemo(n, k, target,dp);

        return res;
    }
};

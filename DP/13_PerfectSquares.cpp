// lc - 279

class Solution {
public:
    int getMinNumbers(int n) { // exponential time complexity
        if (n <= 0) {
            return 0;
        }

        int mini = n;
        for (int i = 1; i * i <= n; i++) {
            int ans = 1 + getMinNumbers(n - i * i);
            mini = min(ans, mini);
        }

        return mini;
    }
    int getMinNumbersMemo(int n, vector<int>& dp) {
        if (n <= 0) {
            return 0;
        }
        if (dp[n] != -1) {
            return dp[n];
        }

        int mini = n;
        for (int i = 1; i * i <= n; i++) {
            int ans = 1 + getMinNumbersMemo(n - i * i, dp);
            mini = min(ans, mini);
        }

        dp[n] = mini;
        return dp[n];
    }

    int getMinNumbersTabulation(int n) {
        vector<int> dp(n + 1, 0);

        for (int k = 1; k <= n; k++) {
            int mini = k;
            for (int i = 1; i * i <= k; i++) {
                int ans = 1 + dp[k - i * i];
                mini = min(ans, mini);
            }
            dp[k] = mini;
        }

        return dp[n];
    }
    int numSquares(int n) {

        // Recursive Solution
        // int res = getMinNumbers(n);

        // Memoization
        // vector<int> dp(n + 1, -1);
        // int res = getMinNumbersMemo(n, dp);

        // Tabulation
        int res = getMinNumbersTabulation(n);

        return res;
    }
};

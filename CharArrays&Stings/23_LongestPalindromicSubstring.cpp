// lc -
// tc : O(N^2)
// sc : O(1)

// key hint : make window{even/odd} and exand to make palindrome.

class Solution {
public:
    string longestPalindrome(string s) {

        int low = 0;
        int high = 0;
        int n = s.size();
        int maxLen = 1;
        int startingIndex = 0;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j <= 1; j++) { // for even/odd window
                low = i;
                high = i + j;

                while (low >= 0 && high < n && s[low] == s[high]) {

                    int currLen = (high - low) + 1;
                    if (currLen > maxLen) {
                        maxLen = currLen;
                        startingIndex = low;
                    }
                    low--;
                    high++;
                }
            }
        }

        return s.substr(startingIndex, maxLen);
    }
};

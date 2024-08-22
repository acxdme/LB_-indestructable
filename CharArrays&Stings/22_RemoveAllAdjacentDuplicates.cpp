// lc - 1047
// tc : O(N)
// sc : O(1)

class Solution {
public:
    string removeDuplicates(string s) {

        int n = s.size() - 1;
        int i = 0;
        while (i < n - 1) {
            if (s[i] == s[i + 1]) {
                s.erase(i, 2);
                i = 0;
            } else {
                i++;
            }
        }

        return s;
    }
};

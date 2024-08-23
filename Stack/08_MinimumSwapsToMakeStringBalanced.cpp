// lc - 1963
// tc : O(N)
// sc : O(N)

class Solution {
public:
    int minSwaps(string s) {

        int n = s.size();
        if (n & 1 == 1)
            return -1;

        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '[') {
                st.push(s[i]);
            } else {
                if (!st.empty() && st.top() == '[') {
                    st.pop();
                } else {
                    st.push(s[i]);
                }
            }
        }

        int count = 0;
        // the below count method can be optimized just using stack ka size
        while (!st.empty()) {
            auto top = st.top();
            st.pop();
            auto top2 = st.top();
            st.pop();

            count++;
        }

        if (count & 1 == 1)
            count++;

        return count / 2;
    }
};

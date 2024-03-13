// lc-20 
// Valid Parenthesis

class Solution {
public:
    bool isValid(string s) {
        bool result = false;

        stack<char> st;
        for (auto ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if(st.empty()) return false;
                if (ch == ')') {
                    char top = st.top();
                    st.pop();
                    if (top != '(') {
                        return false;
                    }
                }

                if (ch == '}') {
                    char top = st.top();
                    st.pop();
                    if (top != '{') {
                        return false;
                    }
                }
                if (ch == ']') {
                    char top = st.top();
                    st.pop();
                    if (top != '[') {
                        return false;
                    }
                }
            }
        }

        if (st.empty()) {
            result = true;
        }

        return result;
    }
};

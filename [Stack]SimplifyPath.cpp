class Solution {
public:

    void reverseStack(stack<string>& st, string& ans) {
        if (st.empty()) return;

        string top = st.top();
        st.pop();

        reverseStack(st, ans);
        ans += top;
    }

    string simplifyPath(string ip) {
        stack<string> st;
            
        int start = 0;
        int end = start + 1;

        int n = ip.length();
        string temp;

        while (end < n) {

            while (ip[end] != '/' && end < n) {
                end++;
            }
            temp = ip.substr(start, end - start);
            start = end;
            end = start + 1;
            //cout << temp << " ";
            if (temp == "/" || temp == "/.") {
                continue;
            }
            else if (temp != "/..") {
                st.push(temp);
            }
            else if (!st.empty())
            {
                st.pop();
            }
        }
        
        string ans = st.empty() ? "/"  : "";
        reverseStack(st, ans);
        return ans;
    }

};

// Tc : O(N)
// Sc : O(N)
// lc : 1019

 vector<int> nextLargerNodes(ListNode* head) {

        vector<int> result;

        int index = 0;
        stack<pair<int, int>> st;  //<val,index>

        while (head != NULL) {
            result.push_back(0);
            while (!st.empty() && (st.top().first < head->val)) {
                auto top = st.top();
                st.pop();
                result[top.second] = head->val;
            }

            st.push({head->val, index});

            index++;
            head = head->next;
        }

        return result;
    }

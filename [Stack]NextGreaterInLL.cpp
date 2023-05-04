/*
Time complexity : O(N)
Space complexity : O(N)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    void reverseLL(ListNode* &head){
        if(head -> next == NULL) return;
        //initialize pointers
        ListNode* left = head;
        ListNode* curr = head->next;
        ListNode* right = curr->next;

        while(curr != NULL){
            //reverse link
            curr->next = left;
            // update pointers
            left = curr;
            curr = right;
            if(right != NULL){
                right = right ->next;
            }
        }
        head -> next = NULL;
        head = left;

    }

    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;

        reverseLL(head);

        ListNode* temp = head;
        stack<int> st;
        while(temp != NULL){
            if(st.empty()){
                ans.push_back(0);
            }else{
                while(!st.empty() && st.top() <= temp->val){
                    st.pop();
                }
                if(st.empty()){
                    ans.push_back(0);
                }else{
                    ans.push_back(st.top());
                }
                
            }
            st.push(temp->val);
            temp = temp->next;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

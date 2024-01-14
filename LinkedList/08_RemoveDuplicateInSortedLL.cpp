// lc-83
// tc : O(N)
// sc : O(1)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL ){
            return head;
        }
        if(head->next == NULL){
            return head;
        }

        // >1
        ListNode* curr = head;
        while(curr != NULL){
            if((curr->next) && (curr->next->val == curr->val)){
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                temp->next = NULL;
                delete(temp);
            }
            else{
                curr = curr->next;
            }
        }

        return head;

    }
};

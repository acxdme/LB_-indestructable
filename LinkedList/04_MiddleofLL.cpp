// slow & fast pointer approach 

class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL){

            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }

        return slow;
        
    }
};

//------------------------------------------------------------------------------------------------------------------------------------------
// gfg : https://www.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1
// tc : O(N)
// sc : O(1)

    int getMiddle(Node* head) {
        // base-case
        if(head == NULL) return -1;
        Node* slow = head;
        Node* fast = head;
        
        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }
        
          
       return slow->data;
    }

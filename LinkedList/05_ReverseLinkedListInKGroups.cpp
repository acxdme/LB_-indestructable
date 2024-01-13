// Tc: O(N)
// sc : O(N) , considerting recursive stack

class Solution {
public:

    int getLength(ListNode* &head){
        ListNode* temp = head;
        int length = 0;
        while(temp != NULL){
            temp = temp->next;
            length++;
        }

        return length;
    }
    ListNode* reverse(ListNode* &head, int k){

        if(head == NULL) return head;

        ListNode* prev =  NULL;
        ListNode* curr = head;

        int length = getLength(head);
        if( k > length  ) return head;

        int i = 0 ; 
        ListNode * forward = NULL;
        while( i < k){ // k =3
         forward = curr -> next;
         curr->next = prev;
         prev = curr;
         curr = forward;
         i++;
        }

        if(forward != NULL){

        head->next = reverse(forward,k);
        }
       
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* updatedHead = reverse(head,k);

        return updatedHead;
    }
};

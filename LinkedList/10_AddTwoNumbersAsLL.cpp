// lc- 2
// tc : O(N)
// sc : O(N) , since we are creating new linked list

class Solution {
public:

    ListNode* reverse(ListNode* &head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* temp = curr->next;

        while(curr != NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {


        // base-cases
        if(head1 == NULL) return head2;
        if(head2 == NULL) return head1;

        ListNode* l1 = head1;
        ListNode* l2 = head2;

        int sum = 0;
        int carry = 0;
        int digit = 0;
        ListNode* head = new ListNode(-1);
        ListNode* tail = head;
        while(l1 != NULL && l2!= NULL){
            sum = carry + l1->val + l2->val;
            digit = sum % 10;
            carry = sum / 10;
            ListNode* newNode = new ListNode(digit);
            tail->next = newNode;
            tail = tail->next;

            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1 != NULL){
            sum = carry + l1->val;
            digit = sum%10;
            carry = sum / 10;
            ListNode* newNode = new ListNode(digit);
            tail->next = newNode;
            tail = tail->next;
            l1 = l1->next;

        }

        while(l2 != NULL){
            sum = carry + l2->val;
            digit = sum%10;
            carry = sum / 10;
            ListNode* newNode = new ListNode(digit);
            tail->next = newNode;
            tail = tail->next;

            l2 = l2->next;

        }

        if(carry > 0){

            ListNode* newNode = new ListNode(carry);
            tail->next = newNode;
            tail = tail->next;

        }

        return head->next;

    }
};

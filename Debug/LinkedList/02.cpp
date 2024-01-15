
// my-answer:
ListNode* middleNode(ListNode* head) {
        ListNode* last = head;
        ListNode* first = head;

        while (first != NULL) {
            first = first->next;
            if(first != NULL){ // check NULL reference then move fast
              first = first->next;
              last = last->next;
            }
        }
    
        return last;
 }

---------------------------------------------------------
//alternative-method (official answer)
ListNode* middleNode(ListNode* head) {
        ListNode* last = head;
        ListNode* first = head;

        while (first != NULL && first->next != NULL) { //Fix
            last = last->next;
            first = first->next->next;
        }
    
        return last;
    }

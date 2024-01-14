// lc-234
// tc : O(N)
// sc :O(1)
class Solution {
public:
    ListNode* getMiddle(ListNode* &head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }

        return slow;
    }

    ListNode* reverse(ListNode* &head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = curr->next;

        while(curr != NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;

    }

    bool compare(ListNode* &head1 , ListNode* &head2){
        ListNode* h1 = head1;
        ListNode* h2 = head2;
        while(h2!= NULL){
            if(h1->val != h2->val){
                return false;
            }
            else{
                h1 = h1->next;
                h2 = h2->next;
            }
        }

        return true;
    }

    void print(ListNode* &head){
        ListNode* temp = head;
        while(temp!= NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }cout<<endl;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
            return true;
        }
        ListNode* midNode = getMiddle(head); // tc : O(N) , sc : O(1)
        ListNode* t1 = reverse(midNode->next);// tc : O(N) , sc : O(1)
        bool result =  compare(head,t1);// tc : O(N) , sc : O(1)
        ListNode* t2 = reverse(t1);// tc : O(N) , sc : O(1)
        midNode->next = t2;
        print(head);

        return result;
    }
};

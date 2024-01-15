#include <iostream>
using namespace std;

class ListNode {
   public:
    int data;
    ListNode* next;
    ListNode(int d)
    {
      this->data = d;
      this->next = NULL;
    }
  };

    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        ListNode *fast = head;
        ListNode *slow = head;
        while(slow != NULL && fast != NULL) // NULL check-modified
        {
            fast = fast->next; 
            if(fast!=NULL){ // NULL check added.
              fast = fast->next;
              slow = slow->next;
              
            }
            
            if(fast == slow)
                return true;
        }
        
        return false;
    }

    int main(){
      ListNode* head = new ListNode(20);
      ListNode* first = new ListNode(20);
      ListNode* second = new ListNode(20);
      ListNode* third = new ListNode(20);
      head->next = first;
      first->next = second;
      second->next = third;
      third->next = NULL;
      bool answer = hasCycle(head);
      cout<< answer<<'\n';

    }

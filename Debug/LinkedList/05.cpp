// delete middle node

#include <iostream>
using namespace std;

class ListNode{
  public:
  int data;
  ListNode* next;

  ListNode(int d){
    this->data = d;
    this->next = NULL;
  }
};

ListNode* deleteMiddle(ListNode* head) {
    if ( head == NULL  || head -> next == NULL ) // fix : || condition is correct
        return NULL;
    
    ListNode *slow = head, *fast = head -> next -> next;
    
    while (fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    slow -> next = slow->next->next; // linking changes
    return head;
}
    
void print(ListNode* &head){
  ListNode* temp = head;
  while(temp != NULL){
     cout<<temp->data<< " ";
     temp = temp->next;
  }cout<<endl;
}

int main() {
  ListNode* head = new ListNode(10);
  ListNode* first = new ListNode(20);
  ListNode* second = new ListNode(30);
  ListNode* third = new ListNode(40);
  ListNode* fourth = new ListNode(50);

  head->next = NULL;
  first->next = second;
  second->next = third;
  third->next = NULL;

  print(head);
  ListNode* newHead = deleteMiddle(head);
  print(newHead);

  return 0;
}

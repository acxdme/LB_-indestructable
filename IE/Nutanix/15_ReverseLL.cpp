// Reverse a singly linked-list
// tc : O(N)
// sc : O(1)
#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;

  Node(int data) {
    this->data = data;
    this->next = NULL;
  }
};

Node* reverseLL(Node* head){

  if(head == NULL || head->next == NULL) return head;
  Node* prev = NULL;
  Node* curr = head;
  Node* forward = curr->next;
  while(curr != NULL){
    forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;
  }

  return prev ;
  
}

void printLL(Node* head){
  Node* curr = head;
  while(curr != NULL){
     cout<< curr->data <<" ";
     curr = curr->next;
  }cout<<endl;
  return;
}
int main() {

  Node *head = new Node(10);
  Node *first = new Node(20);
  Node *second = new Node(30);
  // Node *third = new Node(40);
  head->next = first;
  first->next = second;
  // second->next = third;

  printLL(head);

  Node* _head = reverseLL(head);
  
  printLL(_head);

  return 0;
}

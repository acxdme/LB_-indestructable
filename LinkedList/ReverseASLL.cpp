//Reverse a singly linked list 
// tc: O(N)
// sc: O(N) , considering recursion stack
#include <iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* next;

  Node(){
    this->data = 0;
    this->next = NULL;
  }

  Node(int d){
    this->data = d;
    this->next = NULL;
  }

  ~Node(){
    cout<<"Node with value "<<this->data<<" is deleted"<<endl;
  }
};

void print(Node* &head){
 
  Node* temp = head;
  while(temp != NULL){
    cout<<temp->data<<" ";
    temp = temp->next;
  }
    cout<<endl;
  return;
}

Node* reverse(Node* &head){
  Node* prev = NULL;
  Node* curr = head;
  Node* temp = curr->next;

  while(curr != NULL){
    curr->next = prev;
    prev = curr;
    curr = temp;
    if(temp != NULL)
    temp = temp->next;
  }

  return prev;

}

int main() {

  // Node* temp = new Node(10);
  // delete(temp);
  Node* head = NULL;
  Node* tail = NULL;

  Node* first = new Node(1);
  Node* second = new Node(2);
  Node* third = new Node(3);
  Node* fourth = new Node(4);
 
  first->next = second;
  second->next = third;
  third->next = fourth;

  head = first;
  tail = fourth;
  
  print(head);
  Node* _head = reverse(head);
  print(_head);


  return 0;
}

// Deletetion in linked list
// deletion from head
// deletion from tail
// deletion from middle

#include <iostream>
using namespace std;

// delete node in a singly linked list
class Node{
  public:
  int data;
  Node* nxt;

  Node(){
    this->data = 0;
    this->nxt = NULL;
  }

  Node(int d){
    this->data = d;
    this->nxt = NULL;
  }

  ~Node(){
    cout<<"Node with value "<<this->data<<" is deleted."<<endl;
  }
};

void printLinkedList(Node* &head){
  Node* temp = head;
  while(temp != NULL){
    cout<<temp->data<<" ";
    temp = temp->nxt;
  }cout<<endl;
}

int findLength(Node* &head){
  Node* temp = head;
  int i = 0;
  while(temp != NULL){
    i++;
    temp = temp->nxt;
  }cout<<endl;

  return i;
}

void deleteAtPosition(Node* &head , Node* &tail , int position){
  if(head == NULL){
    cout<<"linked list is empty."<<endl;
    return;
  }

  if(position == 1){
    Node* temp = head;
    head = head->nxt;
    temp->nxt = NULL;
    delete(temp);
    return;
  }

  int len = findLength(head);
  
  if(len < position){
    cout<<"Invalid position"<<endl;
    return;
  }
  
  if(position == len){
    int i = 1;
    Node* prev = head;
    while(i < position - 1){
      prev = prev->nxt;
      i++;
    }
   Node* temp = prev ->nxt;
   prev->nxt = NULL;
   tail = prev;
   delete(temp);
   return;
  }
  
  // deletion in the middle
  int i = 1;
  Node* prev = head;
  while(i < position - 1){
     prev = prev->nxt;
     i++;
  }
  Node* temp = prev->nxt;
  prev->nxt = temp->nxt;
  temp->nxt = NULL;
  delete(temp);
  return;

}

int main() {
  // Node* t = new Node(10);
  // delete(t);

  Node* head = NULL;
  Node* tail = NULL;
  Node* first = new Node(11);
  Node* second = new Node(12);
  Node* third = new Node(13);
  Node* fourth = new Node(14);
  first->nxt = second;
  second->nxt = third;
  third->nxt = fourth;

  head = first;
  tail = fourth;
  
  printLinkedList(head);
 
  deleteAtPosition(head,tail,5);

  printLinkedList(head);
  return 0;
}

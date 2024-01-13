// insertion at head
// insertion at tail
// insertion at a given position.
#include <iostream>
using namespace std;

class Node {
  public :
  int data;
  Node* nxt;

  Node(){
    this->data = 0;
    this->nxt = NULL;
  }

  Node(int data){
    this->data = data;
    this->nxt = NULL;

  }

  ~Node(){
    cout<<"destruture called"<<endl;
  }
};

void printLinkedList(Node* &head){
  Node* temp = head;
  while(temp != NULL){
    cout<<temp->data<<" ";
    temp = temp->nxt;
  }cout<<endl;

  return;
}
int findLength(Node* &head){
  Node* temp = head;
  int len = 0;
  while(temp != NULL){
    len++;
    temp = temp->nxt;
  }cout<<endl;

  return len;
}

void insertAtHead(Node* &head ,Node* &tail, int data ) {
   if( head == NULL){
      Node* newNode = new Node(data);
      head = newNode;
      tail = newNode;
      return ;
   }
   Node* newNode = new Node(data);
   newNode->nxt = head;
   head = newNode;
   return;

}

void insertAtTail(Node* &head, Node* &tail,int data){
  if(head == NULL){
       Node* newNode = new Node(data);
       head = newNode;
       tail = newNode;
       return;
  }
  Node* newNode = new Node(data);
  tail ->nxt = newNode;
  tail = newNode;
  return;
}

void insertAtPosition(Node* &head, Node* &tail,int data,int position){
  if(head == NULL){
    Node* newNode = new Node(data);
    head = newNode;
    tail = newNode;
    return;
  }

  if(position == 0) {
    insertAtHead(head,tail,data);
    return;
  }
  int length = findLength(head);

  if(position >= length){
    insertAtTail(head,tail,data);
    return;
  }
  
  int i =1;
  Node* prev = head;
  while(i < position){
    prev= prev->nxt;
    i++;
  }
  Node* newNode = new Node(data);
  newNode->nxt = prev->nxt;
  prev->nxt = newNode;

  return ;

}



int main() {
  // Node *head = new Node(10);
  Node* head = NULL;
  Node* tail = NULL;

  // insertAtHead(head,tail,10);
  // insertAtHead(head,tail,20);
  // insertAtHead(head,tail,35);
  // printLinkedList(head);

  // insertAtTail(head,tail,12);
  // insertAtTail(head,tail,68);
  // insertAtTail(head,tail,46);
  // printLinkedList(head);

  // int ans = findLength(head);
  // cout<<ans<<endl;

  // insertAtPosition(head,tail,44,0);
  // insertAtPosition(head,tail,45,1);
  // insertAtPosition(head,tail,46,1);
  // insertAtPosition(head,tail,49,2);
  // printLinkedList(head);



  return 0;
}

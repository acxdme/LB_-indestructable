#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
};

Node* head;
Node* tail; // tail pointer added as global variable

void insert(int x) { // code converted to insert at tail logic
  if(head == NULL){
    Node* temp = new Node;
    temp->data = x;
    temp->next = NULL;
    head = temp;
    tail = temp;
    return;
  }
  Node* temp = new Node;
  temp->data = x;
  temp->next = NULL;
  tail->next = temp;
  tail = tail->next;

  return;
}

void print() {
  Node* temp = head;
  cout << "List: ";
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main() {
  head = NULL;
  insert(1);
  insert(2);
  insert(3);
  insert(4);
  print();
  return 0;
}

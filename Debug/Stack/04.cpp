// Stack implementation using linked list : Debugging

#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;


    Node(T data) {
        this->data = data;
        next = nullptr;
    }
};

template <typename T>
class Stack {
    Node<T> *head;
    int size;

    public :    
    Stack() {
        head = NULL;
        size = 0;
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
        return head == NULL;
    }
    
    void push(T element) {
        Node<T>* temp = new Node<T>(element);
        temp->next = head;
        head = temp;
        size++;
        return;
    }
    
    T pop() {
       // check if stack is empty
        if(head == NULL){ // fix : stack underflow condition
          cout<<"stack underflow"<<endl;
          return -1;
        }
        T data = head->data;
        head = head->next;
        size--;
        return data;   
    }
    
    T top() {
       if(head == NULL){  // fix : stack underflow condition
        return -1;
       }
        return head->data;
    }    
};

int main() {
  Stack<int> s;
  s.push(10);
  s.push(20);
  s.pop();
  cout<< " top " << s.top();
  return 0;
}

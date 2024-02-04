// stack creation using array

#include <iostream>
using namespace std;

class stack {

  private :
   int top;
   int* arr;
   int size;

   public:

   stack(int size){
     this->top = -1;
     this->arr = new int(size);
     this->size = size;
   }

   void push(int data){
     // check for overflow
     if(size - top > 1){
        top++;
        arr[top] = data;
     }else{
       cout << "Stack overflow" << endl;
     }

   }

   void pop(){

    // check underflow
    if(top != -1){
      arr[top] = 0;
      top--;
    }
    else{
      cout<<"Stack underflow"<<endl;
    }

   }

   int peek(){
    // check underflow
    if(top != -1){
      return arr[top];
    }
    else{
      cout<<"Stack underflow"<<endl;
    }
       
   }

   bool isEmpty(){
    if(top == -1){
      return true;
    }
     return false;

   }

   int getSize(){

    return top + 1;
    
   }

   void print(){
    
    for(int i =0 ;i < size ;i++ ){
      cout<< arr[i] << " ";
    }cout<<endl;
   }
  
};

int main() {
  stack* s = new stack(5);

  s->push(10);
  s->print();
  cout<<"Stack size : "<<s->getSize() << endl;
  s->push(20);
  s->print();
  s->push(30);
  s->print();
  s->push(40);
  s->print();
  s->push(50);
  s->print();
  cout<<"Stack size : "<<s->getSize() << endl;
  cout<<"Stack top : "<<s->peek() << endl;

  // s->pop();
  // s->print();
  // s->pop();
  // s->print();
  // s->pop();
  // s->print();
  // s->pop();
  // s->print();
  // s->pop();
  // s->print();
  // s->pop();
  // s->print();
  cout<<"stack empty " << s->isEmpty()<<endl;


  return 0;
}

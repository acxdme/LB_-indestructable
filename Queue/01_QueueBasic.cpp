// Implementing queue using class based approach.

#include <iostream>
using namespace std;

using namespace std;
class queue{
  public:
   int* arr;
   int size;
   int front = 0;
   int rear = 0;

   queue(int n){
    this->size = n;
    this->arr = new int[n];
   }

   void push(int value){
    // check if queue is full
     if(rear == size){
       cout<<"Queue is full"<<endl;
       return;
     }
     else{
       arr[rear] = value;
       rear++;
       return;
     }
   }
    
    void pop(){
      // check if queue is empty
      if(front == 0 && rear == 0){
        cout<<"Queue is empty"<<endl;
        return;
      }
      else if(front == rear){
         arr[front] = -1;
         front = 0 ;
         rear = 0;
         return;
      }
      else{
        arr[front] = -1;
        front++;
      }
      
    }
};

void print(queue* &q, int &size){
  for(int i =0 ;i<size;i++){
    cout<<q->arr[i] <<" ";
  }cout<<endl;
}


int main() {
  int size = 6;
  queue* q = new queue(size);

  print(q,size);

  q->push(10);
  q->push(20);
  q->push(30);
  q->push(40);
  q->push(50);
  q->push(60);
  print(q,size);

  q->pop();
  q->pop();
  q->pop();
  q->pop();
  q->pop();
  q->pop();
  q->pop();
 
  print(q,size);





  return 0;
}

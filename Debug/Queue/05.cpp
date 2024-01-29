// stack implementation using two queue

#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {
        
    }
    
    void push(int x) {
        while(!q1.empty()){
            int f1 = q1.front();// fix : store front then pop
            q1.pop();
            q2.push(f1);
        }

        q1.push(x);

        while(!q2.empty()){
            int f2 = q2.front(); // fix : store front then pop
            q2.pop();
            q1.push(f2);
        }

    }
    
    int pop() {
        if(empty()){ // edge-case
          return -1;
        }
        int ans = q1.front(); 
        q1.pop();
        return ans;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }

    void print(){
      queue<int> temp = q1;
      while(!temp.empty()){
        cout << temp.front();
        cout<<endl;
        temp.pop();
      }
    }
};

int main() {
  MyStack* s = new MyStack();
  int popVal = s->pop();
  cout<<popVal<<endl;
  s->push(1);
  s->push(2);
  s->print();

  cout<<"after pop"<<endl;
  s->pop();
  s->pop();
  s->pop();
  s->pop();
  s->pop();
  s->print();
  cout<<popVal<<endl;
  s->push(4);
  s->push(5);
  s->push(6);
  s->print();
  cout<<"top val " <<s->top()<<endl;


  return 0;
}

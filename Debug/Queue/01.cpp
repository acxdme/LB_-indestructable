// debugging in queue implementation using 2 stacks

#include <iostream>
#include<stack>
using namespace std;

class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        while (!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int t= s2.top();
        s2.pop(); // fix , we need to pop the element.
        while (!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return t;
    }
    
    int peek() {
        while (!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int t= s2.top();
				// s2.pop();  popping is not required.
        while (!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return t;
    }
    
    bool empty() {
        return s1.empty();
    }

    void print(){

    }
};

int main() {
   MyQueue q;
   q.push(1);
   q.push(2);
   q.push(3);
  return 0;
}

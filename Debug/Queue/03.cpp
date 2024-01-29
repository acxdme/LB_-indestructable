#include <iostream>
#include <queue>
using namespace std;

void reverseQueue(queue<int> &q) {
    //base-case
    if(q.empty()){ // fix : base case added
      return;
    }
    int front = q.front(); // fix :  front stored in a variable
    q.pop();
    reverseQueue(q);
    q.push(front); // fix : pushed front variable
}
void print(queue<int>  q){
  while(!q.empty()){
    int front = q.front();
    q.pop();
    cout<<front<<" ";
  }cout<<endl;

  return;
}

int main() {
  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);
  print(q);

  reverseQueue(q);

  print(q);




  return 0;
}

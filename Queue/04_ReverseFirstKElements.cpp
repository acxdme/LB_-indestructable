// gfg - https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1
// tc : O(N)
// sc : O(k) 

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
       
       int totalSize = q.size();
       // remainging Size = N - K
       int remainingSize = totalSize - k;
       
       stack<int> stk;
       int i = 0;
       // insert first k elements into stack 
       while( i < k){
           
           int front = q.front();
           q.pop();
           
           stk.push(front);
           
           i++;
       }
       
       // insert the stacked elements into queue
       while(!stk.empty()){
           int top = stk.top();
           stk.pop();
           
           q.push(top);
       }
       
       i= 0;
       // put the N-K elements from front to q's back
       while(i < remainingSize){
           int front = q.front();
           q.pop();
           
           q.push(front);
           i++;
       }
       
       
       return q;
       
    }
};

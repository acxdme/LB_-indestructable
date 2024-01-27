// gfg -https://www.geeksforgeeks.org/problems/queue-reversal/1
// TC : O(N)
// SC : O(N)

// method -1 :  using stack to reverse the queue
class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        // edge-case
        if(q.size() <= 1) {
            return q;
        }
        
        //initialize stack st
        stack<int> st;
        
        // insert q data into stack
        while(!q.empty()){
            int front = q.front();
            q.pop();
            st.push(front);
        }
        // put stack data back into q
        while(!st.empty()){
            int top = st.top();
            st.pop();
            q.push(top);
        }
        
        return q;
    }
};

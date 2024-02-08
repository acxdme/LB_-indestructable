class Solution{
public:

    void insertAtBottom(stack<int>& s,int target){
        //base case - insert target
        if(s.empty()){
            s.push(target);
            return;
        }
        
        // get top & pop
        int top = s.top();
        s.pop();
        
        // recursive call
        insertAtBottom(s,target);
        
        // insert top
        s.push(top);
    }
    void Reverse(stack<int> &st){
        
        
        //base-case
        if(st.empty()){
            return;
        }
        
        // get top & pop
        int top = st.top();
        st.pop();
        
        // recursive call
        Reverse(st);
        
        // insertAtBottom
        insertAtBottom(st,top);
    }
};

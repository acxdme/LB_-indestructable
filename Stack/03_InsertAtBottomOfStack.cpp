// gfg - https://www.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1
// tc : O(N)
// sc :  O(N)

class Solution{
public:
    void insertHelper(stack<int> &st, int &target){
        
        //base-case 
        if(st.empty()){
           st.push(target);
           return ;
        }
        
        int top = st.top();
        st.pop();
        
        insertHelper(st,target);
        
        st.push(top);
    }
    stack<int> insertAtBottom(stack<int> st,int X){
        
        insertHelper(st,X);
        return st;
        
    }
};

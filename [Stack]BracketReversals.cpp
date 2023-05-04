int countRev (string s)
{
    stack<char> st;
    int close = 0 ;
    int open = 0;
    
    for( char c : s){
        if(c == '}'){
            if(!st.empty() && st.top() == '{'){
                st.pop();
            }else{
                
            st.push(c);
            }
        }else{
            st.push(c);
        }
        
    }
    
    while(!st.empty()){
        char top = st.top();
        st.pop();
        if(top == '{') open++;
        else close++;
    }
    
    if((close + open) & 1 )  return -1;
    
    return ((open+1)/2 + (close+1)/2);
}

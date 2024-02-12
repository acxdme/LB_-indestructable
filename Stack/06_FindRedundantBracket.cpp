// gfg - https://www.geeksforgeeks.org/problems/expression-contains-redundant-bracket-or-not/1
// tc :  O(N) , time for traversal 
// sc :  O(N) , auxillary space for stack taken

class Solution {
  public:
    int checkRedundancy(string s) {
        
        bool flag = false;
        int n = s.size();
        stack<char> st;
        
        for(int i = 0 ; i < n ; i++){
            if(s[i] == '('){
                st.push(s[i]);
            }
            else if(s[i] == '+'  || s[i] == '-' || s[i] == '*' || s[i] == '/'){
                st.push(s[i]);
            }
            else if( s[i] == ')'){
                
                while(!st.empty() && st.top() != '('){
                    flag = true;
                    st.pop();
                    
                }
                if(st.top() == '(' && !flag){ // redundant bracket found
                    return 1;
                }else{
                    st.pop(); // pop the correct opening bracket
                    flag = false;
                }
            }
            else{
                continue;
            }
                
        }
        
        return 0;
       
    }
};

/*
 Time complexity : O(N)
 Space complexity : O(N)
*/
int celebrity(vector<vector<int> >& M, int n) 
    {
        // elimination
         stack<int> st;
         for(int i = 0 ;i < n; i++){
             st.push(i);
         }
         
         while(st.size() > 1){
             int t1 = st.top();
             st.pop();
             int t2 = st.top();
             st.pop();
             
             if(M[t1][t2] == 0 ){
                 st.push(t1);
             }else{
                 st.push(t2);
             }
             
         }
        
        //verification
        int person = st.top();
        int count = 0;
        for(int i = 0 ; i < n ;i++){
            if(M[person][i] == 1) return -1;
            if(M[i][person] == 1) count++;
        }
        
        if(count == n-1) return person;
        
        return -1;
    }

// tc : O(N)
// sc : O(1)
// lc-28

    int strStr(string haystack, string needle) {
        int res =  -1;
        int n = haystack.size();
         auto it =  haystack.find(needle);
         if(it != string::npos){
             res= it;
         }
        

        return res;
    }

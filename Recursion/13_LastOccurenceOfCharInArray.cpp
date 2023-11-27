// time-complexity : O(N)
// space complexity : O(1)

   int ans = -1;
   int n = s.size();
   for(int i = n - 1; i >= 0 ; i--){
       if(s[i] == p){
           ans = i;
           break;
       }
   }
   
   return ans;
   
   
}

// recursive approch
// time-complexity : O(N)
// space-complexity : O(N) , considering recursion stack


    int isCharFound(string &s , char &p , int i){
        if(i < 0) return -1;
        
        if(s[i] == p) return i;
        
        int ans = isCharFound(s,p,i-1);
        
        return ans;
    }
    
    int LastIndex(string s, char p){
       int ans = -1;
       int n = s.size();
       ans = isCharFound(s,p,n-1);
       
       return ans;
       
       
    }

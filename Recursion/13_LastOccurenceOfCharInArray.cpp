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

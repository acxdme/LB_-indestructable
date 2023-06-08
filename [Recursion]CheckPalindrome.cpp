/*
 Time-complexity : O(N)
 Space-complexity : O(N)
*/

class Solution {
public:

    bool checkPalindrome(string& ns,int start ,int end){
        if(start >= end) return true;

        if(ns[start] != ns[end]) return false;

        bool result = checkPalindrome(ns,start+1,end-1);

        return result;

    }
    bool isPalindrome(string s) {
     string ns;
     for (auto& x : s) {
        x = tolower(x);
        if( (x >= 'a' && x <= 'z') || (x >= '0' && x <='9')){
            ns += x;
        }
     }
       cout<<ns<<endl;
       int start = 0;
       int end = ns.length()-1;
       bool ans = checkPalindrome(ns,start,end);

      return ans;

        
    }
};

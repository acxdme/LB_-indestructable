// tc : O(N)
// sc : O(1)
// lc-917

class Solution {
public:
   static bool isValidChar(char x){
       if((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z')){
           return true;
       }

       return false;
   }
    string reverseOnlyLetters(string s) {
        int start = 0;
        int end = s.length() -1;

        while(start <= end){
            if(isValidChar(s[start]) && isValidChar(s[end])){
                swap(s[start] ,s[end]);
                start++;
                end--;
            }
            else if(isValidChar(s[start]) && !isValidChar(s[end])){
                end--;
            }
            else if(!isValidChar(s[start]) && isValidChar(s[end])){
                start++;
            }
            else{
                start++;
                end--;
            }
        }

        return s;
        
    }
};

// lc-5
// tc : O(N*N) 
// sc : O(N)

class Solution {
public:

    string findPalindrome(string &s , int left ,int right){
        int n = s.length();
        string ans = "";
        while(left >=0 && right < n){
            if(s[left] == s[right]){
                ans = s.substr(left,right-left+1);
                left--;
                right++;
            }
            else{
                return ans;
            }
        }
        return ans;
    }
    string longestPalindrome(string s) {

        int center = 0;
        int n = s.length();
        string ans = "";
        for(center = 0 ; center < n; center++){
         string evenPalindrome = findPalindrome(s,center,center+1);
         string oddPalindrome = findPalindrome(s,center,center);
         if(evenPalindrome.length() >  oddPalindrome.length())
         {
             if(evenPalindrome.length() > ans.length()){
                 ans = evenPalindrome;
             }
         }
         else{
             if(oddPalindrome.length() > ans.length()){
                 ans = oddPalindrome;
             }
         }
        }
        
        return ans;
    }
};

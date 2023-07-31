//leetcode-3
// must optimize the code (thoda aur better likhna hai)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       int startIndex = 0 ;
       int n = s.length();
       int maxLen = INT_MIN;

       unordered_map<char,int> sMap;

       for(int i =0 ; i < n;i++){
           sMap[s[i]]++;
           if(sMap[s[i]] > 1 ){
               maxLen = max(maxLen,i-startIndex);
               while(sMap[s[i]] > 1){
                   sMap[s[startIndex]]--;
                   startIndex++;
               }
               
           }
       }
        maxLen = max(maxLen, n-startIndex);
         if(maxLen == INT_MIN) return s.length();
        return maxLen;
    }
};


---------------------------------------------------------------------------------------------------

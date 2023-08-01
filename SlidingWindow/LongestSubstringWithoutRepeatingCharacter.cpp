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

// more cleaner solution , always remember to optimize

        unordered_map<char, int> counts; // Frequencies of chars in the window
        int res = 0;
        int i = 0; // Left pointer
        for(int j = 0; j < s.length(); j++){
            counts[s[j]] ++; // Add right pointer to window 
            while(counts[s[j]] > 1){ // While the element at right pointer created a repeat
                counts[s[i++]] --; // While condition not valid, remove element at left pointer from window by decreasing its count, and then increment left pointer. In this case, it is while s[j] is a duplicate (we will stop after removing the duplicate copy of s[j]).
            } // Now the condition is valid
            res = max(res, j-i+1); // Update global max with the length of current valid substring
        }
        return res;

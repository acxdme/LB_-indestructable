// tc :  O(N^2)
// sc : O(1)
// lc - 647

class Solution {
public:
    int palindromeCounter(string& s , int left , int right){

        int count = 0;
        while(left >=0 && right < s.length() && s[left] == s[right]){
            count++;
            left--;
            right++;
        }

        return count;
    }
    int countSubstrings(string s) {
        int totalCount = 0;
        int n = s.length();

        for(int center = 0 ; center < n ;center++){
            // call for even 
            int evenCount = palindromeCounter(s,center,center+1);

            // call for odd
            int oddCount = palindromeCounter(s,center,center);

            totalCount += (evenCount +oddCount);
        }

        return totalCount;
        
    }
};

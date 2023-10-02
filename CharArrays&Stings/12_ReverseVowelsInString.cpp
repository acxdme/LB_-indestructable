// tc : O(N)
// sc : O(1)
// lc-345

class Solution {
public:
    bool isVowel(char &x){
        const string vowels ="aeiouAEIOU";
        if(vowels.find(x) != string::npos){
            return true;
        }

        return false;
    }
    string reverseVowels(string s) {
        int start = 0;
        int end = s.length() -1;
        while(start <= end){
            if(isVowel(s[start]) && isVowel(s[end])){
                swap(s[start],s[end]);
                start++;
                end--;
            }
            else if(!isVowel(s[start])){
                start++;
            }
            else{
                end--;
            }
        }

        return s;
    }
};

// tc : O(N)
// sc : O(1) , since considering only 26 small englist alphabets.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
// typically using all the original letters exactly once.
// lc-242
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n != m ) return false;
        int arr[26] = {0};
        for(int i = 0 ; i <n ; i++){
            arr[s[i] - 'a']++; // increment

        }
        for(int i =0 ; i< m ;i++){
            arr[t[i] - 'a']--; // decrement
        }

        for(int i =0 ; i< 26; i++){
            if(arr[i] != 0) return false; // check non-null values
        }cout<<endl;

        return true;
    }
};

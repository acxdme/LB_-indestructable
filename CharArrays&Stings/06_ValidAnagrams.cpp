// tc : O(N)
// sc : O(1) , since considering only 26 small englist alphabets.
// lc-242
/**
     An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
     typically using all the original letters exactly once.
**/

// approach -1 (sorting)

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};


// approach-2 (hashmap)
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

// approach-3 (hashTable using array)

class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[26] = {0};
        
        // Count the frequency of characters in string s
        for (char x : s) {
            count[x - 'a']++;
        }
        
        // Decrement the frequency of characters in string t
        for (char x : t) {
            count[x - 'a']--;
        }
        
        // Check if any character has non-zero frequency
        for (int val : count) {
            if (val != 0) {
                return false;
            }
        }
        
        return true;
    }
};

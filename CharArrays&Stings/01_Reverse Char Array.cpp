// tc : O(N)
// sc : O(1)
// lc - 344


class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0 ;
        int j = s.size() - 1;
        while(i < j){
            swap(s[i],s[j]);
            i++; j--;
        }
    }
};

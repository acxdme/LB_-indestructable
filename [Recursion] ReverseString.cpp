/*
 Time complexity :O(N)
 Leetcode 344
**/


class Solution {
public:

    void solve(vector<char>& s , int start ,int end){
        if(start >= end) return;

        swap(s[start],s[end]);


        solve(s,start+1,end-1);

    }
    void reverseString(vector<char>& s) {

        int start =0;
        int end = s.size()-1;
        solve(s,start,end);
        
    }
};

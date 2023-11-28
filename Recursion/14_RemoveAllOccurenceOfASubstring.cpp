// time-complexity : O(N^2)
// space-complexity : O(N) , considering recursive stack
// lc -1910
class Solution {
public:
    void helper(string &s , string &part){
        if(s.find(part) == string::npos){
            return;
        }

        int pos = s.find(part);
        helper(s.erase(pos,part.size()),part);
    }
    string removeOccurrences(string s, string part) {
        helper(s,part);

        return s;
    }
};

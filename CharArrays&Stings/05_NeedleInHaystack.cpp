// tc : O(N)
// sc : O(1)
// lc-28

// method-1
    int strStr(string haystack, string needle) {
        int res =  -1;
         auto it =  haystack.find(needle);
         if(it != string::npos){
             res= it;
         }
        

        return res;
    }


// method-2
class Solution {
public:
    int strStr(string haystack, string needle) {
        int result = -1;
        if(needle.size() > haystack.size()) return result;
        for(int i = 0 ; i <= haystack.size() - needle.size(); i++){
            if(haystack.substr(i,needle.size()) == needle){
                result = i;
                break;
            }
        }

        return result;
    }
};

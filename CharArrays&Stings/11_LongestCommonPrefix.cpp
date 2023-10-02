// tc : O(N*M) , N = total number of strings , M = size of the reference string
// sc : O(1)
// lc-14

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       string refString = strs[0];
       int totalStrings = strs.size();

       string res = "";

       for(int k = 1 ; k <= refString.length(); k++)
       {
          string compare = refString.substr(0,k);
           for(int i = 1 ;i < totalStrings ; i++ ){
               if(compare != strs[i].substr(0,k)){
                   return res;
               }
           }
           res = compare;
       }
        

        return res;
    }
};

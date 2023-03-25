class Solution {
public:

    void solve(vector<string> &ans , string digits,int index,string output,unordered_map<int,string> &mapping){
        //Base-case
        if(index >= digits.length()){
            ans.push_back(output);
        }
        int digit = digits[index] - '0';
        
        for(auto letter : mapping[digit]){
            // add letter to output string
            output.push_back(letter);
            //recursion
            solve(ans,digits,index+1,output,mapping);
            //backtracking
            output.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {

        vector<string> ans;
        if(digits.length() == 0) return ans;
        
        unordered_map<int,string> mapping ;
        mapping[2] = "abc";
        mapping[3] = "def";
        mapping[4] = "ghi";
        mapping[5] = "jkl";
        mapping[6] = "mno";
        mapping[7] = "pqrs";
        mapping[8] = "tuv";
        mapping[9] = "wxyz";
        string output = "";
        solve(ans,digits,0,output,mapping);

        return ans;
        
    }
};

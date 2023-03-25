class Solution {
public:

    void  solve(int n , int open , int close , vector<string> &ans, string output){
        if(open == 0 && close == 0 )
        {
            ans.push_back(output);
            return;
        }

        if(open > 0 ){
            
            solve(n,open-1,close,ans,output+"(");
        }

        if( close > open){
            solve(n,open,close-1,ans,output + ")");
        }

    }

    vector<string> generateParenthesis(int n) {

        int open = n;
        int close = n;
        vector<string> ans;
        string output = "";

        solve(n,open,close,ans,output);

        return ans;
        
    }
};

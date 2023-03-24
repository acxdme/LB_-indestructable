class Solution {
public:

    bool isSafe(vector<vector<char>> &board ,int row ,int col ,int n){
        int i = row;
        int j = col;

        while(j >= 0){
            if(board[i][j] == 'Q') return false;
            j--;
        }

        i = row;
        j= col;

        while(i >=0 & j >=0 ){
            if(board[i][j] == 'Q') return false;
            i--;
            j--;
        }

        i = row;
        j = col;

        while(i<n && j>=0){
            if(board[i][j] == 'Q') return false;
            i++;
            j--;
        }


        return true;

    }

    void populateAns(vector<vector<char>> &board,vector<vector<string>> & ans){

        vector<string> t;
        for(auto row : board ){
            string output = "";
            for(auto it : row){
                output.push_back(it);
            }
            t.push_back(output);
        }

        ans.push_back(t);
    }

    void solve(int n,vector<vector<char>> &board ,int col,vector<vector<string>> &ans){
        //Base-case
        if(col >= n) {
            populateAns(board,ans);
            return ;

        }

        for(int i= 0 ; i< n ; i++ ){

            if( isSafe(board,i,col,n)){

            // queen rakho
            board[i][col] = 'Q';

            //recursion
            solve(n,board,col+1,ans);
            
            //back-tracking
            board[i][col] = '.';

            }

        }
    }
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<char>> board(n,vector<char>(n,'.'));
        vector<vector<string>> ans;

        solve(n,board,0,ans);

        return ans;
        
    }
};

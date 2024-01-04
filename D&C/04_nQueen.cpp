//tc : n!
// sc : o(n*n)

class Solution {
public:
    bool isSafe(vector<vector<char>>& board ,int n , int row ,int col){
        
       for(int i = col -1; i >= 0 ;i-- ){
           if(board[row][i] == 'Q') return false;
       }

       int i = row-1;
       int j = col-1;
       while(i >=0 && j >=0){
           if(board[i][j] == 'Q' ) return false;
           i--;
           j--;
       }
       int a = row + 1;
       int b = col -1;

       while(a < n && b >=0){
           if(board[a][b] == 'Q') return false;
           a++;
           b--;
       }

       return true;
    }
    void solve(vector<vector<char>>& board,int &n,int col,vector<vector<string>>& result){
        //base-case
        if(col >= n){
            vector<string> output;
            for(int i= 0 ;i < n ; i++){
                string temp ="";
                for(int j = 0 ; j< n;j++){
                    temp += board[i][j];
                }
                output.push_back(temp);
            }
            result.push_back(output);
            return;
        } 

        for(int row = 0 ; row < n ; row++){
            if(isSafe(board,n,row,col)){
                board[row][col] = 'Q';
                solve(board,n,col+1,result);
                //backtracking
                board[row][col] ='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<vector<char>> board(n,vector<char>(n,'.'));
        solve(board,n,0,result);
        return result;
    }
};

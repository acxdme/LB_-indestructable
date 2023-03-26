class Solution {
public:

    bool isSafe(vector<vector<char>> &board ,int k ,int i , int j){
        for(int col = 0 ; col < 9 ; col++){
            if(board[i][col] == 'k') return false;
        }

        for(int row =0 ; row < 9 ; row++){
            if(board[j][row] == 'k') return false;
        }

        for(int ind =0 ;ind < 9 ;ind++){
            if(board[3*(i/3) + ind/3][3*(j/3) + ind%3] == 'k')
            return false;
        }

        return true;
    }

    bool solve(vector<vector<char>> &board , int n){

        for(int i =0 ; i<n ;i++){
            for(int j=0 ;j<n;j++){
                if(board[i][j]=='.'){
                    for(char k = '1' ;  k < '9' ; k++){
                        if(isSafe(board,k,i,j)){
                            board[i][j] = k;
                        }
                        else{
                            return false;
                        }

                        return false;
                    }
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int n = 9;
         bool solver = solve(board,n);
        
    }
};

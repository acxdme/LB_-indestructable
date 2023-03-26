class Solution {
public:

    bool isSafe(vector<vector<char>> &board ,int value,int row , int col){
        int n = board.size();

        for(int i=0; i<n; i++) {
            //row check
            if(board[row][i] == value)
                return false;
            
            //col check
            if(board[i][col] == value) 
                return false;

            //3*3 box check
            if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)] == value) 
                return false;
        }

        return true;
    }

    bool solve(vector<vector<char>> &board , int n){

        for(int i =0 ; i<n ;i++){
            for(int j=0 ;j<n;j++){
                //check for empty cell
                if(board[i][j]=='.'){
                    // try to fill a value from 1 to 9
                    for(char k = '1' ;  k <= '9' ; k++){
                        // check if placement is safe or not.
                        if(isSafe(board,k,i,j)){
                            board[i][j] = k;
                            bool remainingSolution = solve(board,n);
                            if(remainingSolution){
                                return true;
                            }
                            else{
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
         int n = board.size();
         bool solver = solve(board,n);
        
    }
};

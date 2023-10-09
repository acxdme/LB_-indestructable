// tc : O(rows * cols)
// sc : O(rows * cols)
// lc - 6

class Solution {
public:
    string convert(string s, int numRows) {
        int rows = numRows;
        if(rows == 1) return s;
        int cols = s.size();
        char mat[rows][cols];
        memset(mat,'0',sizeof(mat));
        int i = 0 ; int r = 0 ; int c = 0;
        while(i < cols){
            if( (c & 1) && rows > 2  ){ // odd row
              r= rows -2;
              while(r >= 1 && i < cols){
                  mat[r][c] = s[i];
                  i++;
                  r--;
              }
            }
            else{ //even row
              while( r < rows && i < cols ){
                    mat[r][c] = s[i];
                    i++;
                    r++;
              }
            }
            r = 0;
            c++;

        }
         string res = "";
        for( i = 0 ; i < rows ;i++){
            for(int j = 0 ; j < cols ;j++){
                if(mat[i][j] != '0'){
                    res += mat[i][j];
                }
            }
        }

        return res;
        
    }
};

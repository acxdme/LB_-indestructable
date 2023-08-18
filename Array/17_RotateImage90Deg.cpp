// lc- 48
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        // transpose
         for(int i =0 ; i < rows ; i++){
             for(int j = i+1 ; j < cols ;j++){
                 swap(matrix[i][j],matrix[j][i]);
             }
         }
        // reverse row wise
        for(int i = 0 ; i < rows ; i++){
            int start = 0;
            int end = cols -1;
            while(start < end){
                swap(matrix[i][start],matrix[i][end]);
                start++;
                end--;
            }
        }
        

    }
};

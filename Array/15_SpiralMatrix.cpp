// time complexity : O(M*N)
// space complexity : O(1) , no additional space required.
// lc-54

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int startRow = 0;
        int endRow = matrix.size() -1;

        int startCol = 0;
        int endCol = matrix[0].size() - 1;

        vector<int> ans;
        while(startRow <= endRow && startCol <= endCol){
            for(int i= startCol ; i <= endCol ; i++){
                // cout<<matrix[startRow][i]<<" ";
                ans.push_back(matrix[startRow][i]);
            }
            startRow++;
            if(startRow > endRow) break;

            for(int j = startRow ; j <= endRow ; j++){
                // cout<<matrix[j][endCol]<<" ";
                ans.push_back(matrix[j][endCol]);
            }
            endCol--;
            if(endCol < startCol) break;

            for(int k = endCol  ; k >= startCol ; k--){
                // cout<<matrix[endRow][k]<<" ";
                ans.push_back(matrix[endRow][k]);
            }
            endRow--;
            if(endRow < startRow) break;

            for(int l = endRow ; l >= startRow ; l--){
                // cout<<matrix[l][startCol]<<" ";
                ans.push_back(matrix[l][startCol]);
            }
            startCol++;
            if(startCol > endCol) break;
        }


        return ans;
        
    }
};

// lc-867
// TC : O(N^2)
// SC  : O(1) , no extra space required.

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {

        int r = matrix.size();
        int c = matrix[0].size();

        vector<vector<int>> res(c,vector<int>(r,-1));
        for(int i =0 ;i < r ;i++){
            for(int j =0 ; j < c ; j++){
                res[j][i] = matrix[i][j];
            }
        }

        return res;
    }
};

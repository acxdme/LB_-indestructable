// time complexity : O(log(m*n))
// lc-74

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int size = m * n;
        int start = 0 ;
        int end = size -1;
        int mid = start + (end - start)/2;
        bool ans = false;
        while(start <= end){
            int r = mid / m;
            int c = mid % m;
            if(matrix[r][c] == target){
                ans = true;
                break;
            }
            else if(matrix[r][c] > target){
                end = mid -1;
            }
            else{
                // matrix[r][c] < target
                start = mid +1;
            }

            mid = start + (end -start)/2;

        }

        return ans;
        
    }
};

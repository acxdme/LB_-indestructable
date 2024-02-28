// lc - 64 
// Minimum path sum
// unable to get the top down approach from my logic
class Solution {
public:
    void findMinPathRecursive(vector<vector<int>>& grid, int& r, int& c,
                              int srcX, int srcY, vector<vector<int>>& result) {

        // base-case : Out of bound
        if (srcX >= r || srcY >= c) {
            return;
        }

        int top = INT_MAX;
        int left = INT_MAX;
        if (srcX - 1 >= 0)
            top = result[srcX - 1][srcY];
        if (srcY - 1 >= 0)
            left = result[srcX][srcY-1];

        // base-case : Reached destination
        if (srcX == r - 1 && srcY == c - 1) {
            result[srcX][srcY] = grid[srcX][srcY] + min(top, left);
            return;
        }

        if (srcX == 0 && srcY == 0) {
            result[srcX][srcY] = grid[srcX][srcY];
        } else {
            result[srcX][srcY] = grid[srcX][srcY] + min(top, left);
        }

        findMinPathRecursive(grid, r, c, srcX + 1, srcY, result);
        findMinPathRecursive(grid, r, c, srcX, srcY + 1, result);
        return;
    }
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        if(r == 1 && c == 1) return grid[0][0];
        vector<vector<int>> result = grid;

        // Recursive approach
        findMinPathRecursive(grid, r, c, 0, 0, result);

        return result[r - 1][c - 1];
    }
};

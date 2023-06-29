#include <vector>
class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& grid) {
        grid[row][col] = '0';

        //neeche
        if (row + 1 < grid.size() && grid[row + 1][col] == '1') {
            dfs(row + 1, col, grid);
        }
        //upar
        if (row - 1 >= 0 && grid[row - 1][col] == '1') {
            dfs(row - 1, col, grid);
        }
        //left
        if (col - 1 >= 0 && grid[row ][col-1] == '1') {
            dfs(row, col-1, grid);
        }
        //right
        if (col + 1 < grid[0].size() && grid[row ][col+1] == '1') {
            dfs(row , col+1, grid);
        }


    }
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // create a copy of the original vector
        vector<vector<char>>test = grid;
        int count = 0;
            for (int row = 0;row < rows;row++) {
                for (int col = 0; col < cols; col++)
                {
                if (test[row][col] == '1') {
                        dfs(row, col,test);
                        count++;
                    }
                }
            }
        return count;
    }
};

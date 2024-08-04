// lc-463
// T.C : O(N*M)
// S.C : O(1)

class Solution {
public:
    int getPerimeter(vector<vector<int>>& grid, int sr, int sc) {
        int value = 0;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int newX = sr + dx[i];
            int newY = sc + dy[i];
            if (newX >= 0 && newX < grid.size() && newY >= 0 &&
                newY < grid[0].size() && grid[newX][newY] == 1) {
                continue;
            } else {
                value++;
            }
        }

        return value;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int perimeter = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    perimeter += getPerimeter(grid, i, j);
                }
            }
        }

        return perimeter;
    }
};

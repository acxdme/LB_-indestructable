// lc -996
// tc : O(N*M)
// sc : O(N*M)

// based on the pattern of multisource bfs , similar to burning tree.
class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int newX, int newY) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (newX < 0 || newX >= rows) {
            return false;
        }
        if (newY < 0 || newY >= cols) {
            return false;
        }
        if (grid[newX][newY] != 1) {
            return false;
        }

        return true;
    }
    int traverse(vector<vector<int>>& grid, int rows, int cols) {
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j}); // push all rotten oranges in queue
                }
            }
        }

        int counter = 0;

        while (!q.empty()) {
            int t = q.size();
            bool nextRotten = false;
            for (int i = 0; i < t; i++) {
                pair<int, int> front = q.front();
                q.pop();
                int dx[] = {-1, 0, 1, 0};
                int dy[] = {0, -1, 0, 1};

                for (int i = 0; i < 4; i++) {
                    int newX = front.first + dx[i];
                    int newY = front.second + dy[i];

                    if (isValid(grid, newX, newY)) {
                        nextRotten = true;
                        q.push({newX, newY});
                        grid[newX][newY] = 2; // visited/rotten
                    }
                }
            }
            if (nextRotten)
                counter++;
        }

        return counter;
    }

    bool validateGrid(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        bool validGrid = true;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) { // fresh found
                    validGrid = false;
                    return validGrid;
                }
            }
        }

        return validGrid;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        int time = traverse(grid, rows, cols);

        // check if everything is rotten
        if (!validateGrid(grid)) {
            return -1;
        }
        return time;
    }
};

/*
 Multisource bfs
*/
  
class Solution {
public:
    int findRottenOranges(vector<vector<int>>& grid ){

        int rows = grid.size();
        int cols  = grid[0].size();
        int ans  = 0;
        queue<pair<pair<int,int>,int>> q;
        
        for(int row = 0 ; row < rows ; row ++){
            for(int col = 0 ; col < cols ; col ++){
                if(grid[row][col] == 2){
                    q.push({{row,col},0});
                }
            }
        }

        while(!q.empty()){
            auto frontNode = q.front();
            q.pop();
            int row = frontNode.first.first;
            int col = frontNode.first.second;
            int time = frontNode.second;
            ans = max(time,ans);
            int dx[] = {0,1,0,-1};
            int dy[] = {-1,0,1,0};

            for(int i= 0 ;i < 4 ;i++){
                if(row + dx[i] >= 0  && row + dx[i] < rows && col +  dy[i] >= 0 && col + dy[i] < cols && grid[row+dx[i]][col+dy[i]] == 1){
                     grid[row+dx[i]][col+dy[i]] = 2;
                     q.push({{row+dx[i],col+dy[i]},time+1});
                }
            }
        }

        return ans;

    }
    int orangesRotting(vector<vector<int>>& grid) {
        
        vector<vector<int>> testGrid = grid;
        int minutes = 0;
         int rows = grid.size();
        int cols  = grid[0].size();

        minutes =  findRottenOranges(testGrid);

        for(int row = 0 ; row < rows ; row ++){
            for(int col = 0 ; col < cols ; col ++){
                if(testGrid[row][col] == 1){
                    return -1;
                }
            }
        }

        return minutes;
    }
};

 bool isSafe(int i , int j , int n ,vector<vector<int>> &maze,vector<vector<int>> &visited){
     if( ((i>=0 && i < n) && (j >= 0 && j< n)) && (maze[i][j] == 1 ) && (visited[i][j]==false)) {
      return true;
     }
     else {
      return false;
     }
    }
    
    void solve(vector<vector<int>> &maze ,int n , string path,vector<vector<int>> &visited,int i ,int j,vector<string> &ans){
       //base-case
        if(i == n-1 && j == n-1){
            ans.push_back(path);
            return;
        }
        // cout<<"path :"<<path<<endl;
        
        // up,right,down,left movement
        
        if( isSafe(i-1,j,n,maze,visited) ){ //up
            visited[i-1][j] = 1;
            solve(maze,n,path + "U",visited,i-1,j,ans);
            visited[i-1][j] = 0;
        }
        
        if( isSafe(i,j+1,n,maze,visited) ){ //right
            visited[i][j+1] = 1;
            solve(maze,n,path +"R",visited,i,j+1,ans);
            visited[i][j+1] = 0;
        }
        
        if( isSafe(i+1,j,n,maze,visited)){ //down
            visited[i+1][j] = 1;
            solve(maze,n,path+"D",visited,i+1,j,ans);
            visited[i+1][j] = 0;
        }
        
        if( isSafe(i,j-1,n,maze,visited)){ //left
            visited[i][j-1] = 1;
            solve(maze,n,path+"L",visited,i,j-1,ans);
            visited[i][j-1] = 0;
        }
        
        
    }
    
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        vector<string> ans;
        
        if(m[0][0] == 0 || m[n-1][n-1] == 0){
            return ans;
        }
        
        string path;
        
        vector<vector<int>> visited(n,vector<int>(n,0));
        visited[0][0] = 1;
        
        solve(m,n,path,visited,0,0,ans);
        
        return ans;
    }

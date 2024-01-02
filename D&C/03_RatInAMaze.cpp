// Rat in a maze
//tc : O(exponential) : 4^n
//sc : O(N*N)

    int dx[4] = {-1,+1,0,0};
    int dy[4] = {0,0,-1,+1};
    char dir[4] =  {'U','D','L','R'};
    
    bool isSafe(vector<vector<int>> &m , int& n,int x ,int y,vector<vector<int>>& visited){
        if(!(x >=0 && x < n)) return false;
        if(!(y >=0 && y < n)) return false;
        if(m[x][y] == 0) return false;
        if(visited[x][y] == 1) return false;
        
        return true;
    }
    void solve(vector<vector<int>> &m , int& n,vector<string>& result , string path,vector<vector<int>>& visited,int x ,int y){
        //base-case : reached destination
        if(x == n -1 && y == n-1){
            result.push_back(path);
            return ;
        }
        
        for(int i =0 ; i<4 ;i++){
            int newX = x + dx[i];
            int newY = y + dy[i];
            if(isSafe(m,n,newX,newY,visited)){
                visited[x][y] = 1;
                solve(m,n,result,path + dir[i],visited,newX,newY);
                visited[x][y] = 0;
            }
        }
        
        
        
        
    }
    vector<string> findPath(vector<vector<int>> &m, int& n) {
        vector<string> result;
        int srcX = 0 ;
        int srcY = 0 ;
        // edge-case : if src is 0 return 
        if(m[srcX][srcY] == 0) return result;
        
        string path = "";
        vector<vector<int>> visited(n,vector<int>(n,0));
        visited[0][0] = 1;
        solve(m,n,result,path,visited,srcX,srcY);
        
        return result;
    }

// Rat in Maze- i -gfg : https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
// tc : O(N*N)
// sc : O(N*N)

void traverse(vector<vector<int>> &m, int n , int x , int y , string path ,vector<string> &result,vector<vector<int>> &visited){

        
        //base-case
        if(x == n-1 && y == n-1){
            result.push_back(path);
            return;
        }
        
        int dx[4] = {-1,+1,0,0};
        int dy[4] = {0,0,-1,+1};
        char dir[4] =  {'U','D','L','R'};
        
        for(int i= 0 ; i < 4 ; i++){
            int newX = x + dx[i];
            int newY = y + dy[i];
            if( (newX >=0 && newX < n)  && (newY >=0 && newY < n) && (m[newX][newY] == 1) && (visited[newX][newY] == 0)){
                visited[x][y] = 1;
                traverse(m,n,newX,newY,path + dir[i],result,visited);
                visited[x][y] = 0;
            }
        }
        
        visited[x][y] = 0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> result;
        if(m[0][0] == 0 || m[n-1][n-1] == 0 ){ // edge-case no paths posssible
            return result;
        }
        
        string path = "";
        vector<vector<int>> visited (n, vector<int>(n,0));
        visited[0][0] = 1;
        traverse(m,n,0,0,path,result,visited);
        
        
        return result;
    }

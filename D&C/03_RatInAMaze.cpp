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


//--------------------------------------------------------------------------------------
// alternative approach ( has a cleaner isSafe method)

#include <iostream>
#include<vector>
using namespace std;

bool isSafe(int i, int j, int row, int col, int arr[][4],
 vector<vector<bool> > &visited) {
  if( ((i>=0 && i < row) && (j >= 0 && j< col)) &&
      (arr[i][j] == 1 ) &&
      (visited[i][j]==false)) {
    return true;
  }
  else {
    return false;
  }
}

void solveMaze(int arr[][4], int row,int col, int i, int j,
vector<vector<bool> > &visited, vector<string>& path, string output  ) {

  //base case
  if(i == row-1 && j == col-1) {
    //answer found
    path.push_back(output);
    return;
  } 

  //Down -> i+1, j
  if(isSafe(i+1, j, row, col, arr, visited)) {
    visited[i+1][j] = true;
    solveMaze(arr, row, col, i+1, j, visited, path, output + 'D');
    //backtrack 
    visited[i+1][j] = false;
  }

  //Left -> i, j-1
  if(isSafe(i, j-1, row, col, arr, visited)) {
    visited[i][j-1] = true;
    solveMaze(arr, row, col, i, j-1, visited, path, output + 'L');
    //backtrack 
    visited[i][j-1] = false;
  }

  //Right -> i, j+1
  if(isSafe(i, j+1, row, col, arr, visited)) {
    visited[i][j+1] = true;
    solveMaze(arr, row, col, i, j+1, visited, path, output + 'R');
    //backtrack 
    visited[i][j+1] = false;
  }

  //Up-> i-1, j
if(isSafe(i-1, j, row, col, arr, visited)) {
    visited[i-1][j] = true;
    solveMaze(arr, row, col, i-1, j, visited, path, output + 'U');
    //backtrack 
    visited[i-1][j] = false;
  }


}

int main() {
  int maze[4][4] = { {1,0,0,0}, 
                 {1,1,0, 1},
                 {1,1,0,0},
                 {0,1,1,1}};

  if(maze[0][0] == 0) {
    cout << "No Path Exists " << endl;
    return 0;
  }

  int row = 4;
  int col = 4;

  vector<vector<bool> > visited(row, vector<bool>(col,false));
  //src ki value k true mark kredete h 
  visited[0][0] = true;

  vector<string> path;
  string output = "";

  solveMaze(maze,row,col, 0,0, visited, path, output);

  cout << "printing the results " << endl;
  for(auto i: path) {
    cout << i << " ";
  }
  cout << endl;
  if(path.size() == 0 ){
    cout << "No Path Exists " << endl;
  }

  
  return 0;
}

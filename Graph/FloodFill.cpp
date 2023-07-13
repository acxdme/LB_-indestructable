//why it's giving error when visited is not maintained , I also think that visited is not required.
// Reason : original color and color to be changes same hue tuh infinite loop
     void dfsFlooding(vector<vector<int>> &ansImage, int sr, int sc ,int& newColor,int sourceColor){
        // cout<<sr<<","<<sc<<endl;
        ansImage[sr][sc] = newColor;

        int dx[] = {0,1,0,-1};
        int dy[] = {-1,0,1,0};

        for(int i =0 ;i <4 ;i++){
            if(sr+dx[i] >= 0 && sr+dx[i] < ansImage.size() && sc + dy[i] >= 0 && sc + dy[i] < ansImage[0].size() && ansImage[sr +dx[i]][sc + dy[i]] == sourceColor){
                    dfsFlooding(ansImage,sr+dx[i],sc+dy[i],newColor,sourceColor);
            }
        }

    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> ansImage = image;

        int sourceColor = image[sr][sc];
        dfsFlooding(ansImage,sr,sc,newColor,sourceColor);

        return ansImage;
    }

/* -------------------------------------------------------------------------------------------*/

// visited leke approach 


class Solution {
public:

    void dfs(vector<vector<int>>& modImage,int r ,int c ,map<pair<int,int>, bool >& visited,int color,int originalColor){
        
        visited[{r,c}] = true;
        modImage[r][c] = color;

        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};

        for(int i = 0 ;i < 4 ; i++){
            int newX = r + dx[i];
            int newY = c + dy[i];

            if(newX >= 0 && newX < modImage.size() && newY >=0 && newY < modImage[0].size()){
                if(!visited[{newX,newY}] && modImage[newX][newY] == originalColor){
                    
                    dfs(modImage,newX,newY,visited,color,originalColor);
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        map<pair<int,int>, bool > visited;

        vector<vector<int>> modImage = image;

        dfs(modImage,sr,sc,visited,color,originalColor);

        return modImage;
    }
};

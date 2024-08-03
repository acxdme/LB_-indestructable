// lc - 733

// first attempt I think it's not possible to do this question without visited.

class Solution {
public:

    bool isValid(vector<vector<int>>& res ,int newX , int newY){
        if(newX >= res.size() || newX < 0) return false;
        if(newY >= res[0].size() || newY < 0 ) return false;

        return true;
    }
    void traverse(vector<vector<int>>& res , int sr, int sc , int &sourceColor , int &targetColor){
        if(res[sr][sc] != sourceColor){ // base-case
            return ;
        }
        res[sr][sc] = targetColor;
        int dx[] = {-1 ,0 , 1,0};
        int dy[] = {0 , -1,0,1};

        for(int i =0 ; i< 4 ;i++){
            int  newX = sr + dx[i];
            int  newY = sc + dy[i];
            if(isValid(res,newX,newY)){
                traverse(res,newX,newY,sourceColor,targetColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int sourceColor = image[sr][sc];
        int targetColor = color;

        // if(sourceColor == targetColor){
        //     return image;
        // }

        vector<vector<int>> result = image;
        traverse(result,sr,sc,sourceColor,targetColor);


        return result;
        
    }
};

-------------------------------------------------------------------------------------------------------------
    class Solution {
public:
    bool isValid(int x, int y, vector<vector<int>>& image, int originalColor) {
        if (x < 0 || x >= image.size())
            return false;
        if (y < 0 || y >= image[0].size())
            return false;
        if (image[x][y] != originalColor)
            return false;

        return true;
    }

    void dfs(vector<vector<int>>& image, int sr, int sc,
             vector<vector<int>>& visited, int originalColor, int newColor) {
        visited[sr][sc] = 1;
        image[sr][sc] = newColor;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int x = sr + dx[i];
            int y = sc + dy[i];

            if (isValid(x, y, image, originalColor)) {
                if (!visited[x][y]) {
                    dfs(image, x, y, visited, originalColor, newColor);
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {

        int rows = image.size();
        int cols = image[0].size();
        int originalColor = image[sr][sc];
        int newColor = color;
        vector<vector<int>> visited(rows, vector<int>(cols, 0));

        dfs(image, sr, sc, visited, originalColor, newColor);

        return image;
    }
};

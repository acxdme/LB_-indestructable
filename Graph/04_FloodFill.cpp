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

//why it's giving error when visited is not maintained , I also think that visited is not required.

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

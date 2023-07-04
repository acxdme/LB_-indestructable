//lc-1631
// bhagvan kasam mujhe bhi nahi pata mei kya kar raha hu.
class Solution {
public:
    int getMinEffort(vector<vector<int>>& heights,map<pair<int,int>,bool>& visited){

        set<pair<int,pair<int,int>>> st; //{distance,{x,y}}
        st.insert({INT_MAX,{0,0}});
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> distance(n,vector<int>(m,INT_MAX));
        // distance[0][0] = 0;
        while(!st.empty()){
            auto front = st.begin();
            auto frontNode = *front;
            st.erase(front);
            int curX = frontNode.second.first;
            int curY = frontNode.second.second;
            int curDistance = frontNode.first;
            int dx[] = {0,-1,0,1};
            int dy[] = {-1,0,1,0};

            for(int i = 0 ; i< 4 ;i++){
                int newX = frontNode.second.first + dx[i];
                int newY = frontNode.second.second + dy[i];
                if(newX >= 0 && newX < n && newY >=0 && newY < m && !visited[{newX,newY}])
                {
                
                 if(abs(heights[curX][curY] - heights[newX][newY]) < distance[newX][newY]){
                    int heightDiff = abs(heights[curX][curY] - heights[newX][newY]);
                    st.insert({heightDiff,{newX,newY}});
                    distance[newX][newY] = min(curDistance,distance[newX][newY]);
                 }

                }

            }
        }
        

        return distance[n-1][m-1];
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        map<pair<int,int>,bool> visited;

         int ans = getMinEffort(heights,visited);

         return ans;
    }
};

//------------------------------------------------------------------------------------------------------------------------------------------------

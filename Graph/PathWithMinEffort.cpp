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
//Second attempt , nahi pata kar pa raha ki kese debug karu

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int ans = 0;
        int r = heights.size();
        int c = heights[0].size();
        vector<vector<int>> distance(r,vector<int> (c,INT_MAX));
        priority_queue< pair<int,pair<int,int>> , vector< pair<int,pair<int,int>> >,greater< pair<int,pair<int,int>> > >pq;
        pq.push({0,{0,0}});
        distance[0][0] = 0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int curDiff = it.first;
            int curX = it.second.first;
            int curY = it.second.second;
            // cout<<curX<<" "<<curY <<endl;
            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};
            if(curX == r-1 && curY == c-1){
                return distance[curX][curY];
            }
            for(int i =0 ; i<4 ;i++){
                int newX = curX + dx[i];
                int newY = curY + dy[i];
                if(newX >=0 && newX < r && newY >= 0 && newY < c){
                    int newDiff = abs(heights[newX][newY] - heights[curX][curY]);
                    int mxDiff = max(newDiff,curDiff);
                    if( mxDiff < distance[newX][newY]  );
                    {
                      pq.push({mxDiff,{newX,newY}});
                      distance[newX][newY] = mxDiff;
                    }
                }
            }
        }






        return distance[r-1][c-1];

    }
};

-----------------------------------------------------------------------------------------------
    //third try correct code aur my code found no difference
    // correct code :
    class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
    
        int r = heights.size();
        int c = heights[0].size();
        vector<vector<int>> distance(r,vector<int>(c,INT_MAX));
        priority_queue< pair<int,pair<int,int>> , vector< pair<int,pair<int,int>> >,greater< pair<int,pair<int,int>> > >pq;
        pq.push({0,{0,0}});
        distance[0][0] = 0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int curDiff = it.first;
            int curX = it.second.first;
            int curY = it.second.second;
            // cout<<curX<<" "<<curY <<endl;

            if(curX == r-1 && curY == c-1){
                return distance[curX][curY];
            }

            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};
            for(int i =0 ; i<4 ;i++){
                int newX = curX + dx[i];
                int newY = curY + dy[i];
                if(newX >=0 && newX < r && newY >= 0 && newY < c){
                    int newDiff = abs(heights[newX][newY] - heights[curX][curY]);
                    int mxDiff = max(newDiff,curDiff);
                    if( mxDiff < distance[newX][newY]  );
                    {
                    //  cout<< newX <<"-"<<newY <<" : "; 
                      distance[newX][newY] = mxDiff;
                      pq.push({mxDiff,{newX,newY}});
                    }
                }
            }
        }

        return 0;

    }
};

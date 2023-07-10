    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> distance(V,1e8);
        distance[S] = 0;
        
        for(int i = 0 ;i <V ;i++){
            for(auto edge : edges){
                if(distance[edge[0]] == 1e8){
                    continue;
                }
                else{
                    if(distance[edge[1]] > distance[edge[0]] + edge[2]){
                        distance[edge[1]] = distance[edge[0]] + edge[2];
                    }
                }
            }
        }
        
        
        bool negativeCyclePresent = false;
        
        for(auto edge : edges){
            if(distance[edge[0]] == INT_MAX){
                continue;
            }
            else{
                if(distance[edge[1]] > distance[edge[0]] + edge[2]){
                    negativeCyclePresent = true;
                     vector<int> res(1,-1);
                     return res;
                }
            }
        }
        
        return distance;
        
    }

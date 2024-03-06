// gfg - https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

// hard to frame the mindset , need to revise again (bura haal hai)

    void findShortestPath(int &V , vector<vector<int>> adj[] , int &src , vector<int> &distance ,vector<int> &visited,set<pair<int,int>> &st){
        
        distance[src] = 0;
        visited[src] = 1;
        
        st.insert({0,src});
        
        while(!st.empty()){
            
            auto it = st.begin();
            int currD = it->first;
            int node = it->second;
            
            st.erase(it);
            
            for(auto nbr : adj[node]){
                if(currD + nbr[0] <= distance[nbr[1]]){
                    distance[nbr[1]] =  currD + nbr[0];
                    st.insert({distance[nbr[1]],nbr[1]});
                }
            }
        }
    }
    
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        
        //distance array
        vector<int> distance(V,INT_MAX); 
        
        //visited array
        vector<int> visited(V,0);
        
        
        //set<weight,node>
        set<pair<int,int>> st;
        
        findShortestPath(V,adj,S,distance,visited,st);
        
        
        return distance;
    }

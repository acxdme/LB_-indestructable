//Greedy algorithm

/*

  algorithm : find the node with minimum distance , staring with source node,keep updating the distance array , and maintain a clean set of {distance, node} values.
  */

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // 0 -> {node,weight} ,{node2,weght}
        
        vector<int> distance(V,INT_MAX);
        distance[S] = 0;
        
        set<pair<int,int>> st;
        st.insert({0,S}); // {weight,node}
        
        while(!st.empty()){
            auto it = *st.begin();
            // cout<<"{"<<it.first<<","<<it.second<<"}"<<endl;
            st.erase(st.begin());
            for(auto nbr : adj[it.second]){
                
                // cout<<nbr[0]<<":"<<nbr[1]<<", ";
                if(distance[it.second] != INT_MAX && it.first + nbr[1] < distance[nbr[0]]){
                    
                    if(st.find({distance[nbr[0]],nbr[0]}) != st.end()){
                        auto pos = st.find({distance[nbr[0]],nbr[0]});
                        st.erase(pos);
                    }
                    
                    
                    distance[nbr[0]] = it.first + nbr[1];
                    st.insert({distance[nbr[0]],nbr[0]});
                }
            }
        }
        
        return distance;
    }

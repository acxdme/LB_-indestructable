bool findCycle(vector<int> adj[],unordered_map<int,int> &visited,int vertices , int src,int parent){
    visited[src] = 1;
    
    for(auto nbr : adj[src]){
        if(!visited[nbr]){
            bool answer = findCycle(adj,visited,vertices,nbr,src);
            if(answer){
                return true;
            }
        }
        else{ //visited hai
            if(nbr != parent){ // cycle detected
                return true;
            }
        }
    }
    
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    unordered_map<int,int> visited;
    
    for(int i =0 ; i < V ;i++){
      if(!visited[i]){
          bool result = findCycle(adj,visited,V,i,-1);
          if(result){
              return true;
          }    
      }
    }
    
    return false;
    }

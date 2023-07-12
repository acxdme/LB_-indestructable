//Kosaraju algorithm for finding the strongly connected components.

	    visited[src] = true;
	    
	    for(auto nbr : adjList[src]){
	        if(!visited[nbr]){
	            dfs2(nbr,visited,adjList);
	        }
	    }
	    
	}
	
	void dfs(int src,unordered_map<int,int>& visited, vector<vector<int>>& adjList,stack<int>&topoOrder){
	    visited[src] = true;
	    
	    for(auto nbr : adjList[src]){
	        if(!visited[nbr]){
	            dfs(nbr,visited,adjList,topoOrder);
	        }
	    }
	    
	    topoOrder.push(src);
	}
	void findTopoOrder(int& V ,vector<vector<int>>& adj, stack<int>&topoOrder){
	    
	    unordered_map<int,int> visited;
	    for(int src = 0 ; src < V ;src++){
	        if(!visited[src]){
	            dfs(src,visited,adj,topoOrder);
	        }
	    }
	    
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //topoOrder using dfs
        // reverse edges
        // dfs traverse on topoOrder
        stack<int> topoOrder;
        findTopoOrder(V,adj,topoOrder);
        
        unordered_map<int,list<int>> adjList;
        for(int i = 0 ; i< V ;i++){
            for(auto nbr : adj[i]){
                adjList[nbr].push_back(i);
            }
        }

        
        int count = 0 ;
        unordered_map<int,int> visited;

        while(!topoOrder.empty()){
             int tp = topoOrder.top();
             topoOrder.pop();
             if(!visited[tp]){ 
                dfs2(tp,visited,adjList);
                count++;
             }
        }
        
        return count;
    }

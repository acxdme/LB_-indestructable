// Find if path exists or not 

#include <iostream>
#include <vector>

using namespace std;

bool dfs(int source , int destination , vector<int> adj[] , vector<int> &vis)
{
    vis[source] = 1; // fix : mark the source as visited
    if(source == destination)
    {
        return true;
    }
    for(auto a:adj[source])
    {
        if(!vis[a])
        {
            if(dfs(a, destination, adj, vis))
            {
                return true;
            }
        }
    }
    return false;
}

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
{
    vector<int> vis(n,0);
    vector<int> adj[n];
    int edgesSize = edges.size();
    for(int i=0; i < edgesSize;i++)
    {
        adj[edges[i][1]].push_back(edges[i][0]); 
        adj[edges[i][0]].push_back(edges[i][1]);            
    }
    return dfs(source , destination , adj , vis);
}


int main() {
  vector<vector<int>> edges = {{0,1},{2,3}};
  cout<< "edges : " << endl;
  bool answer = validPath(4,edges, 0, 2);
  cout<<"answer : " << answer <<endl;
  
  return 0;
}

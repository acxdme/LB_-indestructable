
#include <iostream>
#include <unordered_map>
#include<list>
#include<vector>
#include<queue>

using namespace std;

class Graph{
public :
 unordered_map<int,list<int>> adj;
 
 void addEdge(int u ,int v , int isDirected){
     adj[u].push_back(v);
     if(!isDirected){
         adj[v].push_back(u);
     }
 }
 
 void printAdjList(){
     for(auto node : adj){
         cout<<node.first<<"-> ";
         for(auto nbr : node.second){
             cout<<nbr<<",";
         }cout<<endl;
     }
 }
 
 void bfs(int src,vector<int>&visited){
     
     queue<int> q;
     q.push(src);
     visited[src] = 1;
     
     while(!q.empty()){
         int front = q.front();
         cout<< front<<" ";
         q.pop();
         for(auto nbr : adj[front]){
             if(!visited[nbr]){
                 q.push(nbr);
                 visited[nbr] = 1;
             }
         }
     }
     
 }
    
};
int main() {
    Graph g;
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(2,0,0);
    g.addEdge(3,4,0);
    
    

    g.printAdjList();
    
 
    int nodes = g.adj.size();
    vector<int>visited(nodes,0);
    for(int src = 0 ; src<nodes;src++ ){
     if(!visited[src]){
      g.bfs(src,visited);
     }
        
    }
   

    return 0;
}

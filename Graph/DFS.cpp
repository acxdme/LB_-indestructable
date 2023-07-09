//  Time - complexity : O(V+E)
#include <iostream>
#include <vector>
#include<unordered_map>
#include<list>

using namespace std;

template<typename T> 
class Graph{
public:
    unordered_map<T,list<T>> adjList;
    
   void addEdge(T u ,T v ,int direction){
        adjList[u].push_back(v);
        if(!direction){
            adjList[v].push_back(u);
        }
    }
    
   void printAdjList(){
       for( auto nodes : adjList){
           cout << nodes.first<<"-> ";
           for(auto nbr : nodes.second){
               cout<< nbr<<",";
           }cout<<endl;
       }
   }
   
   void dfs(vector<int>& visited ,int src){
       
       cout<< src <<" ";
       for(auto nbr : adjList[src]){
           if(!visited[nbr]){
               visited[nbr] = true;
               dfs(visited,nbr);
           }
       }
   }
    
};
int main() {
   
    Graph<int> g;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(1,4,1);
    g.addEdge(2,4,1);
    g.addEdge(2,3,1);
    
    g.printAdjList();
    int nodes = 5;
    vector<int> visited(nodes , 0);
    
    for(int i = 0 ;i < nodes ; i++){
        if(!visited[i]){
            g.dfs(visited,i);
        }
    }
    
    

    return 0;
}


---------------------------------------------------------------------

// method-1 VS method-2 (check in a real example)

    //method-1
   void dfs(vector<int>& visited ,int src){
       
       cout<< src <<" ";
       for(auto nbr : adjList[src]){
           if(!visited[nbr]){
               visited[nbr] = true;
               dfs(visited,nbr);
           }
       }
   }

 // method-2

   void dfs(vector<int>& visited ,int src){
       
       cout<< src <<" ";
       visited[src] = true; // this line
       for(auto nbr : adjList[src]){
           if(!visited[nbr]){
               
               dfs(visited,nbr);
           }
       }
   }


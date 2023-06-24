// Online C++ compiler to run C++ program online
#include <iostream>
#include <unordered_map>
#include<list>
#include<vector>

using namespace std;

class Graph{
  private:
  unordered_map<int,list<int>> adjList;
  public:
  void addEdge(int u ,int v , int direction){
      adjList[u].push_back(v);
      if(direction == 0){
          adjList[v].push_back(u);
      }
  }
  
  void printAdjList(){
      for(auto it : adjList){
          cout<< it.first<<"-> ";
          for(auto nbr : it.second){
              cout<<nbr<<",";
          }cout<<endl;
      }
  }
  
  
  bool checkCycleUsingDfs(int src , vector<int>& parent ,vector<int>& visited){
      visited[src] = 1;
      
      bool ans = false;
      for(auto nbr : adjList[src]){
          if(!visited[nbr]){
              visited[nbr]= true;
              parent[nbr] = src;
              ans = checkCycleUsingDfs(nbr,parent,visited);
              if(ans) return true;
          }else{
              if(parent[src] != nbr){
                  return true;
              }
          }
      }
      
      return ans;
  }
  
};

int main() {
    Graph g;
    // g.addEdge(0,1,0);
    // g.addEdge(1,3,0);
    // g.addEdge(2,3,0);
    // g.addEdge(3,4,0);
    // g.addEdge(3,5,0);
    // g.addEdge(5,6,0);
    // g.addEdge(4,6,0);
    
    
    // example showing failure in directed graph
    // g.addEdge(0,1,1);
    // g.addEdge(1,2,1);
    // g.addEdge(0,2,1);
    
    
    g.printAdjList();
    int nodes = 7;
    vector<int> parent(nodes , -1);
    vector<int> visited(nodes,0);
    bool isCycle = false;
    for(int i = 0 ; i < nodes ; i++){
         if(!visited[i]){
          isCycle = g.checkCycleUsingDfs(i , parent ,visited);        
         }
        if(isCycle){
           break;

        }
    }
    
    if(isCycle){
        cout<<"Cycle Present"<<endl;
    }else{
        cout<<"Cycle is Absent"<<endl;
    }
    

    return 0;
}

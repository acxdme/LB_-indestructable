#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>

using  namespace std;

class Graph {
private:
    unordered_map<int, list<int>> adjList;
    unordered_map<int, int> indegree;

public:
    void addEdge(int u, int v, int direction) {
        adjList[u].push_back(v);
        indegree[v]++;
        if (direction == 0) {
            adjList[v].push_back(u);
        }
    }

    void printAdjList() {
        for (auto it : adjList) {
            cout << it.first << "->";
            for (auto nbr : it.second) {
                cout << nbr << ",";
            }cout << endl;
        }
    }

    void findTopoBFS(int nodes ) {
        queue<int>  q;
        for(int i = 0 ;i < nodes; i++){
         if(indegree[i] == 0){
            q.push(i);
         }
        }

        while(!q.empty()){
            int frontNode = q.front();
            cout<<frontNode<<", ";
            q.pop();
            for(auto nbr : adjList[frontNode]){
                 indegree[nbr]--;
                 if(indegree[nbr] == 0 ){
                     q.push(nbr);
                 }
            }
        }cout<<endl;
       
    }

};

int main()
{
    Graph g;

    // example-1
    // g.addEdge(0, 1, 1);
    // g.addEdge(1, 2, 1);
    // g.addEdge(1, 3, 1);
    // g.addEdge(2, 4, 1);
    // g.addEdge(3, 4, 1);
    
    // example-2
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(2, 4, 1);

    g.addEdge(3, 5, 1);
    g.addEdge(4, 5, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(5, 7, 1);
    
    g.printAdjList();

    int nodes = 8;

    // Directed acyclic graph is
    // a must to find the topoSort order

    // Kahn's algorithm -> topoSort using BFS traversal.

    g.findTopoBFS( nodes);

    return 0;
}

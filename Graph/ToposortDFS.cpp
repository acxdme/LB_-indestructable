#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>

using  namespace std;

class Graph {
private:
    unordered_map<int, list<int>> adjList;
public:
    void addEdge(int u, int v, int direction) {
        adjList[u].push_back(v);
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

    void topoDfs(int src , unordered_map<int,int>& visited , stack<int>& topoSort) {
        visited[src] = 1;


        for (auto nbr : adjList[src]) {
            if (!visited[nbr]) {
                topoDfs(nbr, visited, topoSort);
            }
        }

        cout << "pushing element :" << src << endl;
        topoSort.push(src);

        return;
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);

    g.printAdjList();

    int nodes = 4;
    
    // Directed acyclic graph is
    // a must to find the topoSort order

    stack<int> topoSort;
    unordered_map<int, int> visited;

    for (int i = 0;i < nodes; i++) {
        if (!visited[i]) {
            g.topoDfs(i, visited, topoSort);
        }
    }

    while (!topoSort.empty()) {
        int top = topoSort.top();
        cout << top << " ";
        topoSort.pop();
    }

    cout << endl;



    return 0;
}

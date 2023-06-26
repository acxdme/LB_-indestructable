#include <iostream>
#include <unordered_map>
#include <list>

using  namespace std;

class Graph {
private:
    unordered_map<int, list<int>> adjList;
public :
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

    bool checkCycleDfs(unordered_map<int, int>& visited, unordered_map<int, int>& dfsVisited, int src) {
        visited[src] = 1;
        dfsVisited[src] = 1;

        for (auto nbr : adjList[src]) {
            if (!visited[nbr]) {
               bool res =  checkCycleDfs(visited, dfsVisited, nbr);
               if (res) {
                   return res;
               }
            }
            else {
                if (dfsVisited[nbr] = true) {
                    return true;
                }
            }

        }

        dfsVisited[src] = 0;

        return false;
    }

};

int main()
{
    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    //g.addEdge(3, 1, 1);


    g.printAdjList();

    unordered_map<int, int> visited;
    unordered_map<int, int> dfsVisited;

    bool isCyclic = false;
    int nodes = 4;
    for (int i = 0;i < nodes;i++) {
        if (!visited[i]) {
         isCyclic =  g.checkCycleDfs(visited,dfsVisited,i);
         if (isCyclic) {
             isCyclic = true;
             break;
         }
        }
    }

    if (isCyclic) {
        cout << "cycle present" << endl;
    }
    else {
        cout << "cycle absent" << endl;
    }

    return 0;
}

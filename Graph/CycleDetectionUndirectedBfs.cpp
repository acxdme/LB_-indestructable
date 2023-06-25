#include <iostream>
#include <unordered_map>
#include<list>
#include <queue>

using namespace std;

class Graph {
private:
	unordered_map<int, list<int>> adjList;
public:
	void addEdge(int u ,int v , int direction) {
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

	bool detectCycleBfs(unordered_map<int,bool>& visited, unordered_map<int, int>& parent, int src) {
		queue<int> q;
		q.push(src);
		visited[src] = true;
		parent[src] = -1;

		bool isCycle = false;
		while (!q.empty()) {
			int frontNode = q.front();
			q.pop();
			for (auto nbr : adjList[frontNode]) {
				if (!visited[nbr]) {
					q.push(nbr);
					visited[nbr] = true;
					parent[nbr] = frontNode;
				}
				else {
					if (parent[frontNode] != nbr) {
						isCycle = true;
						return isCycle;
					}
				}
			}
		}

		return isCycle;
	}
};

int main()
{
	Graph g;
	//example-1
// 	g.addEdge(0, 1, 0);
// 	g.addEdge(1, 2, 0);
// 	g.addEdge(1, 3, 0);
// 	g.addEdge(3, 4, 0);
// 	g.addEdge(2, 4, 0);

  // example-2
  g.addEdge(0,1,0);
  g.addEdge(0,2,0);
  g.addEdge(0,3,0);


	g.printAdjList();

	//detect cycle via BFS

	unordered_map<int, bool> visited;
	unordered_map<int, int> parent;

	int nodes = 3;
	bool isCycle = false;
	for (int i = 0;i < nodes;i++) {
		if (!visited[i]) {
			isCycle = g.detectCycleBfs(visited,parent,i);
			if (isCycle) {
				break;
			}
		}
	}
	
	if (isCycle) {
		cout << "Cycle present" << endl;

	}
	else {
		cout << "Cycle absent" << endl;
	}

	return 0;
}

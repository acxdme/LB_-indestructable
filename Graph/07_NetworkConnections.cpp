// lc - 1319
// Tc : O( V + E)
// Sc : O( V + E)

class Solution {
public:
    void findDisconnectedComponents(int src,
                                    unordered_map<int, list<int>>& adjList,
                                    unordered_map<int, bool>& visited) {
        visited[src] = true;

        for (auto nbr : adjList[src]) {
            if (!visited[nbr]) {
                findDisconnectedComponents(nbr, adjList, visited);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {

        int totalConnections = connections.size();
        // edge case ->  n nodes then n-1 edges are required
        if (totalConnections < n - 1)
            return -1;

        // make adjList
        unordered_map<int, list<int>> adjList;

        for (auto edge : connections) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        unordered_map<int, bool> visited;

        int counter = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                counter++;
                findDisconnectedComponents(i, adjList, visited);
            }
        }

        return counter - 1;
    }
};

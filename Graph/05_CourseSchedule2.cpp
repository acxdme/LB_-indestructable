class Solution {
public:
    void findTopo(unordered_map<int, list<int>>& adjList, int& numCourses,
                  vector<int>& topoOrder) {

        vector<int> indegree(numCourses, 0);

        for (auto it : adjList) {
            for (auto nbr : it.second) {
                indegree[nbr]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int front = q.front();
            q.pop();
            topoOrder.push_back(front);

            for (auto nbr : adjList[front]) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<int> topoOrder;
        // make adjaceny list
        unordered_map<int, list<int>> adjList;
        for (auto pre : prerequisites) {
            adjList[pre[1]].push_back(pre[0]);
        }

        // apply kahn's algo for topo order
        findTopo(adjList, numCourses, topoOrder);

        // check if cycle exits return []
        if (topoOrder.size() != numCourses) {
            return {};
        }

        // return the topo order
        return topoOrder;

        return topoOrder;
    }
};

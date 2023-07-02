// finding toposort with DFS will give incorrect result when cycle exist unlike the BFS approach it will not, give you incomplete ordering.
// so for courseSchedule type questions directly go for BFS approach.

// code with failed attempt (using DFS)
class Solution {
public:

    void topoSortDfs(int src,unordered_map<int,int>& visited,unordered_map<int,list<int>>& adjList ,stack<int>& topologicalOrder){
        visited[src] = 1;

        for(auto nbr : adjList[src]){
            if(!visited[nbr]){
                topoSortDfs(nbr,visited,adjList,topologicalOrder);
            }
        }


        topologicalOrder.push(src);
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int,list<int>> adjList;
        for(auto it : prerequisites){
            int u = it[0];
            int v = it[1];
            adjList[v].push_back(u);
        }

        stack<int> topologicalOrder;
        unordered_map<int,int> visited;
        for(int i = 0 ; i< numCourses;i++){
            if(!visited[i]){
                topoSortDfs(i,visited,adjList,topologicalOrder);
            }
        }

        int nodes = numCourses;
        if(topologicalOrder.size() == nodes){
            return true;
        }
        else{
            return false;
        }

    }
};

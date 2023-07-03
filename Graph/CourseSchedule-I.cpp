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

//working solution
// Kahn's algorithm (BFS approch)
class Solution {
public:
    bool findTopoOrderUsingKahn(int nodes ,unordered_map<int,list<int>>& adjList){
        queue<int> q;
        vector<int> indegree(nodes,0);
        for(auto it : adjList){
            for(auto nbr : it.second){
                indegree[nbr]++;
            }
        }
        for(int i =0 ;i<nodes;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> topoOrder;
        while(!q.empty()){
            int frontNode = q.front();
            topoOrder.push_back(frontNode);
            q.pop();
            for(auto nbr : adjList[frontNode]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }
        }

        if(topoOrder.size() == nodes){
            return true;
        }
        else{
            return false;
        }

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //create adjList from prerequisites.
        // apply kahns algorithm.
        // validate topo ordering.
        unordered_map<int,list<int>> adjList;
        for(auto it : prerequisites){
            int u = it[0];
            int v = it[1];
            adjList[v].push_back(u);
        }

        bool result=  findTopoOrderUsingKahn(numCourses,adjList);


        return result;

    }
};

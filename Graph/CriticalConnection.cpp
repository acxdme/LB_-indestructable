class Solution {
public:

    void findCricticalConnections(int src , unordered_map<int,list<int>>& adjList,vector<vector<int>>& res, unordered_map<int,int>& visited,int timer,vector<int>& tin , vector<int>& low,int parent){

        visited[src] = 1;
        tin[src] = timer;
        low[src] = timer;
        timer++;

        for(auto nbr : adjList[src]){
            if(nbr == parent) {
                continue;
            }
            else if(!visited[nbr]){
                findCricticalConnections(nbr,adjList,res,visited,timer,tin,low,src);

                low[src] = min(low[src],low[nbr]);

                if(low[nbr] > tin[src]){
                    vector<int> temp;
                    temp.push_back(nbr);
                    temp.push_back(src);
                    res.push_back(temp);
                }
            }
            else{
               low[src] = min(low[src],low[nbr]); 
            }
        }


    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>> res;
        unordered_map<int,int> visited;
        unordered_map<int,list<int>> adjList;
        vector<int> tin(n);
        vector<int> low(n);

        for(auto it : connections){
            int u = it[0];
            int v = it[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        findCricticalConnections(0,adjList,res,visited,1,tin,low,-1);

        return res;
    }
};

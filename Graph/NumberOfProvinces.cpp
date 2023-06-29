class Solution {
private:
    void dfs(unordered_map<int,int>& visited , int src ,vector<vector<int>>& isConnected){
        visited[src] = 1;

        for(int i = 0 ; i < isConnected[src].size(); i++){
            if(src == i){
                continue;
            }
            else if(isConnected[src][i] == 1 && visited[i] != 1){
                dfs(visited,i,isConnected);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int nodes = isConnected.size();
        unordered_map<int,int> visited;
        int provinces = 0;
        // i represent a node here.
        for(int i = 0; i < nodes;i++){
            if(!visited[i]){
                dfs(visited,i,isConnected);
                provinces++;
            }
        }

        return provinces;
    }
};

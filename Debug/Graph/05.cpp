// Clone Graph
// R & D on clone Graph questions.

class Solution { // fix : baseCase and access specifiers updated.
public:
    unordered_map<Node* , Node*> mp;
    
    Node* cloneGraph(Node* node) {
        if(node == NULL) 
        {
            return NULL;
        }
        
        if(mp.find(node) == mp.end())
        {
            mp[node] = new Node(node -> val, {});
            
            for(auto adj: node -> neighbors)
            {
                mp[node] -> neighbors.push_back(cloneGraph(adj));
            }
        }
        
        return mp[node];
        
    }
};

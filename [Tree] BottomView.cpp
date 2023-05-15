/*
 Time complexity : O(N)
 Space complexity : O(N) , using queue to  for level order traversal (storing the nodes and horizontal data)
*/
class Solution {
  public:
    void solve(Node* root ,map<int,int>& mp){
        int hd = 0;
        queue<pair<int,Node*>>q;
        q.push({0,root});
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            mp[front.first] = front.second->data;
            
            if(front.second->left){
                q.push({front.first-1,front.second->left});
            }
            if(front.second->right){
                q.push({front.first+1,front.second->right});
            }
        }
    }
    vector <int> bottomView(Node *root) {
        vector<int> ans;
        if(root == NULL) return ans;
        
        map<int,int> mp;
        solve(root,mp);
        for(auto it : mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
    
};

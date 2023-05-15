/*
 Time complexity : O(n)
 Space complexity : O(n) , considering stack space.
*/

class Solution
{
    public:
    
    void solve(Node * root , map<int,pair<int,int>>& mp ,int level,int order ,vector<int>& ans){
      if(root == NULL) return;
      
      if(mp.find(order) == mp.end()){
          mp[order] = make_pair(level,root->data);
      }else{
          if(mp[order].first > level){
              mp[order] = make_pair(level,root->data);
          }
      }
      
      solve(root->left,mp,level+1,order-1,ans);
      solve(root->right,mp,level+1,order+1,ans);
      
    }
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int> ans;
        if(root == NULL) return ans;
        map<int,pair<int,int>> mp;
        int order = 0;
        int level = 0;
        
        solve(root,mp,level ,order,ans);
        for(auto it : mp){
            ans.push_back(it.second.second);
        }
        
        return ans;
    }

};

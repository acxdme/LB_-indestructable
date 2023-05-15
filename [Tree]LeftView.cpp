/*
 Time complexity : O(N)
 Space complexity : O(N) , considering recursion stack space.
*/
void solve( Node *root,vector<int>& ans ,int level){
    //base-case
    if(root == NULL) return;
    
    if(ans.size() == level) ans.push_back(root->data);
    
    solve(root->left,ans,level+1);
    solve(root->right,ans,level+1);
}
vector<int> leftView(Node *root)
{
   vector<int> ans;
   if(root == NULL) return ans;
   int level = 0;
   
   solve(root,ans,level);
   
   return ans;
}

/*
  Problem : gfg , check if Dead End exists in BST or not.
  T.C : O(N) , traverse the tree.
  S.C : O(N), considerting the recursion stack.
*/


bool solve(Node* root ,int& mn ,int& mx){
    if(root == NULL){
       return false;
    }
    if(root->left == NULL && root->right == NULL){
      if(root->data - mn <=1  && mx - root->data <=1 ) return true;
      return false;
    }
    
    bool left =solve(root->left,mn,root->data);
    // if(left) return left;
   
    bool right = solve(root->right,root->data,mx);
    // if(right ) return right;
    
    return left || right;
    
    
}
bool isDeadEnd(Node *root)
{
   int mn = 1;
   int mx = INT_MAX;
   
   bool ans = solve(root,mn,mx);
   
   return ans;
}

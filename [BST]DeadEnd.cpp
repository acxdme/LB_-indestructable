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


----------------------------------------
  //more simpler approach gfg
  bool deadEnd(Node* root, int min=1, int max=INT_MAX)
{
    // if the root is null or the recursion moves
    // after leaf node it will return false
    // i.e no dead end.
    if (!root)
        return false;
 
    // if this occurs means dead end is present.
    if (min == max)
        return true;
 
    // heart of the recursion lies here.
    return deadEnd(root->left, min, root->data - 1) ||
           deadEnd(root->right, root->data + 1, max);
}

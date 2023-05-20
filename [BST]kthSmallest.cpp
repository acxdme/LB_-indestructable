/**
  Time complexity : O(N)
  The pattern is same as the kth ancestor of a node in binary tree.
  Here in this question we are following the inorder approach to find the smallest node , from there onwards we 
  are moving to the increasing sequence (aka inorder is sorted) , we are decreasing the value of k , k==0 is our answer.
 */
class Solution {
public:
    int solve(TreeNode* root ,int &k){
        //base-case
        if(root == NULL) return -1;
        
        // check for left sub-tree
        int l = solve(root->left,k);
        if(l != -1) return l;
        
        // decrease k, return root->val if k is 0
        k--;
        if(k == 0 ) return root->val;
        
        // traverse for right sub-tree
        int r = solve(root->right,k);
        return r;
    }
    int kthSmallest(TreeNode* root, int k) {
        
        int ans = 0;

        ans = solve(root,k);

        return ans;
        
    }
}; 

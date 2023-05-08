/*
 Time-complexity :  O(N) 
 space complexity : O(1) , ignoring recursion stack space.
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if(root == NULL) return NULL;

        if(root == p) return p;
        if(root == q) return q;

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if(left == NULL && right == NULL) return NULL;
        else if(left!= NULL && right== NULL) return left;
        else if(left == NULL && right !=NULL) return right;
        else return root;
    }
};

/*
Here is the step-by-step algorithm for the given code:

1. The base case is reached when the root node is NULL.
   In this case, there is no LCA, so we return NULL.
2. If the root node is either p or q, then we have found one of the nodes we are looking for.
   In this case, we return that node.
3. We recursively search for the LCA in the left and right subtrees of the root node.
4. We check the results of the recursive calls.
   If both left and right subtrees return NULL, then there is no LCA, so we return NULL.
5. If only one of the subtrees returns a non-NULL value, then that subtree contains either p or q.
   In this case, we return the non-NULL value.
6. If both the left and right subtrees return non-NULL values, then the LCA is the root node itself.
   In this case, we return the root node.
*/

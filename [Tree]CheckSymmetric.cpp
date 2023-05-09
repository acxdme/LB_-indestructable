/*
 Time complexity : O(N)
 Space complexity : O(1) , O(N) if we consider recursive stack.
*/
class Solution {
public:
    bool checkSym(TreeNode* root , TreeNode* root1){

        // if null node return true
        if(root == NULL and root1 == NULL) return true;
        // if one root is null and other root is not null return false
        if((root == NULL and root1 != NULL) || (root !=NULL and root1 == NULL)) return false;
        // if value of compared nodes is not equal return false
        if(root->val != root1->val) return false;

        // traverse in respected trees
        bool ans = checkSym(root->left ,root1->right);
        bool ans1 = checkSym(root->right,root1->left);
        return ans && ans1;
    }
    bool isSymmetric(TreeNode* root) {
        //base-condition
        if(root == NULL) return true;
        // split  the problem of finding mirror between LST & RST of root.
        bool ans = checkSym(root->left , root->right);

        return ans;
        
    }
};

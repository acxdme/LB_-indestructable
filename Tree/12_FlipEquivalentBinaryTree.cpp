TC : O(N)
SC : O(h) , where h is the height of the binary tree.
lc - 951 : https://leetcode.com/problems/flip-equivalent-binary-trees/

class Solution {
public:

    bool checkEquiv(TreeNode* r1 , TreeNode* r2){
        if(r1 == NULL & r2 != NULL)
        return false;
        if(r1 != NULL & r2 == NULL)
        return false;
        if(r1 == NULL & r2 == NULL)
        return true;
        if(r1->val != r2->val){
            return false;
        }
        // check if already equal or can be flipped to make it equal
        return checkEquiv(r1->left,r2->left) && checkEquiv(r1->right,r2->right) || 
        checkEquiv(r1->left,r2->right) && checkEquiv(r1->right,r2->left);

        
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {

        bool ans = checkEquiv(root1, root2);
        return ans;
        
    }
};

/*
 Time complexity : O(N)
 Space complexity : O(1) , but O(N) if we consider recursion stack
*/

class Solution {
public:
    bool solve(TreeNode* root , int& targetSum , int pathSum){
        //base-case
        if(root == NULL) return false;

        //update the pathSum
        pathSum +=  root->val;

        //leafNode check targetSum achieved
        if(root->left == NULL && root->right == NULL){
            if(pathSum == targetSum) return true;
            return false;
        }

        bool left = solve(root->left,targetSum,pathSum);
        bool right = solve(root->right,targetSum,pathSum);

        return (left || right);
    }
  
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        int pathSum = 0;
        bool ans = solve(root,targetSum,pathSum);

        return ans;
    }
};

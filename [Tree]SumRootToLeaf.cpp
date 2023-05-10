/*
  Time complexity : O(N).
  space complexity : O(1) , O(N) when we consider recursive stack.
*/
class Solution {
public:

    void solve(TreeNode* root ,int path ,int& sum){
         if(root == NULL) return ;
         path = path * 10 + root->val;
         if(root->left == NULL && root->right == NULL){
             sum += path;
             return;
         }

         solve(root->left,path,sum);
         solve(root->right,path,sum);

    }
    int sumNumbers(TreeNode* root) {
        if(root == NULL) return 0;
        int path = 0;
        int sum = 0;

        solve(root,path,sum);

        return sum;
        
    }
};

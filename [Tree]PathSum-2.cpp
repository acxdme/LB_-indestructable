/*
 Time complexity : O(N) , we are simply traversing the tree.
 Space complexity : O(1) , O(N) if we consider recursion stack.
*/
class Solution {
public:
    void solve(TreeNode* root ,int& target ,int pathSum,vector<int>& path,vector<vector<int>>& ans){
        //base-case
        if(root == NULL) return ;

        // build the path & update pathSum
        path.push_back(root->val);
        pathSum += root->val;

        // check if leaf node
        if(root->left == NULL && root->right == NULL){
           if(pathSum == target){
               ans.push_back(path);
           }
        }

        solve(root->left,target,pathSum,path,ans);
        solve(root->right,target,pathSum,path,ans);

        path.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        vector<int> path;
        int pathSum = 0;
        solve(root,targetSum ,pathSum ,path,ans);

        return ans;
    }
};

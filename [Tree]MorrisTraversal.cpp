/*
Morris algo for inorder traversal.
Uses the concept of threaded binary tree.
*/

class Solution {
public:
    void morrisTraversal(TreeNode*& root ,vector<int>& ans){
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode *temp = curr->left;
                while(temp->right != NULL && temp->right != curr){
                    temp= temp->right;
                }

                if(temp->right == NULL){
                    temp->right = curr;
                    curr = curr->left;
                }
                else{
                    temp->right =NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        morrisTraversal(root,ans);
        return ans;
        
    }
};

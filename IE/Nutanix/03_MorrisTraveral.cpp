// lc - 94
// tc - O(N)
// sc - O(1)


// Morris Traversal for Inorder Traversal
class Solution {
public:

    void morrisTraversal(TreeNode* &root, vector<int> &ans){
        TreeNode* curr = root;

        while(curr != NULL){

            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr = curr ->right;

            }
            else{
                TreeNode* pred = curr->left;

                while(pred->right != curr && pred->right != NULL){
                    pred = pred->right;
                }

                if(pred->right == NULL){
                    pred->right = curr;
                    curr = curr ->left;
                }
                else{
                    pred->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr ->right;
                }
            }
        }

    }
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> ans;
        if(root == NULL) return ans;

        morrisTraversal(root,ans);

        return ans;
        
    }
};

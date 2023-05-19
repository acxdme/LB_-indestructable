/**
    Time complexity : O(N)
    Space complexity : O(N) , considering recursion stack.
 */
class Solution {
public:

    void findInorderPredessor(TreeNode* root){
        TreeNode* temp = root;
        temp = temp->left;
        while(temp->right != NULL){
            temp = temp->right;
        }
        cout<<temp->val<< " "<<root->val;
        swap(temp->val,root->val);

        return;
    }

    TreeNode* deleteNodeBst(TreeNode* root , int& key){
        //base-case
        if(root == NULL) return NULL;

        if(root->val == key){
            //case-1 both child null
            if(root->left == NULL and root->right == NULL){
                return NULL;
            }

            //case-2 left is null
            else if(root->left == NULL and root->right != NULL ){
                return root->right;
            }

            //case-3 right is null
            else if(root->left != NULL and root->right == NULL ){
                return root->left;
            }

            //case-4 find pre-order successor
            else{
                findInorderPredessor(root);
                // root->left = deleteNodeBst(root->left,key);
            }
        }

        root->left = deleteNodeBst(root->left,key);
        root->right = deleteNodeBst(root->right,key);

        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        root = deleteNodeBst(root,key);


        return root;
        
    }
};

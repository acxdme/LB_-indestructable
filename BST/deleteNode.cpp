// lc - 450
// tc : O(N)
// sc : O(h) , height of the bst

class Solution {
public:
    int findInorderPredessor(TreeNode* root) {
        while (root->right != NULL) {
            root = root->right;
        }

        return root->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        // base-case
        if (root == NULL)
            return root;

        // key-found
        if (key == root->val) {
            // case-1 : leaf Node
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }
            // case-2 : left subTree exists
            if (root->left != NULL && root->right == NULL) {
                TreeNode* left = root->left;
                delete root;
                return left;
            }
            // case-3 : right subTree exists
            if (root->right != NULL && root->left == NULL) {
                TreeNode* right = root->right;
                delete root;
                return right;
            }
            // case-4 : both subTree eixits
            if (root->right != NULL && root->left != NULL) {
                int inorderPredessor = findInorderPredessor(root->left);
                ;
                root->val = inorderPredessor;
                root->left = deleteNode(root->left, inorderPredessor);
            }
        } else if (key > root->val) { // go right
            root->right = deleteNode(root->right, key);
        } else { // go left
            root->left = deleteNode(root->left, key);
        }
        return root;
    }
};

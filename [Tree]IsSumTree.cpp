/*
  Time complexity : O(N^2)
*/

class Solution {
public:
    bool isSumTree(Node* root) {
        if (root == NULL) {
            return true;  // Empty tree is a Sum Tree
        }
        if (root->left == NULL && root->right == NULL) {
            return true;  // Leaf node is a Sum Tree
        }
        
        int leftSum = sumTree(root->left);
        int rightSum = sumTree(root->right);
        
        return (root->data == leftSum + rightSum && isSumTree(root->left) && isSumTree(root->right));
    }
    
    int sumTree(Node* root) {
        if (root == NULL) {
            return 0;
        }
        if (root->left == NULL && root->right == NULL) {
            return root->data;
        }
        return root->data + sumTree(root->left) + sumTree(root->right);
    }
};

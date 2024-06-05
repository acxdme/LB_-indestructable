// lc- 543
// tc : O(N^2)
// sc : O(N) , considering recursive stack.

class Solution {
public:
    int height(TreeNode* root){
        //base-case
        if(root == NULL){
            return 0;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        int h =  1 + max(leftHeight,rightHeight);

        return h;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        //base-case;
        if(root == NULL){
            return 0;
        }

        int l1 = diameterOfBinaryTree(root->left); // diameter from left subtree
        int l2 = diameterOfBinaryTree(root->right); // diameter from right subtree
        int l3 = height(root->left) + height(root->right); // height from left + height from right ( Note : ye +1/-1 ka dhyan rakhna hai)

        int res = max(l1,max(l2,l3));

        return res;
 
    }
};
-------------------------------------------------------------------------------------------------------------
    Method-2 Fast way to find diameter of a tree
 TC : O(N)
 SC : O(log N)

class Solution {
public:
    int D = 0;
    int getDiameter(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int left = getDiameter(root->left);
        int right = getDiameter(root->right);

        int curD = left + right;
        D = max (D,curD);

        return  1 + max(left , right) ;

    }
    int diameterOfBinaryTree(TreeNode* root) {

        if(root == NULL) return 0;
        int ans = getDiameter(root);

        return D;
        
    }
};


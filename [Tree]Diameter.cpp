/*
  Get clarity from the question as to what is considered height , # of nodes or # of edges.
*/
class Solution {
public:
    int height(TreeNode* root){
        if(root == NULL) return 0;

        int ans = 1+ max(height(root->left) , height(root->right));

        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        
        // diameter of left subtree
        int a = diameterOfBinaryTree(root->left);
        // diameter of right subtree
        int b = diameterOfBinaryTree(root->right);
        //height of root's left + height of root's right (including the root)
        int c = height(root->left)  + height(root->right);
        
        // ans is maximum of option a , b and c.
        int ans = max(a,max(b,c));

        return ans;
    }
};

//Method-2
/*
Time complexity : O(N)
Space complexity :O(N)
*/
/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    
    int solve(Node* root, int& mx){
        if(root == NULL) return 0;
        
        int l = solve(root->left,mx);
        int r = solve(root->right,mx);
        mx = max(mx,l + r + 1 );
        
        return  1 + max(l,r);
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        
        int mx = 0;
        int temp = solve(root,mx);
        
        return mx;
        
    }
};

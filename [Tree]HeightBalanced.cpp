/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public: 

    int height (TreeNode* root){
        if(root == NULL) return 0;

        int a = height(root->left);
        int b = height(root->right);

        int ans = 1 + max(a ,b);

        return ans;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;

         int lheight = height(root->left);
         int rheight = height(root->right);

         int h = abs(lheight - rheight);
         
         return  (h<=1) && isBalanced(root->left) && isBalanced(root->right) ;
         
    }
};
------------
    //Method-2
    //Fast method to find if tree is balanced or not
    
  /*
    Time complexity : O(N)
 */
class Solution {
public:
    pair<int,bool> solve(TreeNode* root){
        if( root == NULL) return make_pair(0,true);


        pair<int,bool> left = solve(root->left);
        left.first += 1;

        pair<int,bool> right = solve(root->right);
        right.first += 1;


        return make_pair(max(left.first,right.first), left.second && right.second && abs(left.first - right.first) <= 1 );
    }
    bool isBalanced(TreeNode* root) {
        
        pair<int,bool> ans ;
        ans = solve(root);

        return ans.second;
    }
};

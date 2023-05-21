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
    void findInorder(TreeNode* root,vector<int>& inorder){
       if(root == NULL) return;
       findInorder(root->left,inorder);

       inorder.push_back(root->val);
       findInorder(root->right,inorder);
       
    }
    bool findTwosum(vector<int> inorder,int& k){
        int s = 0;
        int e = inorder.size()-1;
        while(s < e){
            if(inorder[s] + inorder[e] == k)
             return true;
            else if(inorder[s]+inorder[e] > k){
                e--;
            }
            else{
                s++;
            }
        }
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) return false;

        vector<int> inorder;

        //find inorder of given BST
        findInorder(root,inorder);

        bool ans = findTwosum(inorder,k);

        return ans;
        
    }
};

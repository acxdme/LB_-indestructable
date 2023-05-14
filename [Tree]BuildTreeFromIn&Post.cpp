class Solution {
public:
    int findPosition(vector<int>& inorder,int target , int size){
        int position = -1;
        for(int i =0 ;i< size;i++){
            if(target == inorder[i]){
                position = i;
                break;
            }
        }
        return position;
    }

    TreeNode* solve(vector<int>inorder,vector<int> &postorder, int inorderStart,int inorderEnd, int &postorderIndex, int &n){
        if(postorderIndex < 0 || inorderStart > inorderEnd) return NULL;

        int position = findPosition(inorder,postorder[postorderIndex],n);
        TreeNode* root = new TreeNode(postorder[postorderIndex--]);

        root->right = solve(inorder,postorder,position+1,inorderEnd,postorderIndex,n);
        root->left = solve(inorder,postorder,inorderStart,position-1,postorderIndex,n);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        int inorderStart = 0;
        int inorderEnd = n-1;
        int postorderIndex = n-1;

        TreeNode* root = NULL;
         root = solve(inorder,postorder,inorderStart,inorderEnd,postorderIndex,n);

         return root;
    }
};

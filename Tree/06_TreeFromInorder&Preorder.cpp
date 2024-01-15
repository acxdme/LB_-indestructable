//lc-105
//tc: O(N)
//sc: O(N) , for creating nodes of the tree

//Construct Binary Tree from Preorder and Inorder Traversal

 #include<map>
class Solution {
public:

    // find position function
    int findPosition(vector<int>& preorder , vector<int>& inorder,int &size,int &index){
        int target = preorder[index];
        for(int i = 0 ; i <= size ; i++){
            if(inorder[i] == target){
                return i;
            }
        }

        return -1;
    }

    TreeNode* helper(vector<int>& preorder , vector<int>& inorder,int &size,int &index ,int inStart,int inEnd){
        //base-case
        if(index >= size){
            return NULL;
        }
        if(inStart > inEnd){
            return NULL;
        }

        // create node
        TreeNode* node = new TreeNode(preorder[index]);

        // find position in inorder
        int pos = findPosition(preorder,inorder,size,index);

        //increment index
        index++;

        // recursive call for left subTree
        node->left = helper(preorder,inorder,size,index,inStart,pos-1);
        // recursive call for right subTree
        node->right = helper(preorder,inorder,size,index,pos+1,inEnd);

        return node;


    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int index = 0;
        TreeNode* root = helper(preorder,inorder,n,index,0,n-1);

        return root;
    }
};

// lc - 236
// tc : O(N)
// sc : O(log N)

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //base-case
        if(root == NULL){
            return NULL;
        }
        //found p node
        if(root == p){
            return p;
        }
        // found q node
        if(root == q){
            return q;
        }

        TreeNode* leftAnswer = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightAnswer = lowestCommonAncestor(root->right,p,q);

        if(leftAnswer == NULL && rightAnswer != NULL){
            return rightAnswer;
        }
        else if(rightAnswer == NULL && leftAnswer != NULL){
            return leftAnswer;
        }
        else if(rightAnswer == NULL && leftAnswer == NULL){
            return NULL;
        }
        else{
            return root;
        }
    }

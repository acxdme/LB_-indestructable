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

        // left ka answer
        TreeNode* leftAnswer = lowestCommonAncestor(root->left,p,q);
        // right ka answer
        TreeNode* rightAnswer = lowestCommonAncestor(root->right,p,q);

        // right se answer aaya , rightAnswer hi return kardo (p,q right mei hai)
        if(leftAnswer == NULL && rightAnswer != NULL){
            return rightAnswer;
        }
        // left se answer aaya , leftAnswer hi return kardo
        else if(rightAnswer == NULL && leftAnswer != NULL){
            return leftAnswer;
        }
        // left and right dono se answer nahi mila , return NULL
        else if(rightAnswer == NULL && leftAnswer == NULL){
            return NULL;
        }
        // left se answer aaya and right se bhi answer aaya , ab root kardo return
        else{
            return root;
        }
    }

// lc-100
// tc : O(N)
// sc : O(log N) , height of the tree as that much max space will be occupied during recursion

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        //base-case
        if(p == NULL && q == NULL){
            return true;
        }
        if((p == NULL && q != NULL) || (q == NULL && p != NULL)){
            return false;
        }
        if(p->val != q->val){
            return false;
        }

        bool leftLST = isSameTree(p->left ,q->left);
        bool rightLST = isSameTree(p->right ,q->right);


        return leftLST && rightLST;
        
    }
};

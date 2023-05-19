/*
 Time complexity : O(N)
 
 Space complexity : O(N) , considering recursion stack.
 
 Approach : It's purely a range play game.
*/


class Solution {
public:
    bool solve(TreeNode* root , long double mn ,  long double mx){
        if(root == NULL) return true;

        if(root->val <= mn || root->val >= mx){
            return false;
        }

        bool left = solve(root->left,mn ,root->val);
        bool right = solve(root->right,root->val,mx);

        return left && right;
    }
    bool isValidBST(TreeNode* root) {
       long double  mn = -pow(2,31)-1 ;
       long  double  mx = pow(2,31);

        bool ans = solve(root,mn,mx);


        return ans;
        
    }
};

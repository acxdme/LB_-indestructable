// lc - 637
// tc : O(N)
// sc : O(N)

class Solution {
public:

    void levelOrderTraversal(TreeNode* root , vector<double>& result ){

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        double sum = 0.0;
        int count = 0;
        while(!q.empty()){

            TreeNode* front = q.front();
            q.pop();


            if(front != nullptr){
                count++;
                sum += front->val;

                if(front->left != nullptr){
                    q.push(front->left);
                }
                if(front->right != nullptr){
                    q.push(front->right);
                }

            }
            else{
                if(!q.empty()){
                    q.push(nullptr);
                }
                result.push_back(sum/count);
                sum = 0.0;
                count = 0;
            }
            
        }
    }
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> result;
        if(root == NULL)  return result;
        levelOrderTraversal(root,result);

        return result;
        
    }
};

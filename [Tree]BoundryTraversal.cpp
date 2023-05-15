class Solution {
public:
    
    void leftBoundry(Node* root, vector<int>& ans){
        if((root == NULL) || (root->left == NULL and root->right == NULL) ) return;
         
        ans.push_back(root->data);
        if(root->left){
            leftBoundry(root->left,ans);
        }else{
            leftBoundry(root->right,ans);
        }
    }
    
    void rightBoundry(Node* root ,vector<int>& ans){
       if((root == NULL) || (root->left == NULL and root->right == NULL) ) return;
         
        if(root->right){
            rightBoundry(root->right,ans);
        }else{
            rightBoundry(root->left,ans);
        }
        ans.push_back(root->data);
    }
    
    void bottomBoundry(Node* root ,vector<int>& ans){
        if(root == NULL) return ;
        if(root->left == NULL and root->right == NULL){
            ans.push_back(root->data);
        }
        
        bottomBoundry(root->left,ans);
        bottomBoundry(root->right,ans);
        
    }
    
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        if(root == NULL) return ans;
        if(root->left == NULL and root->right == NULL){
            ans.push_back(root->data);
            return ans;
        }
        ans.push_back(root->data);
        // step-1 , left boundry
        leftBoundry(root->left,ans);
        // step-2 , leaf nodes
        bottomBoundry(root,ans);
        // step-3 , right nodes
        rightBoundry(root->right,ans);
    }
};

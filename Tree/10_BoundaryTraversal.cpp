// gfg :https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
// sc : O(h) , h is the max height of the tree

 void leftBoundary(Node* node,vector<int> &result ){
        //base-case
        if(node == NULL ) {
            return;
        }
        
        //leaf-node
        if(node->left == NULL && node->right == NULL){
            return;
        }
        
        // insert node's data into result
        result.push_back(node->data);
        
        
        if(node->left){
            leftBoundary(node->left,result);
        }
        else{
            leftBoundary(node->right,result);
        }
        
    }
    
    void bottomBoundary(Node* node, vector<int> &result){
        //base-case
        if(node == NULL){
            return;
        }
        
                
        //leaf-node
        if(node->left == NULL && node->right == NULL){
            result.push_back(node->data);
            return;
        }
        
        bottomBoundary(node->left,result);
        bottomBoundary(node->right,result);
        
    }
    
        void rightBoundary(Node* node,vector<int> &result ){
        //base-case
        if(node == NULL) {
            return;
        }
                
        //leaf-node
        if(node->left == NULL && node->right == NULL){
            return;
        }
        
        // if node has right subtree move there
        if(node->right){
            rightBoundary(node->right,result);
        }
        else{
            rightBoundary(node->left,result);
        }
        
        // insert node's data into result
        // cout<<"-"<<node->data<<" "<<endl;
        result.push_back(node->data);
    }
    
    
    
    vector <int> boundary(Node *root)
    {
       vector<int> result;
       if(root == NULL) return result;
       
       // insert root's data into result.
      result.push_back(root->data);
       
       //left-boundary
      leftBoundary(root->left,result);
       
       //leaves
      bottomBoundary(root,result);
       
       //right-boundary
       rightBoundary(root->right,result);
       
       return result;
    }

//------------------------------------------------------------------------------------------
// 1 critical test case updated (only node is the root node)


class Solution {
    
 void leftBoundary(Node* node,vector<int> &result ){
        //base-case
        if(node == NULL ) {
            return;
        }
        
        //leaf-node
        if(node->left == NULL && node->right == NULL){
            return;
        }
        
        // insert node's data into result
        result.push_back(node->data);
        
        
        if(node->left){
            leftBoundary(node->left,result);
        }
        else{
            leftBoundary(node->right,result);
        }
        
    }
    
    void bottomBoundary(Node* node, vector<int> &result){
        //base-case
        if(node == NULL){
            return;
        }
        
                
        //leaf-node
        if(node->left == NULL && node->right == NULL){
            result.push_back(node->data);
            return;
        }
        
        bottomBoundary(node->left,result);
        bottomBoundary(node->right,result);
        
    }
    
        void rightBoundary(Node* node,vector<int> &result ){
        //base-case
        if(node == NULL) {
            return;
        }
                
        //leaf-node
        if(node->left == NULL && node->right == NULL){
            return;
        }
        
        // if node has right subtree move there
        if(node->right){
            rightBoundary(node->right,result);
        }
        else{
            rightBoundary(node->left,result);
        }
        
        // insert node's data into result
        // cout<<"-"<<node->data<<" "<<endl;
        result.push_back(node->data);
    }
    
    
public:   
    vector <int> boundary(Node *root)
    {
       vector<int> result;
       if(root == NULL) return result;
       
       
       // insert root's data into result.
      result.push_back(root->data);
       // just root node [this is the only validation.]
       if(root ->left == NULL && root->right == NULL)
       return result;
       
       
       //left-boundary
      leftBoundary(root->left,result);
       
       //leaves
      bottomBoundary(root,result);
       
       //right-boundary
       rightBoundary(root->right,result);
       
       return result;
    }
};

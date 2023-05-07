/*
  Problem : Convert this to a tree where value of each node will be the sum 
            of the values of all the nodes in left and right sub trees of the original tree.
  Time complexity : O(N)
*/
class Solution {
  public:
  

    int solve(Node* root){
        //base-case
        if(root == NULL ) return 0;
        
        int leftsum = solve(root->left);
        int rightsum = solve(root->right);
        
        int sum = 0;
        if(root->left == NULL && root->right == NULL)
        {
            sum = root->data;
            root->data = 0;
        }else{
            sum = root->data + leftsum + rightsum;
            root->data = leftsum + rightsum;
        }
        
        return sum;
        
        
    }
    void toSumTree(Node *node)
    {
        if(node == NULL) return;
        
       int ans = solve(node);
        
    }
};

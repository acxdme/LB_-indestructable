/*
 Time-complexity : O(N)
 
*/
bool solve(Node* root ,int &k , int node , int &ans){
    if(root == NULL) return false;
    if(root->data == node ) return true;

    bool left = solve(root->left,k,node,ans);
    bool right = solve(root->right,k,node,ans);
    
    if(left  || right ) k--;
    
    if(k == 0 ) {
        ans = root->data;
        k = -1;
    }
    
    return (left || right);
    
} 
int kthAncestor(Node *root, int k, int node)
{
    int ans = -1 ;
    bool temp = solve(root , k ,node ,ans);
    if(temp == false) return -1;
    
    return ans;
}

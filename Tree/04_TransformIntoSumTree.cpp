//gfg
// tc : O(N)
// sc : O(log N)

    int convert(Node* root){
        
        //base-case
        if(root == NULL){
            return 0;
        }
        
        
        // leaf-node
        if(root->left == NULL && root->right == NULL){
            int val = root->data;
            root->data = 0;
            return val;
        }
        
        int left = convert(root->left);
        int right = convert(root->right);
        
        int val = root->data;
        int sum = left + right ;
        
        root->data = sum;
        return sum + val;
        
    }
    void toSumTree(Node *node)
    {
        
        int total = convert(node);
        return ;
    }

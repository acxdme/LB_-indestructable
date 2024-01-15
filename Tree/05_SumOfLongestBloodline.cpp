// gfg 
// tc: O(N)
// sc : O(logN)

 void sumOfBloodline(Node* node,int sum ,int &ans,int len , int &maxLen){
        
        //base-case
        if(node == NULL){
            return;
        }
        
        sum = sum + node->data;
        len++;
        //leaf-node
        if((node->left == NULL) && (node->right == NULL)){
            if(len == maxLen){
                    ans = max(sum,ans) ;
                    maxLen = len;
            }
            if(len > maxLen){
                ans = sum;
                maxLen = len;
            }
        }
        
        sumOfBloodline(node->left,sum ,ans,len,maxLen);
        sumOfBloodline(node->right,sum,ans,len,maxLen);
        
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
       if(root == NULL) {
           return 0;
       }
       int len = 0;
       int maxLen = INT_MIN;
       int ans = INT_MIN;
       
       sumOfBloodline(root,0,ans,len,maxLen);
       
       return ans;
    }

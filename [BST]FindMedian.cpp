/*
  Time complexity: O(N)
  Space complexity : O(1) , ignoring recursion stack
*/

void findTotalNodes(Node* root ,int& nodes){
    if(root == NULL) return;
    findTotalNodes(root->left,nodes);
    nodes++;
    findTotalNodes(root->right,nodes);
    
}

void findMedian(Node* root ,int& nodes,float& median,int& k){
    if(root == NULL) return;

    
    findMedian(root->left,nodes,median,k);
    
    // cout<<root->data<<" "<<k<<endl;
    if(nodes % 2 == 0 && ( k == (nodes/2) || k == (nodes/2 +1) ) ){
        // cout<< root->data <<" "<<k<<endl; 
        median += root->data;
    }
    if((nodes % 2 == 1) && (k == (nodes+1)/2)){
        // cout<< root->data <<" "<<k<<endl; 
        median += root->data;
    }
    k = k-1;
    findMedian(root->right,nodes,median,k);
    
}
float findMedian(struct Node *root)
{
      int nodes = 0;
      findTotalNodes(root,nodes);
    //   cout<<nodes<<endl;
      float median = 0.0;
      int k = nodes;
      findMedian(root,nodes,median,k);
       
      if(nodes % 2 == 0) return median/2;
     return median;
}

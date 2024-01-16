// tc : O(N)
// sc : O(N)
// gfg

void findLeftView(Node* root ,map<int ,int> &levelMapping){

    //create queue <node,level>
     queue<pair<Node*,int>> q;
     // push root & initialize mapping with <0,root->data>
     q.push({root,0});
     levelMapping[0] = root->data;
     
     // level order traversal
     while(!q.empty()){
         pair<Node*,int> top = q.front();
         q.pop();
         
         Node* node = top.first;
         int level = top.second;
         
         if(levelMapping.find(level) == levelMapping.end()){
             levelMapping[level] = node->data;
         }
         if(node->left){
             q.push({node->left,level+1});
         }
         if(node->right){
             q.push({node->right,level+1});
         }
     }
     
    
    
}

vector<int> leftView(Node *root)
{
   vector<int> result;
   if(root == NULL) {
       return result;
   }
   map<int ,int> levelMapping;
   
   findLeftView(root, levelMapping);
   
   for(auto item : levelMapping){
       result.push_back(item.second);
   }
   
   return  result;
   
}

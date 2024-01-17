// gfg : https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
// tc- O(N)
// sc - O(N) , auxillary space for creating map.

 void getTopView(Node* root,map<int,int> &mapping){
        //base-case
        if(root == NULL){
            return;
        }
        
        // create queue of <node,hd>
        queue<pair<Node*,int>> q; 
        // push <root,0>
        q.push({root,0});
        
        //hd-order traversal
        while(!q.empty()){
            pair<Node*,int> front = q.front();
            q.pop();
            Node* node = front.first;
            int hd = front.second;
            
            // check in mapping
            if(mapping.find(hd) == mapping.end()){
                mapping[hd] = node->data;
            }
            
            //if node->left , push in queue
            if(node->left != NULL){
                q.push({node->left,hd-1});
            }
            //if node->right , push in queue
            if(node->right != NULL){
                q.push({node->right,hd+1});
            }
        }
    }
    vector<int> topView(Node *root)
    {
       vector<int> result;
       if(root == NULL){
           return result;
       }
       
       map<int,int> mapping;
       
       getTopView(root,mapping);
     
       for(auto item : mapping){
           result.push_back(item.second);
       }
       
       return result;
    }


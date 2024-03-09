// lc - 116 
// tc : O(N)
// sc : O(N)

class Solution {
public:
    Node* connect(Node* root) {

        if(root == NULL) return root;
        
        Node* curr = root;
        queue<Node*> q;

        q.push(curr); // push the root
        q.push(nullptr); // push the nullptr marker

        //while q is not empty, do LOT
        while(!q.empty()){
            Node* front = q.front();
            q.pop();

            if(front != nullptr){
                front->next = q.front(); // linking to the right node 


                if(front->left != nullptr){
                    q.push(front->left); // push left
                }
                if(front->right != nullptr){
                    q.push(front->right); // push right
                }
            }

            else if (!q.empty()){
                q.push(nullptr);
            }
        }

        return root;
        
    }
};

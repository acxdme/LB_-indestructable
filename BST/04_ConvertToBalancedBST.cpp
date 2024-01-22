// gfg : https://www.geeksforgeeks.org/problems/normal-bst-to-balanced-bst/1
// tc : O(N)
// sc : O(N)

class Solution{
    
    public:
    void getInorder(Node* root,vector<int> &inorder){
        if(root == NULL) return;
        
        //left
        getInorder(root->left,inorder);
        //node
        inorder.push_back(root->data);
        //right
        getInorder(root->right,inorder);
    }
    
    Node* buildTreeHelper(vector<int> &inorder , int start,int end){
        
        if(start <= end){
        
        int mid = start + (end-start)/2;
        
        Node* root = new Node(inorder[mid]);
        
        root->left = buildTreeHelper(inorder,start,mid-1);
        
        root->right = buildTreeHelper(inorder,mid+1,end);
        
        return root;
            
        }
        else {
            return NULL;
        }
        
    }
    
    Node* buildTree(vector<int> &inorder){
        
        int start = 0;
        int end = inorder.size() -1;
        
        Node* root = buildTreeHelper(inorder,start,end);
        
        
        return root;
        
        
    }
    Node* buildBalancedTree(Node* root)
    {
        //edge-case
        if(root == NULL){
            return root;
        }
        vector<int> inorder;
    	// get inorder of the given bst
    	getInorder(root,inorder);
    	
    	
    	
    	// construct balanced bst from the given inorder
    	Node* r = buildTree(inorder);
    	
    	return r;
    }
};


//{ Driver Code Starts.

Node* insert(struct Node* node, int key){
	if (node == NULL) return new Node(key);
	if (key < node->data)
		node->left = insert(node->left, key);
	else if (key > node->data)
		node->right = insert(node->right, key);
	return node;
}

void preOrder(Node* node)
{
	if (node == NULL)return;
	printf("%d ", node->data);
	preOrder(node->left);
	preOrder(node->right);
}

int height(struct Node* node) 
{
  if (node==NULL) 
    return 0;
  int lDepth = height(node->left);
  int rDepth = height(node->right);
  if (lDepth > rDepth) 
    return(lDepth+1);
  else 
    return(rDepth+1);
} 
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

Node* buildBalancedTree(Node* root);

int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        struct Node *root = NULL;
        int n, temp;
        string tree;
        getline(cin,tree);
        root = buildTree(tree);
        // cout<<height(root)<<endl;
        Solution obj;
        root = obj.buildBalancedTree(root);
        cout<<height(root)<<endl;
    }
	return 0;
}

// } Driver Code Ends

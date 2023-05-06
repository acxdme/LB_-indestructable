#include <iostream>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }


};

// Function to build a binary tree using recursion
Node* buildTree() {
    int val;
    cout << "Enter node value (or -1 to create a NULL child node): ";
    cin >> val;

    if (val == -1) {
        cout << "NULL node created." << endl;
        return NULL;
    }

    Node* node = new Node(val);

    cout << "Building left subtree of " << val << "..." << endl;
    node->left = buildTree();

    cout << "Building right subtree of " << val << "..." << endl;
    node->right = buildTree();

    return node;
}

void inorderTraversal(Node* root) {
    if (root == NULL) return;

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void levelOrderTraversal(Node* root) {

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        //obtain front
        Node* front = q.front();
        // print front
        cout << front->data << " ";
        // pop front
        q.pop();
        
        //push the children of front
        if (front->left) q.push(front->left);
        if (front->right) q.push(front->right);
    }


}


int main()
{
    int data;

    Node* root = buildTree();

    cout << "Level order traversal" << endl;
    inorderTraversal(root);

    cout <<"Level order traversal"<< endl;
    levelOrderTraversal(root);

    return 0;

}

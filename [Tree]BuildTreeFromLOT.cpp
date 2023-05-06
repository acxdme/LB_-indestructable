#include <iostream>
#include <queue>

using namespace std;

class treeNode {
public:

    int data;
    treeNode* left;
    treeNode* right;

    treeNode(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

treeNode* buildTree() {
      
    cout << "Enter data for node :" << endl;
    int data;
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    treeNode* root = new treeNode(data);

    cout << "create left subtree of " << data << endl;
    root->left = buildTree();
    cout << "create right subtree of " << data << endl;
    root->right = buildTree();

    return root;
}

void levelOrderTraversal(treeNode* root) {
    if (root == NULL) return;
    cout << "here" << endl;
    queue<treeNode*> q;
    q.push(root);
    while (!q.empty()) {
        treeNode* front = q.front();
        q.pop();
        cout << front->data << " ";
        if (front->left) q.push(front->left);
        if (front->right) q.push(front->right);
    }
    cout << endl;
   

}

// buildTree from user provided inorder.
treeNode* buildTreeFromInorder(queue<int>& q) {

    int front = q.front();
    q.pop();
    if (front == -1) return NULL;
    treeNode* root = new treeNode(front);
    root->left = buildTreeFromInorder(q);
    root->right = buildTreeFromInorder(q);

    return root;


}

void markedLevelOrderTraversal(treeNode* root) {
    if(root == NULL) return;

    queue<treeNode*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        treeNode* front = q.front();
        q.pop();
        if (front  == NULL) {
            if (q.empty()) return;
            else {
                cout << endl;
                q.push(NULL);
            }
        }
        else {
            cout << front->data << " ";
            if (front->left) q.push(front->left);
            if (front->right) q.push(front->right);
        }


    }

}

int main()
{
    // build Tree recursively
    treeNode* root = buildTree();
    levelOrderTraversal(root);
    //markedLevelOrderTraversal(root);

    queue<int> q;
    q.push(200);
    q.push(400);
    q.push(600);
    q.push( -1);
    q.push(800);
    q.push(-1);
    q.push(-1);
    q.push(-1);
    q.push(-1);

    treeNode* root1 = buildTreeFromInorder(q);
    cout << endl;
    levelOrderTraversal(root1);
    markedLevelOrderTraversal(root1);

    return 0;
}

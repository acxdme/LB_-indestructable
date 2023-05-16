#include <iostream>
#include<vector>
#include <queue>

using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void BuildBst(TreeNode* root , int data) { //10 20 30 -1
    if (data == -1) return;

    if (data > root->data) {
        if (root->right == NULL) root->right = new TreeNode(data);
        else {
        BuildBst(root->right, data);
        }
    }
    else {
        if (root->left == NULL) root->left = new TreeNode(data);
        else {
            BuildBst(root->left, data);
        }
    }
}

void levelorderTraversal(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        TreeNode* front = q.front();
        q.pop();
        if (front == NULL) {
            cout << endl;
            if (!q.empty()) {
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
    cout << "Enter value for root" << endl;
    int data;
    cin >> data;
    TreeNode* root = new TreeNode(data);
    if (data == -1) {
        cout << "Root is NULL" << endl;
        return 0;
    }
    bool val = true;
    while (val) {
        cout << "Enter node data to be inserted in BST " << endl;
        int val;
        cin >> val;
        if (val == -1) {
            cout << "Build completed" << endl;
            val = false;
            break;
        }
        BuildBst(root, val);
    }

    // level order traversal for verification
    levelorderTraversal(root);




}

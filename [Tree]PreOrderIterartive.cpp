#include <iostream>
#include <queue>
#include <stack>

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
    if (root == NULL) return;

    queue<treeNode*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        treeNode* front = q.front();
        q.pop();
        if (front == NULL) {
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

// Iterative pre-order approach using stack data structure.
void preorderTraversal(treeNode* root) {
    stack<treeNode*> st;
    st.push(root);
    while (!st.empty()) {
        treeNode* top = st.top();
        st.pop();
        cout << top->data << " ";
        if (top->right) st.push(top->right);
        if (top->left) st.push(top->left);
    }
    cout << endl;

}

int main()
{

    //buildTreeFromInorder
    queue<int> q;
    q.push(10);
    q.push(60);
    q.push(80);
    q.push(-1);
    q.push(-1);
    q.push(20);
    q.push(70);
    q.push(-1);
    q.push(-1);
    q.push(40);
    q.push(-1);
    q.push(-1);
    q.push(30);
    q.push(50);
    q.push(-1);
    q.push(-1);
    q.push(-1);

    treeNode* root1 = buildTreeFromInorder(q);

    cout << "marked inorder traversal: " << endl;
    markedLevelOrderTraversal(root1);

    cout << endl << "Pre-order traversal : ";
    preorderTraversal(root1);

    return 0;
}

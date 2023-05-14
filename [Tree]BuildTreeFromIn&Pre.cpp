#include <iostream>
#include<queue>
#include<vector>

using namespace std;

class TreeNode{
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

int findPosition(vector<int> inorder , int target) {
    int targetIndex = -1;
    for (int i = 0; i < inorder.size(); i++) {
        if (inorder[i] == target) {
            targetIndex = i;
            break;
        }
    }

    return targetIndex;
}

TreeNode* buildTreeFromInorderPreorder(vector<int> inorder, vector<int>& preorder,int inorderStart ,int inorderEnd,int &preOrderIndex)
{
    //base case 
    if (preOrderIndex > preorder.size() - 1 || inorderStart > inorderEnd) return NULL;

    int  position = findPosition(inorder,preorder[preOrderIndex]);
    TreeNode* root = new TreeNode(preorder[preOrderIndex++]);
    //cout << root->data << " ";
    root->left = buildTreeFromInorderPreorder(inorder, preorder, inorderStart, position - 1, preOrderIndex);
    root->right = buildTreeFromInorderPreorder(inorder, preorder, position+1, inorderEnd, preOrderIndex);


    return root;

}

void levelOrderTraversal(TreeNode* root)
{
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
    vector<int> inorder = { 3,1,4,5,2 };
    vector<int> preorder = { 5,1,3,4,2 };
    int preorderIndex = 0;
    int inorderStart = 0;
    int inorderEnd = preorder.size() - 1;
    int position = 0;

    TreeNode* root = NULL;

     root = buildTreeFromInorderPreorder(inorder,preorder,inorderStart,inorderEnd,preorderIndex);
    levelOrderTraversal(root);


    return 0;
}

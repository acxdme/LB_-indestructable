#include <iostream>
#include <vector>

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

void convertBstToDll(TreeNode* root, TreeNode* &head) {
    //base-case
    if (root == NULL) return;

    //go recursively for right sub-tree
    convertBstToDll(root->right, head);

    root->right = head;

    if (head != NULL) head->left = root;

    //update head
    head = root;

    //go recursively for right sub-tree
    convertBstToDll(root->left, head);


}

void printLinkedList(TreeNode* head) {
    cout << "printing DLL : " << endl;
    TreeNode* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->right;
    }
}

TreeNode* buildBstFromInorder(vector<int>& inorder, int s, int e) {
    if (s > e) return NULL;

    int mid = (s + e) / 2;
    TreeNode* root = new TreeNode(inorder[mid]);
    root->left = buildBstFromInorder(inorder, s, mid - 1);
    root->right = buildBstFromInorder(inorder, mid + 1, e);
    return root;
}
int main()
{
    TreeNode* root = NULL;
    TreeNode* head = NULL;
    vector<int> inorder = {100,250,400,500,540,600};
    int s = 0;
    int e = inorder.size() - 1;

    root = buildBstFromInorder(inorder, s, e);
    convertBstToDll(root, head);

    printLinkedList(head);

    return 0;
}
        

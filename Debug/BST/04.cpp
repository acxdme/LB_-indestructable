// check if two bst's are identical

void inorder(Node* root, vector<int> &v) {
    if (!root)
        return;
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

bool checkBSTs(Node* root1, Node* root2) {
    if (!root1 && !root2)
        return true;
    if ((root1 && !root2) || (!root1 && root2)) // fix : the 1st condition earlier was incorrect.
        return false;
    vector<int> v1, v2;
    inorder(root1, v1);
    inorder(root2, v2); 
    return (v1 == v2);
}

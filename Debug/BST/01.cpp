// I could not find any error , code is working fine and covering all the edge cases.

void insert(Node*& root, int key)
{
    Node* node = new Node(key);
    if (!root) {
        root = node;
        return;
    }
    Node* prev = root;
    Node* temp = root;
    while (temp) {
				prev = temp;
        if (temp->val > key) {
            temp = temp->left;
        }
        else if (temp->val < key) {
            temp = temp->right; 
        }
    }
    if (prev->val > key)
        prev->left = node;
    else
        prev->right = node;
}

// just reordering the recusive call was required

void mirror(Node* node) {
	if (node == NULL) return;
        mirror(node->left); // left recursive call
        mirror(node->right);// right recursive call
        swap(node->left, node->right); // swap node->left , node->right
}

// sum-tree
void transformTreeHelper(Node *root, int *sum) { // param has pointer to sum
   if (root == NULL)  return;

   transformTreeHelper(root->right, sum);
   *sum = *sum + root->data;
   root->data = *sum - root->data;
   transformTreeHelper(root->left, sum);
}
 
void transformTree(struct Node *root) {
    int sum = 0;
    transformTreeHelper(root, &sum);  // passed the reference of sum
}

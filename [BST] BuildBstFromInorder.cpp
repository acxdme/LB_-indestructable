#include <iostream>
#include<queue>
#include<vector>

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

TreeNode* buildBstFromInorder(vector<int>& inorder, int s ,int e) {
	if (s > e) return NULL;

	int mid = (s + e) / 2;

	TreeNode* root = new TreeNode(inorder[mid]);

	root->left = buildBstFromInorder(inorder, s, mid - 1);

	root->right = buildBstFromInorder(inorder, mid + 1, e);


	return root;



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
	vector<int> inorder = { 1,2,3,4,5,6,7,8,9 };
	TreeNode* root = NULL;
	int s = 0;
	int e = inorder.size() - 1;
	root = buildBstFromInorder(inorder,s,e);
	levelorderTraversal(root);


	return 0;
}


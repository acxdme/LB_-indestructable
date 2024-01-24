// code for bottom view
#include <iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class Node{
  public:
  int data;
  Node* left;
  Node* right;

  Node(int d){
    this->data = d;
    this->left = NULL;
    this->right = NULL;
  }
};

void findBottomView(Node* root)
{
		vector<int> ans;
		if(root == NULL){
		  return ;
    } 
		map<int, int> mp;
		queue<pair<Node*, int>> Q;
		Q.push({root, 0});

		while(!Q.empty()){
			auto it = Q.front();
			Q.pop();
			Node* node = it.first;
			int col = it.second;
			 mp[col] = node->data;

     			 if(node->left != NULL) // validation missing
			Q.push({node->left, col-1});
    		         if(node->right != NULL) // validation missing
			Q.push({node->right, col+1});
		}
		for(auto x:mp){
			ans.push_back(x.second);
      cout << x.second << " ";
		}
}

int main() {
  Node* root = new Node(10);
  root->left = new Node(20);
  root->right = new Node(30);
  root->right->left = new Node(44);
  root->left->left = new Node(29);
  root->left->right = new Node(57);

  findBottomView(root);
  return 0;
}

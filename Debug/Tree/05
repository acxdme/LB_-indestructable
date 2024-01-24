//top view

#include <iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class Node{
  public:
  int data;
  int hd;
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
      // if(mp.find(col) == mp.end()){
			mp[col] = node->data;

      // }
      if(node->left != NULL)
			Q.push({node->left, col-1});
      if(node->right != NULL)
			Q.push({node->right, col+1});
		}
		for(auto x:mp){
			ans.push_back(x.second);
      cout << x.second << " ";
		}
}

void topview(Node* node)
{
    if (node == NULL)
        return;
    queue<Node*> q;
    map<int, int> m;
    int hd = 0;
    node->hd = hd;
    q.push(node);
    m[hd] = node->data;
 
    while (!q.empty()) {
        Node *root = q.front();
        q.pop();
        int _hd = root->hd;
        if (m.count(_hd) == 0)
            m[_hd] = root->data;
        if (root->left != NULL) {
            root->left->hd = _hd - 1;
            q.push(root->left); // when checking left push left
        }
        if (root->right != NULL) {
            root->right->hd = _hd + 1;
            q.push(root->right); // when checking right push right
        }

    }
 
    for (auto [x,y]:m) {
        cout << y << " ";
    }
}

int main() {  
     //            10
     //      20         30
     //   29      57 44
  Node* root = new Node(10);
  root->left = new Node(20);
  root->right = new Node(30);
  root->right->left = new Node(44);
  root->left->left = new Node(29);
  root->left->right = new Node(57);

  // findBottomView(root);
  topview(root);
  return 0;
}

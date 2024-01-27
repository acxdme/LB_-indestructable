#include <iostream>
using namespace std;

class Node{
  public:
  int key;
  Node* left;
  Node* right;

  Node(int data){
    this->key = data;
    this->left = NULL;
    this->right = NULL;
  }
};

void secondLargestUtil(Node *root, int &c) {
    if (root == NULL)
        return;
    secondLargestUtil(root->right, c);
    c++; // increment on coming back from left recursive call
    if (c == 2) {
        c = 3;  // flag something appropriate to make logic correct.
        cout << root->key << endl; 
        return;
    }
    secondLargestUtil(root->left, c);
}

void secondLargest(Node *root) {
    int c = 0;
    secondLargestUtil(root, c);
}

int main() {

  Node* root = new Node(50);
  Node* first = new Node(40);
  Node* second = new Node(60);
  Node* third = new Node(70);
  Node* fourth = new Node(64);

  root->left = first;
  // root->right = second;
  // root->right->right = third;
  // root->right->right->left = fourth;

  secondLargest(root);

  return 0;
}


//--------------------------------------------------------------------------------------------------

//reset karne ki bhi jaroot nahi hai , bas return optimize kar lo
// provided solution :

void secondLargestUtil(Node *root, int &c) {
    if (root == NULL || c >= 2)
        return;
    secondLargestUtil(root->right, c);
    c++;
    if (c == 2) {
        cout << root->key << endl; // Print 2nd Largest Element
        return;
    }
    secondLargestUtil(root->left, c);
}

void secondLargest(Node *root) {
    int c = 0;
    secondLargestUtil(root, c);
}

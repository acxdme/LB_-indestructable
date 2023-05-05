

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }


};

Node* buildTree() {

    int data;
    cin >> data;
    if (data == -1) {
        return NULL;
    }
    
    Node* temp = new Node(data);
    cout << "insert node on left :" << endl;
    temp->left = buildTree();

    cout << "insert node on right :" << endl;
    temp->right = buildTree();

    
}

int main()
{
    Node* root = new Node(0);
    root = buildTree();

    return 0;

}

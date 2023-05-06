

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
    cout << "insert node on left of " << data << " " << endl;
    temp->left = buildTree();

    cout << "insert node on right of "<< data << " " << endl;
    temp->right = buildTree();

    
}

int main()
{
    Node* root = buildTree();
    return 0;

}

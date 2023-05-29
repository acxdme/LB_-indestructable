
/*
 Time complexity : O(N) , just traversing the tree.
 Space complexity : O(N) , consideting recusion stack.
*/
#include <iostream>
#include<limits.h>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->right = NULL;
        this->left = NULL;
    }
};

class test {
public:
    int mn = INT_MAX;
    int mx = INT_MIN;
    int size;
    bool valid;

    test(int size ,int mn ,int mx ,bool valid) {
        this->size = size;
        this->mn = mn;
        this->mx = mx;
        this->valid = valid;
    }
};

test* findLargestBst(Node* root , int& maximumSize) {
    if (root == NULL) {
        test* temp = new test(0, INT_MAX, INT_MIN, true);
        return temp;
    }
    if (root->left == NULL && root->right == NULL) {
        test* temp = new test(1, root->data, root->data, true);
        return temp;
    }

    test* left = findLargestBst(root->left,maximumSize);
    test* right = findLargestBst(root->right,maximumSize);

    test* current = NULL;
    if (root->data > left->mx && root->data < right->mn && left->valid && right->valid) {
        maximumSize = max(maximumSize, 1 + left->size + right->size);
         current = new test(1 + left->size + right->size, root->data, root->data, true);
    }
    else {
        current = new test(1 , root->data, root->data, false);

    }

    return current;

}

int main()
{
    Node* root = new Node(50);
    root->left = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(20);
    root->right = new Node(60);
    root->right->left = new Node(45);
    root->right->right = new Node(70);
    root->right->right->left = new Node(65);
    root->right->right->right = new Node(80);
    int maximumSize = 1;
    test* ans = findLargestBst(root,maximumSize);

    cout << "answer: " << endl;
    cout << maximumSize << endl;

    return 0;
}
//-----------------------------------------
//updated function 
NodeData* findLargestBst(Node* root, int& maximumSize) {
    if (root == NULL) {
        NodeData* temp = new NodeData(0, INT_MAX, INT_MIN, true);
        return temp;
    }
    if (root->left == NULL && root->right == NULL) {
        NodeData* temp = new NodeData(1, root->data, root->data, true);
        return temp;
    }

    NodeData* left = findLargestBst(root->left, maximumSize);
    NodeData* right = findLargestBst(root->right, maximumSize);

    NodeData* current = NULL;
    if (root->data > left->mx && root->data < right->mn && left->valid && right->valid) {
        maximumSize = max(maximumSize, 1 + left->size + right->size);
        current = new NodeData(1 + left->size + right->size, min(root->data,left->mn), max(root->data,right->mx), true);
    }
    else {
        current = new NodeData(1,  min(root->data,left->mn), max(root->data,right->mx), false);

    }

    return current;

}

// Convert sorted DLL to BST
#include <iostream>
#include<queue>


/*
Optimized approach : 
Node* sortedLinkedListIntoBST(Node* &head, int n) {
	//base case
	if(n <= 0 || head == NULL)
		return NULL;

	Node* leftSubtree = sortedLinkedListIntoBST(head, n/2);

	Node* root = head;
	root->left = leftSubtree;

	head = head -> right;
	
	//right part solve karna h 
	root->right = sortedLinkedListIntoBST(head,n-1-n/2);
	return root;
}
*/
using namespace std;

class Node {
public:
    int data;
    Node* left = NULL;
    Node* right = NULL;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->right;
    }

    return;
}

Node* convertDllToBst(Node* head,Node* root, int n) {

    //base-case 
    if (n <= 0) return NULL;
  
    // find mid and place root 
    int mid = n / 2;
    int i = 0;
    Node* temp = head;
    while (i < mid) {
        i++;
        temp = temp->right;

    }
    root = temp;

    // Traverse recursively on the left.
    root->left = convertDllToBst(head, root, n / 2);
     // Traverse recursively on the right.
    root->right = convertDllToBst(temp->right, root,n - n / 2 - 1);
  
    return root;


}

void levelorderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* front = q.front();
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
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);
    Node* sixth = new Node(6);

    head->right = second;
    second->left = head;

    second->right = third;
    third->left = second;

    third->right = fourth;
    fourth->left = third;

    //fourth->right = fifth;
    //fifth->left = fourth;

    //fifth->right = sixth;
    //sixth->left = fifth;

    cout << "Printing Original Linked List: " << endl;
    printLinkedList(head);

    int n = 4;
    
    Node* root = NULL;
    root = convertDllToBst(head,root,n);
    cout << "Printing Level order traversal" << endl;
    levelorderTraversal(root);
    

    return 0;

    
}


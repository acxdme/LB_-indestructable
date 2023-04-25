#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node() {
		this->data = -1;
		this->next = NULL;
	}

	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

void print(Node* head) {
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}cout << endl;
}

int findLength(Node* head) {
	Node* temp = head;
	int length = 0;
	while (temp != NULL) {
		length++;
		temp = temp->next;
	}
	return length;
}

void deleteHead(Node* &head, Node* &tail) {
	if (head == NULL) {
		return;
	}
	Node* temp = head;
	head = head->next;
	temp->next = NULL;
	delete(temp);
}

void deleteTail(Node* &head, Node* &tail) {
	if (head == NULL) {
		return;
	}
	int size = findLength(head);
	Node* temp = head;
	int i = 1;
	while (i < size-1) {
		temp = temp->next;
		i++;
	}
	tail = temp;
	temp = temp->next;
	tail->next = NULL;
	delete(temp);
}

void deleteAtPosition(Node*& head, Node*& tail,int position) {
	if (head == NULL) return;
	if (position == 1) {
		deleteHead(head, tail);
		return;
	}
	int length = findLength(head);
	cout << length << endl;
	if (position >= length) {
		deleteTail(head, tail);
		return;
	}

	int i = 1;
	Node* left = head;
	while (i < position - 1) {
		left = left->next;
		i++;
	}

	Node* temp = left->next;
	Node* right = temp->next;
	left->next = right;
	temp->next = NULL;
	delete(temp);
}

int main()
{
	Node* head = NULL;
	Node* tail = NULL;
	head = new Node(10);
	tail = new Node(90);
	Node* first = new Node(20);
	Node* second = new Node(30);
	Node* third = new Node(40);
	Node* fourth = new Node(50);
	Node* fifth = new Node(60);

	head->next = first;
	first->next = second;
	second->next = third;
	third->next = fourth;
	fourth->next = fifth;
	fifth->next = tail;

	//Delete head from LL 
	
	//deleteHead(head, tail);
	//deleteHead(head, tail);
	//deleteHead(head, tail);

	// Deleting tail from LL
	//deleteTail(head, tail);
	//deleteTail(head, tail);

	// Deleting from a given position
	deleteAtPosition(head, tail, 8);


	cout << "Printing LL: ";
	print(head);
	cout << endl;

}

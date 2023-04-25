
#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node() {
		this->data = 0;
		this->next = NULL;
	}

	Node(int data) {
		this->data = data;
		this->next = NULL;
	}

};

 void print(Node* head) {
	Node* temp = head;
	cout << "Printing LL: " << endl;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
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

 void insertAtHead(Node* &head, Node* &tail, int data) {
	Node* newNode = new Node(data);
	if (head == NULL) {
		head = newNode;
		tail = newNode;
		return;
	}

	newNode->next = head;
	head = newNode;
	//cout << "head ka data : " << head->data << endl;
	//print(head);

	return;
}

 void insertAtTail(Node* &head, Node* &tail, int data) {
	Node* newNode = new Node(data);
	if (head == NULL) {
		head = newNode;
		tail = newNode;
		return;
	}

	tail->next = newNode;
	tail = newNode;

	return;

}

 void insertAtPosition(Node*& head, Node*& tail, int position, int data) {
	 Node* newNode = new Node(data);
	 if (head == NULL) {
		 head = newNode;
		 tail = newNode;
		 return;
	 }

	 if (position == 0) {
		 insertAtHead(head, tail, data);
		 return;
	 }

	 int length = findLength(head);

	 if (position >= length) {
		 insertAtTail(head, tail, data);
		 return;
	 }

	 int i = 1;
	 Node* temp = head;
	 while (i < position) {
		 temp = temp->next;
		 i++;
	 }
	 
	 newNode->next = temp->next;
	 temp->next = newNode;
	 
 }

int main()
{

	Node* head = NULL;
	Node* tail = NULL;
	insertAtHead(head, tail, 20);
	insertAtHead(head, tail, 50);
	insertAtHead(head, tail, 60);
	insertAtHead(head, tail, 90);
	//insertAtTail(head, tail, 77);
	//insertAtTail(head, tail, 67);
	//insertAtTail(head, tail, 67);
	insertAtPosition(head, tail, 4, 12);


	//Node* head = new Node(10);
	//Node* first = new  Node(20);
	//Node* second = new  Node(30);
	//Node* third = new  Node(40);
	//Node* fourth = new  Node(50);
	//
	//head->next = first;
	//first->next = second;
	//second->next = third;
	//third->next = fourth;

	 //insertAtHead(head, fourth, 90);
	 //insertAtHead(head, fourth, 58);

	 //insertAtTail(head, fourth, 89);
	 //insertAtTail(head, fourth, 87);

	print(head);


}

/*
 Time complexity : O(n)
 Space complexity : O(n)
*/

#include <iostream>
#include<queue>

using namespace std;

void print(queue<int> q) {
	while (!q.empty()) {
		int front = q.front();
		cout << front << " ";
		q.pop();
	}cout << endl;

}

void reverseQueue(queue<int>& q) {
	if (q.empty()) return;

	int front = q.front();
	q.pop();

	reverseQueue(q);
	
	q.push(front);
}

int main()
{
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);

	print(q);

	reverseQueue(q);

	print(q);
}

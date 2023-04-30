/*
Time complexity : O(N)
Space complexity : O(N)
*/
#include <iostream>
#include <queue>
#include<stack>

using namespace std;

void print(queue<int> q) {
	while (!q.empty()) {
		int front = q.front();
		cout << front << " ";
		q.pop();
	}cout << endl;

}

void reverseFirstK(queue<int>& q , int &k) {
	if (q.empty()) {
		cout << "queue is empty" << endl;
		return;
	}
	stack<int> st;
	int n = q.size();
	int i = 0;
	while ( i < k) {
		st.push(q.front());
		q.pop();
		i++;
	}

	while (!st.empty()) {
		int top = st.top();
		st.pop();
		q.push(top);
	}

	i = 0;
	while (i < n - k) {
		int front = q.front();
		q.pop();
		q.push(front);
		i++;
	}

}

int main()
{
	// Note :  0 > k <= n

	queue<int> q;
	q.push(3);
	q.push(6);
	q.push(9);
	q.push(2);
	q.push(8);

	cout << "original queue :" << endl;
	print(q);

	int k = 4;
	reverseFirstK(q,k);

	cout << "queue after reversal:" << endl;

	print(q);
}

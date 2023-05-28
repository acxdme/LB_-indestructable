/*
  T.C (for finding median for each streaming character ) : O(log n)
*/
#include <iostream>
#include<queue>
using namespace std;

void findMedian(int stream[],int &index,double & median, priority_queue<int>& mxHeap, priority_queue<int, vector<int>, greater<int>>& mnHeap)
{
	if (mxHeap.size() == mnHeap.size()) {
		if (stream[index] > median) {
			mnHeap.push(stream[index]);
			median = mnHeap.top();
		}
		else {
			mxHeap.push(stream[index]);
			median = mxHeap.top();
		}
	}
	else if (mxHeap.size() > mnHeap.size()) {
		if (stream[index] > median) {
			mnHeap.push(stream[index]);
			median = (mnHeap.top() + mxHeap.top()) / 2.0;
		}
		else {
			int mxTop = mxHeap.top();
			mxHeap.pop();
			mnHeap.push(mxTop);
			mxHeap.push(stream[index]);
			median = (mnHeap.top() + mxHeap.top()) / 2.0;
		}

	}
	else {
		//mxHeap.size() < mnHeap.size()
		if (stream[index] > median) {
			int mnTop = mnHeap.top();
			mnHeap.pop();
			mxHeap.push(mnTop);
			mnHeap.push(stream[index]);
			median = (mnHeap.top() + mxHeap.top()) / 2.0;
		}
		else {
			mnHeap.push(stream[index]);
			median = (mnHeap.top() + mxHeap.top()) / 2;
		}
	}
}
int main()
{
	int stream[8] = { 2,3,4,5,16,7,8,20 };
	int size = 8;
	priority_queue<int> mxHeap;
	priority_queue<int, vector<int>, greater<int>> mnHeap;
	double median = 0;
	for (int i = 0; i < 8; i++) {
		findMedian(stream,i,median,mxHeap,mnHeap);
		cout << "median for stream " << i <<": " << median << endl;
	}
}

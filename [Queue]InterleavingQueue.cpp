#include <iostream>
#include<queue>
#include <stack>


using namespace std;

void print(queue<int> q) {
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        cout << front << " ";
    }cout << endl;
    return;
}

void interleave(queue<int>& q) {
    queue<int> q1;
    int size = q.size();
    int k = size / 2;
    //cout << k << endl;
    int i = 0;
    while (i < k) {
        int front = q.front();
        q.pop();
        q1.push(front);
        i++;
    }//  20 30 10
    // inteleaving pattern
    while (!q1.empty()) {
        int q1Front = q1.front();
        q1.pop();
        q.push(q1Front);
        int qFront = q.front();
        q.pop();
        q.push(qFront);
    }
    cout << i << endl;

    if (size & 1) {
        int element = q.front();
        q.pop();
        q.push(element);
    }

    return;
}

void interleaveQueue(queue<int>& q) {
    //Step A: separate both halves
    int n = q.size();
    if (q.empty())
        return;
    int k = n / 2;
    int count = 0;
    queue<int> q2;

    while (!q.empty()) {
        int temp = q.front();
        q.pop();
        q2.push(temp);
        count++;

        if (count == k)
            break;
    }

    //stepB: interleaving start krdo
    while (!q.empty() && !q2.empty()) {
        int first = q2.front();
        q2.pop();

        q.push(first);

        int second = q.front();
        q.pop();

        q.push(second);
    }
    //odd wala case
    if (n & 1) {
        int element = q.front();
        q.pop();
        q.push(element);
    }
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    //q.push(60);

    cout << "original queue" << endl;
    print(q);

    interleave(q);
    //interleaveQueue(q);

    cout << "interleaved string" << endl;
    print(q);
    return 0;
}


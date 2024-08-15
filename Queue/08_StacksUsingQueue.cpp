// lc - 225
// Tc : push-> O(N) , pop & front -> O(1)

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {}

    void push(int x) {
        while (!q1.empty()) {
            int front = q1.front();
            q1.pop();
            q2.push(front);
        }
        q1.push(x);

        while (!q2.empty()) {
            int front = q2.front();
            q2.pop();
            q1.push(front);
        }
    }

    int pop() {
        int front = q1.front();
        q1.pop();
        return front;
    }

    int top() { return q1.front(); }

    bool empty() { return q1.empty(); }
};

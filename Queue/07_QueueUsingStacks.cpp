// lc - 232
// TC : push-> O(N) , pop & seek -> O(1)
// Method-1

class MyQueue {
public:
    // Method-1
    stack<int> s1;
    stack<int> s2;
    MyQueue() {}

    void push(int x) {
        while (!s1.empty()) {
            int s1Top = s1.top();
            s1.pop();
            s2.push(s1Top);
        }
        s1.push(x);

        while (!s2.empty()) {
            int s2Top = s2.top();
            s2.pop();
            s1.push(s2Top);
        }
    }

    int pop() {
        if (!s1.empty()) {
            int s1Top = s1.top();
            s1.pop();
            return s1Top;
        }

        return -1;
    }

    int peek() {
        if (!s1.empty()) {
            int s1Top = s1.top();
            return s1Top;
        }

        return -1;
    }

    bool empty() { return s1.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

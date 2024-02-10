// something very unusual
// unable to make out the logic .

void streamMedian(int A[], int n) {
    priority_queue<int> g, s;
    for (int i = 0; i < n; i++) {
        s.push(A[i]);
        int temp = s.top();
        s.pop();
        g.push(-1 * temp);
        if (g.size() > s.size()) {
            temp = g.top();
            g.pop();
            s.push(-1 * temp);
        }
        if (g.size() != s.size())
            cout << (double)s.top() << endl;
        else
            cout << (double)((s.top() * 1.0 - g.top() * 1.0)/ 2) << endl;
    }
}

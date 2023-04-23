
#include <iostream>
#include<stack>

using namespace std;

int main()
{
    string t = "ayush";
    stack<char> st;
    for (int i = 0;i < t.size();i++) {
        st.push(t[i]);
    }

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}

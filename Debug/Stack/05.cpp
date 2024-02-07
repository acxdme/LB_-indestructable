// delete element from middle of stack

// i feel my approach(commented code) is correct.

#include <iostream>
#include <stack>
using namespace std;


// void deleteMiddle(stack<int>& s, int k) {
//     stack<int> aux;
//     int count = 0;

//     while (!s.empty()) {
//         int num = s.top();
//         s.pop();
//         aux.push(num);
//         count++;
//         if (count == k) {
//             s.pop();
//             break;
//         }
//     }

//     while (!aux.empty()) {
//         int num = aux.top();
//         aux.pop();
//         s.push(num);
//     }
// }

// int main() {
//     stack<int> s;
//     s.push(1);
//     s.push(2);
//     s.push(3);
//     s.push(4);
//     s.push(5);
//     s.push(6);
//     s.push(7);

//     // delete middle element
//     int k = (s.size() + 1) / 2;
//     deleteMiddle(s, k);

//     // print remaining elements
//     while (!s.empty()) {
//         cout << s.top() << " ";
//         s.pop();
//     }
//     cout << endl;

//     return 0;
// }

void deleteMiddle(stack<int>& s, int k) {
    stack<int> aux;
    int count = 0;

    while (!s.empty()) {
        int num = s.top();
        s.pop();
        aux.push(num);
        count++;
        if (count == k) {
            s.pop();
            break;
        }
    }

    while (!aux.empty()) {
        int num = aux.top();
        aux.pop();
        s.push(num);
    }
}

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);

    // delete middle element
    int k = (s.size() + 1) / 2;
    deleteMiddle(s, k);

    // print remaining elements
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}

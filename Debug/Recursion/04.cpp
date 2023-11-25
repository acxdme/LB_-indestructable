#include <iostream>
using namespace std;

int rec(char input[], int n) {
    if (input[0] == '\0') // not assign but equate whether end of string
        return n;
    n = n * 10 + (input[0] - '0'); // ascii of input char to integer equivalent.
    return rec(input + 1, n);
}

int main() {
    char input[] = "628";
    int n = 0;
    cout << rec(input, n) << endl;
    return 0;
}

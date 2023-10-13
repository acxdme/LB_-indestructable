#include <iostream>
using namespace std;

void reverseString(char input[], int n, int start) {
    for (int i = start, j = n - 1; i < j; i++, j--) { // for loop condition corrected
        int temp = input[i]; // swapping logic correction
        input[i] = input[j];
        input[j] = temp;
    }
}

void reverseEachWord(char input[]) {
    int start = 0, i = 0;
    while (true) {
        i++;

        if ((input[i] == ' ') || (input[i] == '\0')) {
            reverseString(input,i, start);
            start = i + 1;
       
        }
        if (input[i] == '\0') break;
    }
}

int main()
{
    char input[] = "focus mode";
    reverseEachWord(input);
    for (auto ch : input) {
        cout << ch;
    }cout << endl;

    return 0;
}

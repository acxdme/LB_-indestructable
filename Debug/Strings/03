// debug-03

#include <bits/stdc++.h>
using namespace std;

char *removeDuplicate(char str[], int n) {
    // str is a character array and n is the length of the character array
    int index = 0;

    // Traverse through the input string
    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;

        // Check if the current character has already occurred
        for (int j = 0; j < index; j++) {
            if (str[i] == str[j]) {
                isDuplicate = true;
                break;
            }
        }

        // If the character is not a duplicate, add it to the result
        if (!isDuplicate) {
            str[index++] = str[i];
        }
    }

    // Null-terminate the result string
    str[index] = '\0';

    return str;
}

int main() {
    char text[] = "programming";
    int length = strlen(text);

    cout << "Original String: " << text << endl;

    // Call the removeDuplicate function
    removeDuplicate(text, length);

    cout << "String after removing duplicates: " << text << endl;

    return 0;
}

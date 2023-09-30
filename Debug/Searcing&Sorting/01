//Debug the code. This code is implementation for binary search.

//debugged code below
// resoning , the return  statements were not proper in the binary search functions


#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int x) {

    if (right >= left) {
        int mid = (left + right) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] > x) {
            int res = binarySearch(arr, left, mid - 1, x);
            if (res != -1)
                return res;

        }
        else
        {
            int res = binarySearch(arr, mid + 1, right, x);
            if (res != -1)
                return res;
        }
    }
    return -1;
}

int main() {
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 40;
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
        cout << "Element not found.";
    else
        cout << "Element found at index " << result << endl;
    return 0;
}

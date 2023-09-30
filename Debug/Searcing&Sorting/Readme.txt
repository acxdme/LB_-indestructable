# Supreme-Batch-Debug-Exercise-C++ (Week-4)

**NOTE: The code snippet given may be incomplete or have compile time, runtime or logical errors.**

**How to attempt Debugging Exercise?**

1. Copy the code to your code editor (e.g. VS Code).
2. Add relevant header files like “#include <iostream>” etc.
3. Run the code.
4. You will notice the expected output is not printing at the console.
5. Apply your smart coder mind to Debug the code.
6. **Warning**: Only see the solution after you have tried enough.

1. ******Debug the code. This code is implementation for binary search.******

```cpp
#include <iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = (left + right) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] > x)
            binarySearch(arr, left, mid - 1, x);
        else
            binarySearch(arr, mid + 1, right, x);
    }
    return -1;
}

int main() {
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
        cout << "Element not found.";
    else
        cout << "Element found at index " << result << endl;
    return 0;
}
```

[debug-1.txt](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/4790609f-bf18-4760-981b-030ee2332af4/debug-1.txt)

1. ******Debug the code. This code is implementation for binary search for calculating ceil index. The ceil index is the index of the smallest element in the array that is greater than or equal to a given target value.******

```cpp
int ceilIndex(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    int ceil = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else 
            ceil = mid;
            right = mid - 1;
    }

    return ceil;
}
```

[debug-2.txt](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/319783fa-e090-49c1-be60-07eef0f26c58/debug-2.txt)

1. ******Debug the code. This code tries to implement Selection Sort.******

```cpp
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[j];
        arr[j] = temp;
    }
}
```

[debug-3.txt](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/c4defc9a-df44-4164-ae15-1dffb38e097c/debug-3.txt)

1. ******Debug the code. This code tries to implement Bubble Sort.******

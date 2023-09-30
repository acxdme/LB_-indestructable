// Debug Question-2


// debugging -> brackets missing for else condition in  ceilIndex function.
#include <iostream>
using namespace std;


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
        {
            ceil = mid;
            right = mid - 1;
        }
    }

    return ceil;
}

int main() {
    int arr[] = { 1,2,3,5,6,12};
    int n = 6;
    int target = -1;
    int res = ceilIndex(arr, n, target);
    cout << res << endl;

    return 0;
}

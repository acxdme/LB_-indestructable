// Debug 03

// debugging  , indexing issue , j was being used instead of i for index manupulation in selectionSort function.

#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        int j;
        for ( j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }

}

int main()
{
    int arr[] = { 1,12,6,8,3 };
    int n = 5;
    selectionSort(arr, n);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }cout << endl;

    return 0;
}

// tc : O(N log N)
// sc : O(N) , need extra space for left and right arrays

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &v, int start, int mid, int end)
{
    // size of left-subarray
    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    // intialize the left & right arrays
    int *leftArr = new int[leftSize];
    int *rightArr = new int[rightSize];

    // populate the left and right arrays
    for (int i = 0; i < leftSize; i++)
    {
        leftArr[i] = v[start + i];
    }
    for (int i = 0; i < rightSize; i++)
    {
        rightArr[i] = v[mid + 1 + i];
    }

    // merge the left and right arrays
    int i = 0, j = 0, k = start;
    while (i < leftSize && j < rightSize)
    {
        if (leftArr[i] <= rightArr[j])
        {
            v[k++] = leftArr[i++];
        }
        else
        {
            v[k++] = rightArr[j++];
        }
    }

    // leftArray remaining
    while (i < leftSize)
    {
        v[k++] = leftArr[i++];
    }

    // rightArray remaining
    while (j < rightSize)
    {
        v[k++] = rightArr[j++];
    }
}

void mergesort(vector<int> &v, int start, int end)
{
    // base-case
    if (start >= end)
    {
        return;
    }

    // mid-point
    int mid = start + (end - start) / 2;

    // merge-sort on left half
    mergesort(v, start, mid);

    // merge-sort on right half
    mergesort(v, mid + 1, end);

    // merge
    merge(v, start, mid, end);
}

int main()
{

    vector<int> v = {1, 5, 3, 2, 4, 9, 8, 10, 7, 6};
    int size = v.size();

    mergesort(v, 0, size - 1);

    for (int i = 0; i < size; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}

// approach-1 Xor (TC : O(N))

// approach -2 (Binary Search)
// TC (O(log N))

#include <iostream>
#include <vector>

using namespace std;

int findOddElement(vector<int>& arr, int& size) {
    int start = 0;
    int end = size - 1;
    int mid = start + (end - start) / 2;
    int res = -1;
    
    while (start <= end) {
        if (start == end) {
            res = start;
            break;
        }
        if ((mid & 1) == 0) { // even
            if (arr[mid] == arr[mid + 1]) {
                start = mid + 2;
            }
            else {
                end = mid;
            }
        }
        else {
            //odd
            if (arr[mid] == arr[mid - 1]) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        mid = start + (end - start) / 2;
    }

    return res;
}
int main()
{
    vector<int> arr = {13, 1,1,2,2,1,1,2,2,1,1,40,40,13,13 };
    int size = 15;

    int ans = findOddElement(arr, size);
    cout << " the answer is at index " << ans << endl;
    cout << " the answer is " << arr[ans] << endl;

    return -1;
}

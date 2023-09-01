

#include <iostream>

using namespace std;


int searchTarget(int arr[], int& n, int& target) {
	int ans = -1;
	int start = 0;
	int end = n - 1;
	int mid = start + (end - start) / 2;

	while (start <= end) {
		if (target == arr[mid]) {
			ans  = mid;
			break;
		}
		if (target == arr[mid - 1]) {
			ans = mid - 1;
			break;

		}
		if (target == arr[mid + 1]) {
			ans = mid + 1;
			break;

		}
		else if (target > arr[mid]) {
			start = mid + 2;
		}
		else {
			//target < arr[mid]
			end = mid - 2;
		}
		mid = start + (end - start) / 2;
		
	}
	return ans;
}
int main()
{
	int arr[] = { 10, 3, 40, 20, 50, 80, 70 };
	int target = 90;
	int n = 7;
	int result = searchTarget(arr, n, target);

	if (result == -1) {
		cout << "Target not found" << endl;
	}
	else {
		cout << "Target found at index " << result;

	}

	return 0;
}

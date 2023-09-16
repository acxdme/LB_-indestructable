// spoj : https://www.spoj.com/problems/PRATA/

#include <iostream>
#include <algorithm>
using namespace std;

bool checkCondition(int arr[], int n, int p, int sol) {

	int count = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] > sol) return false;
		int k = 1;
		while (arr[i] * ((k * (k + 1)) / 2) <= sol) {
			count++;
			k++;

			if (count > p) return true;

		}
	}


	return false;
}

int main() {

	int t;
	cin >> t;
	int p;
	cin >> p;
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int start = 0;
	int end = arr[n - 1] * ((p * (p + 1)) / 2);
	int mid = start + (end - start) / 2;
	int ans = -1;

	while (start <= end) {
		if (checkCondition(arr, n, p, mid)) {
			ans = mid;
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}

		mid = start + (end - start) / 2;
	}

	cout << ans << endl;
	return 0;
}

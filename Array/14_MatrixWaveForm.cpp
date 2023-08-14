// Time-complexity : O(N*M)
// Space-complexity : O(1) , just have to traverse and print.

#include <iostream>
using namespace std;


int main()
{
	const int n = 3;
	const int m = 5;
	int matrix[n][m] = { {1,2,3,4,5},{5,10,16,24,18},{8,9,7,4,2} };
	//int matrix[3][5] = { {1,2,3,4,5},{5,10,16,24,18},{8,9,7,4,2} };


	cout << matrix[0][0] << endl;

	int i = 0;
	for (int j = 0; j < m; j++) {
		if ((j & 1) == 0) {
			for (i = 0; i < n; i++) {
				cout << matrix[i][j] << " ";
			}
		}
		else {
			for (i = n-1; i >= 0; i--) {
				cout << matrix[i][j] << " ";
			}
		}
	}
	cout << endl;

	return 0;
}

Supreme-Batch-Debug-Exercise-C++ (Week-6)
NOTE: The code snippet given may be incomplete or have compile time, runtime or logical errors.
How to attempt Debugging Exercise?
Copy the code to your code editor (e.g. VS Code).
Add relevant header files like “#include <iostream>” etc.
Run the code.
You will notice the expected output is not printing at the console.
Apply your smart coder mind to Debug the code.
Warning: Only see the solution after you have tried enough.
Debug the code.
#include <bits/stdc++.h>
using namespace std;

void SieveOfEratosthenes(int n) {
	vector<bool> prime(n,true);
	for (int p = 2; p * p <= n; p++) {
		if (prime[p] == false) {
			for (int i = p * p; i <= n; i += p)
				prime[i] = true;
		}
	}

	for (int p = 2; p <= n; p++)
		if (prime[p])
			cout << p << " ";
}

int main() {
	int n = 50;
	SieveOfEratosthenes(n);
	return 0;
}
​
Debug the code. Why is the code crashing when trying to dereference a pointer?
int main() {
    int* p = NULL;
    *p = 42;
    return 0;
}
​
Debug the code. Why is the code not returning the expected output?
int* foo() {
    int x = 10;
    int* p = &x;
    return p;
}

int main() {
    int* q = foo();
    cout << *q << endl; // Expected output: 10, Actual output: some random value
    return 0;
}
​
Debug the code.
int main() {
    int* p;
    *p = 10;
    return 0;
}
​
Debug the code.
int main(){
    int arr[5] = {1, 2, 3, 4, 5};
    int* ptr = arr;
    cout << "The value of the third element in arr is " << *(ptr + 3) << endl;
    return 0;
}

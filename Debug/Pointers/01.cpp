#include <iostream>
#include<vector>
using namespace std;
void SieveOfEratosthenes(int n)
{
	vector<bool> prime(n, true);
	for (int p = 2; p * p <= n; p++)
	{
		if (prime[p] == true) // if prime is true
		{
			for (int i = p * p; i <= n; i += p)
			{
				prime[i] = false; // mark factors of prime false
			}
		}
	}

	for (int p = 2; p <= n; p++) {
		if (prime[p] == true)
		{
			cout << p << " ";
		}
	}
}
int main()
{
	int n = 50;
	SieveOfEratosthenes(n);
	return 0;
}

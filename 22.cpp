#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main()
{
	long long n, k;
	cin >> n >> k;
	vector<long long> a(n + 1);
	a[1] = 1;
	for (size_t i = 2; i <= k; i++)
	{
		for (size_t j = 1; j < i; j++)
		{
			a[i] += a[j];
		}
	}
	for (size_t i = k + 1; i <= n; i++)
	{
		for (size_t j = i - k; j < i; j++)
		{
			a[i] += a[j];
		}
	}
	cout << a[n];
}
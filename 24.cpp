#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
using namespace std;

int main()
{
	long n, sum = 0;
	cin >> n;
	vector<long> A(n + 4, LONG_MAX), B(n + 4, LONG_MAX), C(n + 4, LONG_MAX), d(n+4);
	for (size_t i = 4; i < n+4; i++)
	{
		cin >> A[i] >> B[i] >> C[i];
	}
	for (size_t i = 4; i < n + 4; i++)
	{
		d[i] = min(min(d[i-2] + B[i-1], d[i-3] + C[i-2]), A[i] + d[i-1]);
	}
	cout << d[n + 3];
}
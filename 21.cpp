#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int main()
{
	long long n, ans = 1;
	cin >> n;
	vector<long long> a(n + 3);
	a[1] = 2;
	a[2] = 4;
	a[3] = 7;
	for (size_t i = 4; i <= n; i++)
	{
		a[i] = a[i - 1] + a[i - 2] + a[i - 3];
	}
	cout << a[n];
}
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	long n, sum = 0;
	cin >> n;
	vector<long> a(n), d(n + 1);
	for (size_t i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	d[0] = 0;
	d[1] = a[1] - a[0];
	d[2] = a[2] - a[1] + d[1];
	for (size_t i = 3; i < n; i++)
	{
		d[i] = min(d[i - 2], d[i - 1]) + a[i] - a[i - 1];
	}
	cout << d[n - 1];
}
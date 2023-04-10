#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>
using namespace std;

long BinSearch(vector<long>& a, long p) {
	long l = 0, r = a.size() - 1, m;
	while (l < r) {
		m = (l + r + 1) / 2;
		if (a[m] <= p) {
			l = m;
		}
		else {
			r = m - 1;
		}
	}
	return l;
}

int main()
{
	long n, k, p;
	cin >> n;
	set<long> m;
	for (size_t i = 0; i < n; i++)
	{
		cin >> p;
		m.insert(p);
	}
	cin >> k;
	vector<long> a(m.begin(), m.end());
	for (size_t i = 0; i < k; i++)
	{
		cin >> p;
		long result = BinSearch(a, p);
		if (a[result] < p) {
			result++;
		} 
		cout << result << endl;
	}
}
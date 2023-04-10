#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

typedef pair<long, long> pr;

long Min(vector<long>& a, long& l, long& r) {
	long m = 1000000000;
	for (size_t i = l; i <= r; i++)
	{
		m = min(a[i], m);
	}
	return max(long(0), m);
}

long Count(vector<long>& a, long& l, long& r, vector<pr>& temp) {
	long min = Min(a, l, r);
	long start = l, end = l;
	bool x = false;
	for (size_t i = l; i <= r; i++)
	{
		a[i] -= min;
	}
	for (size_t i = 0; i <= r; i++)
	{
		if (!x && a[i] != 0) {
			start = i;
			end = i;
			x = true;
		}
		else if (x && a[i] == 0 && start == end) {
			x = false;
		}
		else if (x && a[i] == 0 && start < end) {
			temp.push_back(pr(start, end));
			x = false;
		}
		else if (x && a[i] != 0) {
			end++;
		}
	}
	if (x && start < end) {
		temp.push_back(pr(start, end));
	}
	return min*(r-l);
}

long func(vector<long>& a) {
	long result = 0, diff = 1;
	vector<pr> vec{ pr(0,a.size() - 1) };
	vector<pr> temp;
	while (diff != 0) {
		temp = vector<pr>();
		diff = 0;
		for (size_t i = 0; i < vec.size(); i++)
		{
			diff += Count(a, vec[i].first, vec[i].second, temp);
		}
		result += diff;
		vec = temp;
	}
	return result;
}

int main()
{
	long n;
	cin >> n;
	vector<long> a(n);
	for (size_t i = 0; i < a.size(); i++)
	{
		cin >> a[i];
	}
	cout << func(a);
}



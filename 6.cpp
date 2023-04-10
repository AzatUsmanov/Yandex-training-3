#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <math.h>
using namespace std;

void func(unordered_set<long>& set, vector<pair<long, long>>& a, long x) {
	vector<long> temp;
	for (auto i : set)
	{
		if (a[i].first <= a[x].first && a[x].first <= a[i].second) {
			temp.push_back(i);
		}
		else if (a[i].first <= a[x].second && a[x].second <= a[i].second) {
			temp.push_back(i);
		}
		else if (a[x].first <= a[i].first && a[i].first <= a[x].second) {
			temp.push_back(i);
		}
		else if (a[x].first <= a[i].second && a[i].second <= a[x].second) {
			temp.push_back(i);
		}
	}
	for (size_t i = 0; i < temp.size(); i++)
	{
		set.erase(temp[i]);
	}
	set.insert(x);
}

int main()
{
	long m, n;
	cin >> m >> n;
	vector<pair<long, long>> a(n);
	unordered_set<long> set;
	for (size_t i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	for (size_t i = 0; i < n; i++)
	{
		func(set, a, i);
	}
	cout << set.size();
}
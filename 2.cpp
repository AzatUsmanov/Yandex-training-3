#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <math.h>
using namespace std;

long func(vector<long> a, long k) {
	long j = 0, Max = 0, remainder = 0, t = 0;
	bool x;
	for (size_t i = 0; i < a.size(); i++)
	{
		x = false;
		for (size_t j = t; j < a.size(); j++)
		{
			if (a[j] - a[i] - 1 <= j - i - 1 + k) {
				remainder = j - i + k - (a[j] - a[i]);
				Max = max(Max, a[j] - a[i] + 1 + remainder);
				t = j;
				x = true;
			}
			else if (x) {
				break;
			}
		}
	}
	return Max;
}

int main()
{
	char c;
	long k, i = 0, Max = 0, remainder = 0;
	vector<char> s;
	unordered_map<char, vector<long>> m;
	unordered_map<char, long> map;
	vector<pair<long, char>> vec;
	ifstream fin("input.txt");
	fin >> k;
	while (fin >> c) {
		s.push_back(c);
		m[c].push_back(i++);
		map[c] = m[c].size();
	}
	
	for (auto i : map)
	{
		vec.push_back(pair<long, char>(i.second, i.first));
	}
	sort(vec.begin(), vec.end());
	for (size_t i = 0; i < vec.size(); i++)
	{
		Max = max(Max, func(m[vec[i].second],k));
	}
	Max = min(long(s.size()), Max);
	k = min(long(s.size()), k + 1);
	cout << max(k, Max);
}



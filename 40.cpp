#include <iostream>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

void BFS(vector<vector<int>>& g, vector<int>& s, int x, queue<int>& q) {
	for (size_t i = 0; i < g[x].size(); i++)
	{
		if (s[g[x][i]] == -1) {
			s[g[x][i]] = s[x] + 1;
			q.push(g[x][i]);
		}
	}
}

int main()
{
	int n, m, k, x, A, B;
	cin >> n >> m;
	vector<unordered_set<int>> p(m);
	vector<vector<int>> g(m);
	vector<int> s(m, -1);
	queue<int> q;
	for (size_t i = 0; i < m; i++)
	{
		cin >> k;
		for (size_t j = 0; j < k; j++)
		{
			cin >> x;
			p[i].insert(x);
		}
	}
	cin >> A >> B;
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			if (i != j) {
				for (auto k : p[j]) {
					if (p[i].find(k) != p[i].end()) {
						if (!g[i].size() || *--g[i].end() != j)
						g[i].push_back(j);
					}
				}
			}
		}
	}
	vector<int> end, start;
	for (size_t i = 0; i < m; i++)
	{
		if (p[i].find(A) != p[i].end()) {
			start.push_back(i);
		}
		if (p[i].find(B) != p[i].end()) {
			end.push_back(i);
		}
	}
	int ans = 100000000;
	for (size_t i = 0; i < start.size(); i++)
	{
		s = vector<int> (m,-1);
		q = queue<int>();
		s[start[i]] = 0;
		q.push(start[i]);
		for (int i = 0; i < n*n && !q.empty(); i++)
		{
			BFS(g, s, q.front(), q);
			q.pop();
		}
		for (size_t i = 0; i < end.size(); i++)
		{
			if (s[end[i]] != -1) {
				ans = min(ans, s[end[i]]);
			}
		}
	}
	if (ans < 100000000) {
		cout << ans;
	}
	else {
		cout << -1;
	}
}
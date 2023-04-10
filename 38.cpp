#include <iostream>
#include <fstream>
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

	int n, m, S, T, Q, x, y;
	cin >> n >> m >> S >> T >> Q;
	vector<vector<int>> g(n * m);
	vector<int> s(n * m, -1);
	vector<int> b(Q);
	queue<int> q;
	for (int i = 0; i < Q; i++)
	{
		cin >> x >> y;
		b[i] = (x - 1) * m + y - 1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i + 2 < n && j + 1 < m) {
				g[i * m + j].push_back((i + 2) * m + j + 1);
			}
			if (i + 2 < n && j - 1 >= 0) {
				g[i * m + j].push_back((i + 2) * m + j - 1);
			}
			if (i - 2 >= 0 && j + 1 < m) {
				g[i * m + j].push_back((i - 2) * m + j + 1);
			}
			if (i - 2 >= 0 && j - 1 >= 0) {
				g[i * m + j].push_back((i - 2) * m + j - 1);
			}
			if (i + 1 < n && j + 2 < m) {
				g[i * m + j].push_back((i + 1) * m + j + 2);
			}
			if (i - 1 >= 0 && j + 2 < m) {
				g[i * m + j].push_back((i - 1) * m + j + 2);

			}
			if (i + 1 < n && j - 2 >= 0) {
				g[i * m + j].push_back((i + 1) * m + j - 2);
			}
			if (i - 1 >= 0 && j - 2 >= 0) {
				g[i * m + j].push_back((i - 1) * m + j - 2);
			}
		}
	}
	q.push((S-1)*m + T - 1);
	s[(S - 1) * m + T - 1] = 0;
	for (int i = 0; i < n*m && !q.empty(); i++)
	{
		BFS(g, s, q.front(), q);
		q.pop();
	}
	int sum = 0;
	for (int i = 0; i < b.size() && sum != -1; i++)
	{
		if (s[b[i]] != -1) {
			sum += s[b[i]];
		}
		else {
			sum = -1;
		}
	}
	cout << sum;
}
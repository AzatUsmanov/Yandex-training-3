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
	char c;
	int n, start;
	cin >> n;
	vector<vector<int>> g(n * n * n);
	vector<vector<vector<char>>> a(n, vector<vector<char>>(n, vector<char>(n, '#')));
	vector<int> s(n * n * n, -1);
	queue<int> q;
	vector<int> end;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				cin >> a[i][j][k];
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (a[i][j][k] == 'S') {
					start = n * n * i + n * j + k;
				}
				if (i - 1 >= 0 && a[i - 1][j][k] == '.') {
					g[i * n * n + j * n + k].push_back((i - 1) * n * n + j * n + k);
				}
				if (j - 1 >= 0 && a[i][j - 1][k] == '.') {
					g[i * n * n + j * n + k].push_back(i * n * n + (j - 1) * n + k);
				}
				if (k - 1 >= 0 && a[i][j][k - 1] == '.') {
					g[i * n * n + j * n + k].push_back(i * n * n + j * n + k - 1);
				}
				if (i + 1 < n && a[i + 1][j][k] == '.') {
					g[i * n * n + j * n + k].push_back((i + 1) * n * n + j * n + k);
				}
				if (j + 1 < n && a[i][j + 1][k] == '.') {
					g[i * n * n + j * n + k].push_back(i * n * n + (j + 1) * n + k);
				}
				if (k + 1 < n && a[i][j][k + 1] == '.') {
					g[i * n * n + j * n + k].push_back(i * n * n + j * n + k + 1);
				}
			}
		}
	}
	for (size_t j = 0; j < n; j++)
	{
		for (size_t k = 0; k < n; k++)
		{
			if (a[0][j][k] == '.') {
				end.push_back(j * n + k);
			}
		}
	}
	s[start] = 0;
	q.push(start);
	for (int i = 0; i < n*n*n && !q.empty(); i++)
	{
		BFS(g, s, q.front(), q);
		q.pop();
	}
	int min = 10000000;
	for (size_t i = 0; i < end.size(); i++)
	{
		if (s[end[i]] != -1 && s[end[i]] < min) {
			min = s[end[i]];
		}
	}
	cout << min;
}
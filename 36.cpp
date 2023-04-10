#include <iostream>
#include <queue>
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
	int n, x, start, end;
	cin >> n;
	vector<vector<int>> g(n);
	vector<int> s(n, -1);
	queue<int> q;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			cin >> x;
			if (x) {
				g[i].push_back(j);
			}
		}
	}
	cin >> start >> end;
	q.push(start - 1);
	s[start - 1] = 0;
	for (int i = 0; i < n && !q.empty(); i++)
	{
		BFS(g, s, q.front(), q);
		q.pop();
	}
	cout << s[end - 1];
}
#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

void BFS(vector<vector<int>>& g, vector<int>& s, int x, queue<int>& q, vector<int>& prev) {
	for (size_t i = 0; i < g[x].size(); i++)
	{
		if (s[g[x][i]] == -1) {
			s[g[x][i]] = s[x] + 1;
			prev[g[x][i]] = x;
			q.push(g[x][i]);
		}
	}
}

int main()
{
	//ifstream fin("C:/Users/acer/Desktop/input.txt");
	int n, x, start, end;
	cin >> n;
	vector<vector<int>> g(n);
	vector<int> s(n, -1);
	vector<int> prev(n, -1);
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
		BFS(g, s, q.front(), q, prev);
		q.pop();
	}
	int k = end - 1;
	vector<int> ans;
	while (k != -1 ) {
		ans.push_back(k);
		k = prev[k];
	}
	cout << s[end - 1] << endl;
	if (s[end-1] > 0) {
		for (int i = ans.size() - 1; i >= 0; i--)
		{
			cout << ans[i] + 1 << ' ';
		}
	}
}
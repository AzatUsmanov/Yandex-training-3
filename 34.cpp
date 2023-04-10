#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool DFScycle(vector<vector<int>>& g, vector<int>& color, int x, vector<int>& ans) {
	color[x] = 1;
	bool check = true;
	for (size_t i = 0; i < g[x].size(); i++)
	{
		if (color[g[x][i]] == 1) {
			return false;
		}
		else if (!color[g[x][i]] && !DFScycle(g, color, g[x][i], ans)) {
			check = false;
		}
	}
	color[x] = 2;
	ans.push_back(x);
	return check;
}

int main()
{
	int n, m, x, y;
	cin >> n >> m;
	vector<vector<int>> g(n + 1);
	vector<int> color(n + 1, 0);
	vector<int> ans;
	bool check = true;
	for (size_t i = 0; i < m; i++)
	{
		cin >> x >> y;
		g[x].push_back(y);
	}
	for (size_t i = 1; i <= n && check; i++)
	{
		if (!color[i] && !DFScycle(g, color, i, ans)) {
			check = false;
		}
	}
	if (check) {
		for (int i = ans.size()-1; i >= 0; i--)
		{
			cout << ans[i] << ' ';
		}
	}
	else {
		cout << -1;
	}
}
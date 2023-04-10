#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void DFS(vector<int>& ans, vector<vector<int>>& g, vector<bool>& color, int x) {
	ans.push_back(x);
	color[x] = true;
	for (size_t i = 0; i < g[x].size(); i++)
	{
		if (!color[g[x][i]]) {
			DFS(ans, g, color, g[x][i]);
		}
	}
}

int main()
{
	int n, m, x, y;
	cin >> n >> m;
	vector<vector<int>> g(n + 1);
	vector<bool> color(n + 1, false);
	vector<vector<int>> ans;
	for (size_t i = 0; i < m; i++)
	{
		cin >> x >> y;
		if (x != y) {
			g[y].push_back(x);
		}
		g[x].push_back(y);
	}
	for (size_t i = 1; i <= n; i++)
	{
		vector<int> temp;
		if (!color[i]) {
			DFS(temp, g, color, i);
		}
		if (temp.size() != 0) {
			ans.push_back(temp);
		}
	}
	cout << ans.size() << endl;
	for (size_t i = 0; i < ans.size(); i++)
	{
		cout << ans[i].size() << endl;
		for (size_t j = 0; j < ans[i].size(); j++)
		{
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}
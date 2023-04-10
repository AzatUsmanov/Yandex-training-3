#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool DFS(vector<vector<int>>& g, vector<int>& color, int x) {
	bool check = true;
	for (size_t i = 0; i < g[x].size(); i++)
	{
		if (!color[g[x][i]] && color[x] == 1) {
			color[g[x][i]] = 2;
			if (!DFS(g, color, g[x][i])) {
				check = false;
			}
		} else if (!color[g[x][i]] && color[x] == 2) {
			color[g[x][i]] = 1;
			if (!DFS(g, color, g[x][i])) {
				check = false;
			}
		}
		else if (color[g[x][i]] == color[x]) {
			return false;
		}
	}
	return check;
}

int main()
{
	int n, m, x, y;
	cin >> n >> m;
	vector<vector<int>> g(n + 1);
	vector<int> color(n + 1, 0);
	vector<vector<int>> ans;
	bool check = true;
	for (size_t i = 0; i < m; i++)
	{
		cin >> x >> y;
		if (x != y) {
			g[y].push_back(x);
		}
		g[x].push_back(y);
	}
	for (size_t i = 1; i <= n && check; i++)
	{
		if (!color[i]) {
			color[i] = 1;
			check = DFS(g, color, i);
		}
	}
	if (check) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
}
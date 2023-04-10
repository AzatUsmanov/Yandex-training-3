#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

bool DFScycle(vector<vector<int>>& g, vector<int>& color, int x, int prev, vector<int>& ans , bool& ch, int& first) {
	color[x] = 1;
	bool check = false;
	for (size_t i = 0; i < g[x].size(); i++)
	{
		if (!color[g[x][i]] && DFScycle(g, color, g[x][i], x, ans, ch, first)) {
			if (ch && x != first) {
				ans.push_back(x);
			}
			else if ( x == first) {
				ch = false;
				ans.push_back(x);
			}
			return true;
		}
		else if (color[g[x][i]] == 1 && g[x][i] != prev) {
			ans.push_back(x);
			first = g[x][i];
			return true;
		}
	}
	color[x] = 2;
	return check;
}

int main()
{
	ifstream fin("input.txt");
	int n, m, x, y;
	fin >> n;
	vector<vector<int>> g(n + 1);
	vector<int> color(n + 1, 0);
	vector<int> ans;
	bool check = true;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			fin >> x;
			if (x) {
				g[i].push_back(j);
			}
		}
	}

	bool ch = true;
	int first = -1;
	for (int i = 0; i < n; i++)
	{
		if (g[i].size() > 0  && !color[i] && DFScycle(g, color, i, i, ans, ch, first)) {
			break;
		}
	}
	if (!ans.size()) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] + 1 << " ";;
		}
	}
}
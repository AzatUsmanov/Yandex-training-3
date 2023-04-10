#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n;	
	vector<int> a(n + 1);
	for (size_t i = 1; i < n + 1; i++)
	{
		cin >> a[i];
	}
	cin >> m;
	vector<int> b(m + 1);
	for (size_t i = 1; i < m + 1; i++)
	{
		cin >> b[i];
	}
	vector<vector<int>> d(n + 1, vector<int>(m + 1));
	for (size_t i = 1; i < n + 1; i++)
	{
		for (size_t j = 1; j < m + 1; j++)
		{
			if (a[i] == b[j]) {
				d[i][j] = d[i - 1][j - 1] + 1;
			}
			else {
				d[i][j] = max(d[i][j - 1], d[i - 1][j]);
			}
		}
	}
	pair<int, int> k = { n,m };
	vector<int> ans;
	while (k.first > 0 && k.second > 0) {
		//cout << k.first << ' ' << k.second << endl;
		if (d[k.first][k.second] == d[k.first][k.second - 1]) {
			k = { k.first, k.second - 1 };
		}
		else if (d[k.first][k.second] == d[k.first- 1][k.second]){
			k = { k.first - 1, k.second };
		}
		else {
			ans.push_back(a[k.first]);
			k = { k.first - 1, k.second - 1};
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--)
	{
		cout << ans[i] << " ";
	}
}

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	long n, m;
	cin >> n >> m;
	vector<vector<long>> a(n + 1, vector<long>(m + 1, -1));
	vector<vector<long>> d(n + 1, vector<long>(m + 1, -1));
	vector<vector<pair<long, long>>> prev(n + 1, vector<pair<long, long>>(m + 1));
	for (long i = 1; i < n + 1; i++)
	{
		for (long j = 1; j < m + 1; j++)
		{
			cin >> a[i][j];
		}
	}
	prev[0][1] = { -1,-1 };
	prev[1][0] = { -1,-1 };
	prev[0][0] = { -1,-1 };
	d[0][1] = 0;
	d[1][0] = 0;
	d[0][0] = 0;
	for (long i = 1; i < n + 1; i++)
	{
		for (long j = 1; j < m + 1; j++)
		{
			d[i][j] = max(d[i - 1][j], d[i][j - 1]) + a[i][j];
			if (d[i - 1][j] > d[i][j - 1]) {
				d[i][j] = d[i - 1][j] + a[i][j];
				prev[i][j] = { i - 1,j };
			}
			else {
				d[i][j] = d[i][j - 1] + a[i][j];
				prev[i][j] = { i,j - 1 };
			}
		}
	}
	vector<char> ans;
	pair<long, long> k = { n, m };
	while (k.first != 1 || k.second != 1) {
		if (prev[k.first][k.second].first + 1 == k.first) {
			ans.push_back('D');
		}
		else {
			ans.push_back('R');
		}
		k = prev[k.first][k.second];
	}

	cout << d[n][m] << endl;
	for (long i = ans.size()-1; i >=0; i--)
	{
		cout << ans[i] << " ";
	}
}
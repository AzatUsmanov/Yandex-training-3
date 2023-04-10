#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n + 1, vector<int>(m + 1));
	vector<vector<int>> d(n + 1, vector<int>(m + 1, 1000000000));
	for (size_t i = 1; i < n + 1; i++)
	{
		for (size_t j = 1; j < m + 1; j++)
		{
			cin >> a[i][j];
		}
	}
	d[0][0] = 0;
	d[0][1] = 0;
	d[1][0] = 0;
	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < m + 1; j++)
		{
			d[i][j] = min(d[i - 1][j], d[i][j-1]) + a[i][j];
		}
	}
	cout << d[n][m];
}
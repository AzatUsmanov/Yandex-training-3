#include <iostream>
#include <vector>
using namespace std;

int main()
{
	long n, m;
	cin >> n >> m;
	vector<vector<long>> d(n, vector<long>(m));
	d[0][0] = 1;
	for (long i = 0; i < n; i++)
	{
		for (long j = 0; j < m; j++)
		{
			if (i - 2 >= 0 && j - 1 >= 0) {
				d[i][j] += d[i - 2][j - 1];
			}
			if (i - 1 >= 0 && j - 2 >= 0) {
				d[i][j] += d[i - 1][j - 2];
			}
		}
	}
	cout << d[n - 1][m - 1] << endl;
}
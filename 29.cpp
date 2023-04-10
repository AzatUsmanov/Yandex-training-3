#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	int ind = 2 * n - 1, k1 = 0;
	vector <vector <int>> dp(n, vector<int>(2 * n, 100000000));
	vector <int> a(n);
	vector<int> ans;
	if (n == 0) {
		cout << "0" << endl;
		cout << 0 << " " << 0;
		return 0;
	}
	for (size_t i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (a[0] <= 100) {
		dp[0][0] = a[0];
	}
	else {
		dp[0][1] = a[0];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 2 * n; ++j) {
			if (a[i] > 100) {
				if (j > 0) {
					dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + a[i]);
				}
				if (j < 2 * n - 1) {
					dp[i][j] = min(dp[i][j], dp[i - 1][j + 1]);
				}
			}
			else {
				if (j < 2 * n - 1) {
					dp[i][j] = min(dp[i][j], dp[i - 1][j + 1]);
				}
				dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i]);
			}
		}
	}
	for (int i = 2 * n - 1; i >= 0; i--) {
		if (dp[n - 1][i] < dp[n - 1][ind]) {
			ind = i;
		}
	}
	cout << dp[n - 1][ind] << endl;
	k1 = ind;
	for (int i = n - 1; i > 0; i--) {
		if (a[i] > 100) {
			if (ind > 0 && dp[i][ind] == dp[i - 1][ind - 1] + a[i]) {
				ind--;
			}
			else {
				ans.push_back(i + 1);
				ind++;
			}
		}
		else if (ind + 1 < n && dp[i][ind] == dp[i - 1][ind + 1]) {
			ans.push_back(i + 1);
			ind++;
		}
	}
	cout << k1 << " " << ans.size() << endl;
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << endl;
	}
}

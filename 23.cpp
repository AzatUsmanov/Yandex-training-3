#include <iostream>
#include <vector>
using namespace std;

int Min(int i, int j, vector<int>& a) {
	if (a[i] < a[j]) {
		return i;
	}
	else if (a[j] < a[i]) {
		return j;
	}
	else if (i > j) {
		return i;
	}
	else return j;
}

int Min(int i, int j, int k, vector<int>& a) {
	return Min(Min(i, j, a), Min(j, k, a), a);
}

int main()
{
	int n;
	cin >> n;
	vector<int> a(n + 1), prev(n + 1);
	a[1] = 0;
	prev[1] = -1;
	for (size_t i = 2; i <= n; i++)
	{
		if (i % 2 == 0 && i % 3 == 0) {
			prev[i] = Min(i / 2, i / 3, i - 1, a);
			a[i] = a[prev[i]] + 1;
		}
		else if (i % 3 == 0) {
			prev[i] = Min(i / 3, i - 1, a);
			a[i] = a[prev[i]] + 1;
		}
		else if (i % 2 == 0) {
			prev[i] = Min(i / 2, i - 1, a);
			a[i] = a[prev[i]] + 1;
		}
		else {
			a[i] = a[i - 1] + 1;
			prev[i] = i - 1;
		}
	}
	vector<int> ans;
	int k = n;
	while (prev[k] != -1) {
		ans.push_back(prev[k]);
		k = prev[k];
	}
	cout << ans.size() << endl;
	for (int i = ans.size() - 1; i >= 0; i--)
	{
		cout << ans[i] << ' ';
	}
	cout << n;
}
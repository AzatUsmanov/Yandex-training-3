#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <math.h>
using namespace std;

typedef long long ll;

ll Sum(vector<ll>& sum, ll l, ll r) {
	return sum[r] - sum[l];
}

ll func(vector<ll>& sum, ll x1, ll y1, ll x2, ll y2, ll n, ll m) {
	ll s = 0;
	for (ll i = x1; i <= x2; i++)
	{
		s += Sum(sum, y1 - 1 + (i - 1) * m, y2 + (i - 1) * m);
	}
	return s;
}

int main()
{
	ll m, n, k, x1, y1, x2, y2;
	cin >> n >> m >> k;
	vector<ll> a(n*m), sum(n*m + 1);
	for (size_t i = 0; i < n*m; i++)
	{
		cin >> a[i];
	}
	for (size_t i = 1; i < sum.size(); i++)
	{
		sum[i] = sum[i - 1] + a[i - 1];
	}
	for (ll i = 0; i < k; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		cout << func(sum, x1, y1, x2, y2, n, m) << endl;
	}
}
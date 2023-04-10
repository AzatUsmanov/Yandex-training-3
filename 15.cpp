#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	int c, n;
	bool x = true;
	cin >> n;
	vector<int> ans(n);
	stack<pair<int,int>> stack;
	for (size_t i = 0; i < n; i++){
		cin >> c;
		while (!stack.empty() && stack.top().first > c) {
			ans[stack.top().second] = i;
			stack.pop();
		}
		stack.push(pair<int, int>(c, i));
	}
	while (!stack.empty()) {
		ans[stack.top().second] = -1;
		stack.pop();
	}
	for (size_t i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
}
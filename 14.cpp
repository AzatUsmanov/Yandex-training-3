#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

int main()
{
	int c, n;
	bool x = true;
	stack<int> sec, tup;
	sec.push(0);
	cin >> n;
	for (size_t i = 0; i < n; i++){
		cin >> c;
		while (!tup.empty() &&sec.top() + 1 == tup.top()) {
			sec.push(tup.top());
			tup.pop();
		}
		if (sec.top() + 1 == c) {
			sec.push(c);
		}
		else {
			tup.push(c);
		}
	}
	while (!tup.empty() && x) {
		if (tup.top() == sec.top() + 1) {
			sec.push(tup.top());
			tup.pop();
		}
		else x = false;
	}
	if (x) {
		cout << "YES";
	}
	else cout << "NO";
}

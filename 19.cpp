#include <iostream>
#include <set>
using namespace std;

int main()
{
	int x, num, n;
	multiset<int> set;
	cin >> n;
	for (size_t i = 0; i < n; i++) {
		cin >> x;
		if (x) {
			cout << *--set.end() << endl;
			set.erase(--set.end());
		}
		else {
			cin >> num;
			set.insert(num);
		}
	}
}
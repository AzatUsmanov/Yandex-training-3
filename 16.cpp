#include <iostream>
#include <queue>
using namespace std;

int main()
{
	string s;
	int x;
	queue<int> queue, clear;
	while (cin >> s) {
		if (s == "push") {
			cin >> x;
			queue.push(x);
			cout << "ok" << endl;
		}
		else if (s == "pop") {
			if (queue.empty()) {
				cout << "error" << endl;
			}
			else {
				cout << queue.front() << endl;
				queue.pop();
			}
		}
		else if (s == "front") {
			if (queue.empty()) {
				cout << "error" << endl;
			}
			else {
				cout << queue.front() << endl;
			}
		}
		else if (s == "size") {
			cout << queue.size() << endl;
		}
		else if (s == "clear") {
			queue = clear;
			cout << "ok" << endl;
		}
		else if (s == "exit") {
			cout << "bye" << endl;
			return 0;
		}
	}
}
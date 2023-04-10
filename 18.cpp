#include <iostream>
#include <deque>
using namespace std;

int main()
{
	string s;
	int x;
	deque<int> deque;
	while (cin >> s) {
		if (s == "push_front") {
			cin >> x;
			deque.push_front(x);
			cout << "ok" << endl;
		}
		else if (s == "push_back") {
			cin >> x;
			deque.push_back(x);
			cout << "ok" << endl;
		}
		else if (s == "pop_front") {
			if (deque.empty()) {
				cout << "error" << endl;
			}
			else {
				cout << deque.front() << endl;
				deque.pop_front();
			}
		}
		else if (s == "pop_back") {
			if (deque.empty()) {
				cout << "error" << endl;
			}
			else {
				cout << deque.back() << endl;
				deque.pop_back();
			}
		}
		else if (s == "front") {
			if (deque.empty()) {
				cout << "error" << endl;
			}
			else {
				cout << deque.front() << endl;
			}
		}
		else if (s == "back") {
			if (deque.empty()) {
				cout << "error" << endl;
			}
			else {
				cout << deque.back() << endl;
			}
		}
		else if (s == "size") {
			cout << deque.size() << endl;
		}
		else if (s == "clear") {
			deque.clear();
			cout << "ok" << endl;
		}
		else if (s == "exit") {
			cout << "bye" << endl;
			return 0;
		}
	}
}
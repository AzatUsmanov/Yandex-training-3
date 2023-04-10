#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

int main()
{
	ifstream fin("input.txt");
	string s;
	int x;
	stack<int> stack, clear;
	while (fin >> s) {
		if (s == "push") {
			fin >> x;
			stack.push(x);
			cout << "ok" << endl;
		}
		else if (s == "pop") {
			if (stack.empty()) {
				cout << "error" << endl;
			}
			else {
				cout << stack.top() << endl;
				stack.pop();
			}
		}
		else if (s == "back") {
			if (stack.empty()) {
				cout << "error" << endl;
			}
			else {
				cout << stack.top() << endl;
			}
		}
		else if (s == "size") {
			cout << stack.size() << endl;
		}
		else if (s == "clear") {
			stack = clear;
			cout << "ok" << endl;
		}
		else if (s == "exit") {
			cout << "bye" << endl;
			return 0;
		}
	}
}

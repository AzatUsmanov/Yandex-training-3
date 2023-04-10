#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

int main()
{
	ifstream fin("input.txt");
	char c;
	bool x = true;
	stack<char> stack, clear;
	while (fin >> c) {
		switch (c) {
		case '(': {
			stack.push('(');
		} break;
		case '{': {
			stack.push('{');
		} break;
		case '[': {
			stack.push('[');
		} break;
		case ')': {
			if (stack.empty() || stack.top() != '(') {
				x = false;
				break;
			}
			else {
				stack.pop();
			}
		} break;
		case '}': {
			if (stack.empty() || stack.top() != '{') {
				x = false;
				break;
			}
			else {
				stack.pop();
			}
		} break;
		case ']': {
			if (stack.empty() || stack.top() != '[') {
				x = false;
				break;
			}
			else {
				stack.pop();
			}
		} break;
		}
	}
	if (x && stack.empty()) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}
}
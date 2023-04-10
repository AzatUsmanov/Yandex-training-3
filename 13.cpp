#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

int main()
{
	ifstream fin("input.txt");
	char c;
	int a, b;
	bool x = true;
	stack<int> stack;
	while (fin >> c) {
		if ('0' <= c && c <= '9') {
			stack.push(int(c - int('0')));
		}
		else if (c == '+') {
			a = stack.top();
			stack.pop();
			b = stack.top();
			stack.pop();
			stack.push(a + b);
		}
		else if (c == '-') {
			a = stack.top();
			stack.pop();
			b = stack.top();
			stack.pop();
			stack.push(b - a);
		}
		else if (c == '*') {
			a = stack.top();
			stack.pop();
			b = stack.top();
			stack.pop();
			stack.push(a * b);
		}
	}
	cout << stack.top();
}
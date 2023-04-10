#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int x, count = 0;
	queue<int> first, second;
	for (size_t i = 0; i < 5; i++){
		cin >> x;
		first.push(x);
	}
	for (size_t i = 0; i < 5; i++){
		cin >> x;
		second.push(x);
	}
	while (!first.empty() && !second.empty() && count != 1000000) {
		if (first.front() - second.front() != 9 && (first.front() > second.front() || (second.front() == 9 && first.front() == 0))) {
			first.push(first.front());
			first.push(second.front());
		}
		else if (second.front() - first.front() != 9 && (first.front() < second.front() || (second.front() == 0 && first.front() == 9))) {
			second.push(first.front());
			second.push(second.front());
		}
		first.pop();
		second.pop();
		count++;
	}
	if (first.empty()) {
		cout << "second " << count;
	}
	else if (second.empty()) {
		cout << "first " << count;
	}
	else {
		cout << "botva";
	}
}
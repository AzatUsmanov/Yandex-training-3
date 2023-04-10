#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>
using namespace std;

int main()
{
	long n, a, b;
	set<long> x, y;
	cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		cin >> a >> b;
		x.insert(a);
		y.insert(b);
	}
	cout << *(x.begin()) << " " << *(y.begin()) << " " << *(--x.end()) << " " << *(--y.end());
}	

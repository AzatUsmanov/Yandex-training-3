#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <math.h>
using namespace std;

int main()
{
	char c;
	long Max = 0;
	unordered_map<char, long> m;
	ifstream fin("input.txt");
	ofstream out("output.txt");
	while (fin >> c) {
		m[c]++;
		Max = max(m[c], Max);
	}
	map<char, long> sortedMap(m.begin(), m.end());
	for (size_t i = Max; i > 0; i--)
	{
		for (auto x : sortedMap) {
			if (x.second >= i) {
				out << '#';
			}
			else {
				out << ' ';
			}
		}
		out << endl;
	}
	for (auto x : sortedMap) {
		out << x.first;
	}
}
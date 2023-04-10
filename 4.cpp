#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	long n, k, row, seat, vrow1, vrow2, vseat1, vseat2;
	cin >> n >> k >> row >> seat;
	long NP = (row - 1) * 2 + seat;
	if (NP + k > n && NP - k <= 0) cout << -1;
	else {
		vrow1 = long(ceil(double(NP + k) / double(2)));
		vseat1 = (NP + k) % 2;
		if (vseat1 == 0) vseat1 = 2;
		vrow2 = long(ceil(double(NP - k) / double(2)));
		vseat2 = (NP - k) % 2;
		if (vseat2 == 0) vseat2 = 2;

		if (NP + k > n) {
			cout << vrow2 << " " << vseat2;
		}
		else if (NP - k <= 0) {
			cout << vrow1 << " " << vseat1;
		}
		else {
			if (abs(vrow2 - row) < abs(vrow1 - row)) {
				cout << vrow2 << " " << vseat2;
			}
			else {
				cout << vrow1 << " " << vseat1;
			}
		}
	}
}
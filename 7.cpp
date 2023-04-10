#include <iostream>
#include <math.h>
using namespace std;

void func(int& hh, int& mm, int& ss) {
	char a, b, c;
	cin >> a >> b >> c;
	hh = (int(a) - 48) * 10 + (int(b) - 48);
	cin >> a >> b >> c;
	mm = (int(a) - 48) * 10 + (int(b) - 48);
	cin >> a >> b;
	ss = (int(a) - 48) * 10 + (int(b) - 48);
}

int main()
{
	int hh1, mm1, ss1, hh2, mm2, ss2, hh3, mm3, ss3;
	func(hh1, mm1, ss1);
	func(hh2, mm2, ss2);
	func(hh3, mm3, ss3);
	if (ss1 > ss3) {
		ss3 += 60;
		mm3--;
	}
	if (mm1 > mm3) {
		mm3 += 60;
		hh3--;
	}
	if (hh1 > hh3) {
		hh3 += 24;
	}
	int a = (hh3 - hh1) / 2;
	mm3 += ((hh3 - hh1) % 2) * 60;
	int b = (mm3 - mm1) / 2;
	ss3 += ((mm3 - mm1) % 2) * 60;
	int c = int(round((float(ss3) - float(ss1)) / float(2)));
	hh2 += a;
	mm2 += b;
	ss2 += c;
	mm2 += ss2 / 60;
	ss2 = ss2 % 60;
	hh2 += mm2 / 60;
	mm2 = mm2 % 60;
	hh2 = hh2 % 24;
	cout << hh2 / 10 << hh2 % 10 << ":";
	cout << mm2 / 10 << mm2 % 10 << ":";
	cout << ss2 / 10 << ss2 % 10;
}
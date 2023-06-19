#include <iostream>
#include <iomanip>
using namespace std;

class TIME {
	public:
		int h, m, s;
		TIME(int _h = 0, int _m = 0, int _s = 0) {
			h = _h;
			m = _m;
			s = _s;
			m = (s / 60) + m;
			s = s % 60;
			h = (m / 60) + h;
			m = m % 60;
		}
		friend ostream &operator<<(ostream &out, const TIME &t);
		friend istream &operator>>(istream &in, TIME &t);
		friend bool operator>(TIME &a, TIME &b);
		friend bool operator>(TIME &a, int &b);
		friend bool operator>(int &b, TIME &a);
};

bool operator>(TIME &a, TIME &b) {
	if (a.h > b.h) {
		return 1;
	} else if (a.h < b.h) {
		return 0;
	} else {
		if (a.m > b.m) {
			return 1;
		} else if (a.h < b.h) {
			return 0;
		} else {
			if (a.s > b.s) {
				return 1;
			} else {
				return 0;
			}
		}
	}
}

bool operator>(TIME &a, int &b) {
	if (a.h > b) {
		return 1;
	} else
		return 0;
}

bool operator>(int &b, TIME &a) {
	if (b > a.h) {
		return 1;
	} else
		return 0;
}

ostream &operator<<(ostream &out, const TIME &t) {
	out << setw(2) << setfill('0') << t.h << ":" << setw(2) << t.m << ":" << setw(2) << t.s;
	return out;
}

istream &operator>>(istream &in, TIME &t) {
	char c;
	in >> t.h >> c >> t.m >> c >> t.s;
	return in;
}


int main() {
	TIME a, b;
	cin >> a >> b;
	if (a > b) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
	cout << a << b;
	return 0;
}
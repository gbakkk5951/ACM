using namespace std;
int main() {}
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include <cmath>
#include <complex>
#include <cassert>
namespace OI {
struct LS {
	int inline operator [] (int a) {
		return a << 1;
	}
}ls;
struct RS {
	int inline operator [] (int a) {
		return a << 1 | 1;
	}
}rs;
typedef long long lld;
typedef double lf;
typedef unsigned u;
typedef unsigned char uc;
typedef unsigned long long llu;
typedef long double Lf;
typedef complex<lf> com;
const lf PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const lld LINF = (lld)INF << 32 | INF;
const int DST = 0, NXT = 1, VAL = 2, FLOW = 2, CST = 3;

char s[1027][1027];
struct _Main {
	void copy(int size, int x, int y) {
		x = x * size;
		y = y * size + 1;
		for (int i = 1; i <= size; i++) {
			memmove(s[x + i] + y, s[i] + 1, size * sizeof(char));
		}
	}
	void rev(int size, int x, int y) {
		x = x * size;
		y = y * size;
		for (int i = x + 1; i <= x + size; i++) {
			for (int j = y + 1; j <= y + size; j++) {
				s[i][j] = s[i][j] == 'C' ? 'P' : 'C';
			}
		}
	}
	void print(int size) {
		for (int i = 1; i <= size; i++) {
			for (int j = 1; j <= size; j++) {
				putchar(s[i][j]);
			}
			putchar('\n');
		}
	}
	_Main() {
		s[1][1] = s[1][2] = s[2][2] = 'C';
		s[2][1] = 'P';
		for (int i = 2; i <= 10; i++) {
			copy(1 << i - 1, 0, 1);
			copy(1 << i - 1, 1, 0);
			copy(1 << i - 1, 1, 1);
			rev(1 << i - 1, 1, 0);
		}
		int Qn;
		read(Qn);
		for (int Q = 1, k; Q <= Qn; Q++) {
			read(k);
			print(1 << k);
		}
	}
template <typename Type>
	void read(Type &a) {
		char t, f = 1;
		while (!isdigit(t = getchar())) {
			f = t == '-' ? -1 : f;
		}
		a = t - '0';
		while ( isdigit(t = getchar())) {
			a *= 10; a += t - '0';
		}
		a *= f;
	}
}std;
}

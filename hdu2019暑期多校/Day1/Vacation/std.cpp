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
const int MXN = 1e5 + 10;
struct Car {
	lf s, l, v;
}car[MXN];
struct _Main {
	int n;
	lf s[MXN], t[MXN], v[MXN];
	lf runans() {
		lf minv = 1e9;
		for (int i = 0; i <= n; i++) {
			minv = min(minv, car[i].v);
		}
		lf sa = 0;
		s[0] = car[0].s;
		t[0] = car[0].s / car[0].v;
		int top = 0, beg = 0;
		while (beg < n && !(car[beg].v < car[n].v)) {
			beg++;
		}
		if (beg == n) return car[n].s / car[n].v;
		t[1] = 1e9 / minv;
		s[1] = t[1] * car[beg].v;
		v[1] = car[beg].v;
		t[0] = 2e9;
		s[0] = s[1];
		v[0] = 0;
		top = 1;
		for (int i = beg + 1; i <= n; i++) {
			while (t[top] * car[i].v - (s[top] + sa) < car[i].s - (car[i - 1].s + car[i - 1].l)) {
				top--;
			}
			++top;
			v[top] = car[i].v;
			t[top] = (s[top - 1] + sa - v[top - 1] * t[top - 1] + v[top - 1] * t[top] + (car[i].s - (car[i - 1].s + car[i - 1].l))) / (v[top] - v[top - 1]);
			s[top] = t[top] * v[top];
			sa += car[i].s - (car[i - 1].s + car[i - 1].l);
			s[top] -= sa;
			printf("[top] v = %lf, t = %lf, s = %lf\n", v[top], t[top], s[top]);
		}
		while (s[top] < car[n].s) {
			--top;
		} 
		return t[top] - (s[top] - car[n].s) / v[top];
	}
	_Main() {
		while (~scanf("%d", &n)) {
			for (int i = n; i >= 0; i--) {
				read(car[i].l);
			}
			for (int i = n; i >= 0; i--) {
				read(car[i].s);
			}
			for (int i = n; i >= 0; i--) {
				read(car[i].v);
			}
			printf("%lf\n", runans());
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

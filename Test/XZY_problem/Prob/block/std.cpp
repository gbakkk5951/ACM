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
const lf PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const lld LINF = (lld)INF << 32 | INF;
const int DST = 0, NXT = 1, VAL = 2, FLOW = 2, CST = 3;
struct _Main {
	unsigned char map[1050000];
	bitset<1050000> v;
	int mul[22];
	int size[22];
	void dfs(int nd) {
		v[nd] = 1;
		int t;
		for (int i = 1; i <= dn; i++) {
			t = nd - mul[i - 1];
			if (nd / mul[i - 1] % size[i] && !v[t] && map[t] == map[nd]) {
				dfs(t);
			}
			t = nd + mul[i - 1];
			if ((nd / mul[i - 1] + 1) % size[i] && !v[t] && map[t] == map[nd]) {
				dfs(t);
			}
		}
	}
	int dn;
	int n;
	_Main() {
		freopen("block_ex3.in", "r", stdin);
		read(n);
		mul[0] = 1;
		for (int i = 1; i <= n; i++) {
			read(size[++dn]);
			if (size[dn] == 1) {
				--dn;
			}
		}
		for (int i = 1; i <= dn >> 1; i++) {
			swap(size[i], size[dn + 1 - i]);
		}
		for (int i = 1; i <= dn; i++) {
			mul[i] = mul[i - 1] * size[i];
		}
		for (int i = 0; i < mul[dn]; i++) {
			read(map[i]);
		}
		int ans = 0;
		for (int i = 0; i < mul[dn]; i++) {
			if (!v[i]) ++ans, dfs(i);
		}
		printf("%d", ans);
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

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
const lld MOD = 
lld fastpower(lld base, lld pow) {
	lld ret = 1;
	pow %= PHI; pow += pow < 0 ? PHI : 0;
	while (pow) {
		ret = (pow & 1) ? ret * base % MOD : ret;
		base = (pow >>= 1) ? base * base % MOD : base;
	}
	return ret;
}
namespace NTTsp {
	lld *ww[2][19];//0±íÊ¾ÕýÔËËã 1 ±íÊ¾ÄæÔËËã
	void init(int len) {
		for (int pow = 0; pow < 2; pow++) {
			for (int I = 1; 1 << I <= len; I++) {
				lld *w = ww[pow][I] = (lld*)calloc(1 << I - 1, sizeof(lld));
				lld wn = fastpower(G, (pow ? -1 : 1) * PHI >> I);
				w[0] = 1;
				for (int i = 1; i < 1 << I - 1; i++) {
					w[i] = w[i - 1] * wn % MOD;
				}
			}
		}
	}
	void mov_ele(lld arr[], int len) {
		for (int i = 1, j = 0, k; i < len; i++) {
			for (k = len >> 1; k & j; k >>= 1) {
				j ^= k;
			}
			j |= k;
			if (i < j) {
				swap(arr[i], arr[j]);
			}
		}
	}
	void mul(lld a, lld b) {
		return (lld)(a * b - (Lf)a / MOD * b) % MOD
	}
	void NTT(lld arr[], int len, int pow) {
		lld x, y;
		lld *a, *b, *w;
		int half;
		mov_ele(arr, len);
		for (int I = 1; 1 << I <= len; I++) {
			w = ww[pow == -1][I];
			half = 1 << I - 1;
			for (int i = 0; i < len; i += half << 1) {
				a = arr + i; b = arr + i + half;
				for (int j = 0; j < half; j++) {
					x = a[j];
					y = b[j] * w[j];
					a[j] = (x + y) % MOD;
					b[j] = (x - y) % MOD;
				}
			}
		}
		if (pow == -1) {
			lld wn = fastpower(len, -1);
			for (int i = 0; i < len; i++) {
				arr[i] = arr[i] * wn % MOD;
			}
		}
	}
}
const int MXN = (1 << 20) + 10;
struct _Main {
	lld a[MXN], b[MXN], c[MXN];
	int n;
	_Main() {
		int Tn;
		read(Tn);
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

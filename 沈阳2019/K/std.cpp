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
const lld MOD = 1e9 + 7, PHI = 1e9 + 6;
const int MXN = 72;
int n;
struct Matrix {
	lld arr[MXN][MXN];
	lld * operator [] (int x) {
		return arr[x];
	}
	void clear() {
		memset(this, 0, sizeof(Matrix));
	}
	Matrix operator * (Matrix &b) {
		Matrix ret;
		ret.clear();
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				lld mul = arr[i][j];
				for (int k = 0; k <= n; k++) {
					(ret[i][k] += mul * b[j][k]) %= MOD;
				}
			}
		}
		return ret;
	}
};
struct _Main {
	int a[MXN << 1];
	
	lld data[MXN][MXN], *ma[MXN];
	lld getrev(lld base) {
		lld ret = 1;
		for (lld pow = PHI - 1; pow; pow >>= 1) {
			if (pow & 1) ret = ret * base % MOD;
			base = base * base % MOD;
		}
		return ret;	
	}
	void gause() { 
		for (int i = 0; i < n - 1; i++) {
			for (int j = i; j < n; j++) {
				if (ma[j][i]) {
					swap(ma[j], ma[i]);
					break;
				}
			}
			for (int j = i + 1; j < n; j++) {
				if (ma[j][i]) {
					lld mul = ma[j][i] * getrev(ma[i][i]) % MOD;
					for (int k = i; k <= n; k++) {
						(ma[j][k] -= mul * ma[i][k]) %= MOD;
					}
				}
			}
		}
		
		for (int i = n - 1; i >= 0; i--) {
			ma[i][n] = (ma[i][n] * getrev(ma[i][i])) % MOD; 
			ma[i][i] = 1;
			lld mul = ma[i][n];
			for (int j = i - 1; j >= 0; j--) {
				if (ma[j][i]) {
					(ma[j][n] -= ma[j][i] * mul) %= MOD;
				}
			}
		}
		/*
		printf("--\n");
		for (int i = 0; i < n; i++) {
			for (int j = 0 ; j <= n; j++) {
				printf("%lld ", ma[i][j]);
			}
			printf("\n");
		}
		printf("--\n");
		*/
	}
	Matrix one, base, ans;
	_Main() {
		int Tn;
		read(Tn);
		lld dst;//fuck
		for (int i = 0; i <= 70; i++) {
			one[i][i] = 1;
		}
		for (int T = 1; T <= Tn; T++) {
			lld sum = 0;
			read(n); read(dst);
			for (int i = 1; i <= n * 2; i++) {
				read(a[i]);
			}
			if (dst <= 2 * n) {
				for (int i = 1; i <= dst; i++) {
					(sum += a[i]) %= MOD;
				}
				printf("%lld\n", sum);
				continue;
			}
			for (int i = 0; i < n; i++) {
				ma[i] = data[i];
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j <= n; j++) {
					ma[i][j] = a[1 + i + j];	
				}
			}
			gause();
			/*
			for (int i = 0; i < n; i++) {
				printf("R%d = %lld\n", i, ma[i][n]);
			}
			*/
			base.clear();
			for (int i = 0; i < n - 1; i++) {
				base[i][i + 1] = 1;
			}
			for (int i = 0; i < n; i++) {
				base[n - 1][i] = ma[i][n];
			}
			base[n][0] = base[n][n] = 1;
			dst -= n;
		//	dst %= PHI;
			ans = one;
			while (dst) {
				if (dst & 1) ans = ans * base;
				if (dst >>= 1) base = base * base;
			}
			for (int i = 0; i <= n; i++) {
				for (int j = 0; j < n; j++) {
					sum = (sum + ans[i][j] * a[j + 1]) % MOD;
				}
			}
			if (sum < 0) sum += MOD;
			printf("%lld\n", sum);
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


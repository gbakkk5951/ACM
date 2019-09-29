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
struct _Main {
	int a[2][2][2];
	char equal(int a[], int b[]) {
		return a[0] == b[0] && a[1] == b[1];
	}
	_Main() {
		int Qn;
		read(Qn);
		int (*x[2])[2];
		for (int Q = 1; Q <= Qn; Q++) {
			x[0] = a[0];
			x[1] = a[1];
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 2; k++) {
					for (int l = 0; l < 2; l++) {
						read(x[j][k][l]);
					}
				}
			}
			if (x[0][0][1] > x[1][0][1] || x[0][0][1] == x[1][0][1] && x[0][0][0] > x[1][0][0]) {
				swap(x[0], x[1]);
			}
			/*
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					for (int k = 0; k < 2; k++) {
						printf("%d ", x[i][j][k]);
					}
				}
				printf("\n");
			}
			*/
			int ans;
			//左上重合 
			if (equal(x[0][0], x[1][0])) {
				//排右下角
				if (x[0][1][1] > x[1][1][1] || x[0][1][1] == x[1][1][1] && x[0][1][0] > x[1][1][0]) {
					swap(x[0], x[1]);
				}
				//右下重合
				if (equal(x[0][1], x[1][1])) {
					ans = 2;
				} else
				//正下边多
				if (x[1][1][0] < x[0][1][0]) {
					ans = 4;
				} else
				//右边及右下多
				{
					ans = 3;
				}
			} else
			//无交
			if (x[1][0][0] >= x[0][1][0] || x[1][0][1] >= x[0][1][1] || x[1][1][0] <= x[0][0][0]) {
				ans = 3;
			} else
			//内交
			if (x[1][0][1] > x[0][0][1] && x[1][0][0] > x[0][0][0]) {
				if (x[1][1][0] <= x[0][1][0] && x[1][1][1] <= x[0][1][1]) {
					ans = 3;
				} else 
				{
					ans = 4;
				}
			} else
			//上棱交
			if (x[1][0][1] == x[0][0][1]) {
				if (x[1][1][1] > x[0][1][1] && x[1][1][0] < x[0][1][0]) {
					ans = 5;
				} else
				if (equal(x[1][1], x[0][1]) || x[1][1][0] <= x[0][1][0] && x[1][1][1] < x[0][1][1]) {
					ans = 3;
				} else {
					ans = 4;
				}
			} else
			//左棱交 || 左交
			{
	//			printf("HEEE");
				if (x[1][1][1] <= x[0][1][1] && x[1][1][0] < x[0][1][0] || equal(x[0][1], x[1][1])) {
					ans = 3;
				} else
				if (x[1][1][1] < x[0][1][1] && x[1][1][0] > x[0][1][0]) {
					ans = 5;
				} else {
					ans = 4;
				}
				//左交且左边多一块
				if (x[1][0][0] < x[0][0][0] && x[1][1][1] <= x[0][1][1]){
					++ans;
				}
			}
			
			
			
			printf("%d\n", ans);
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

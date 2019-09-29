#pragma GCC optimize(2)
#include <cstdio>
#include <cstring>
#include <algorithm>
#define P 998244353
#define N 1000002
const int mxn = 300005;
using namespace std;
void read(int& x) {
    int f = 1; x = 0;
    char ch = getchar();

    while (ch < '0' || ch > '9')   {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    x *= f;
}
struct Info {
	int head, dfn, low;
}info[mxn];
const int NXT = 0, DST = 1;
int T,n,m,st[mxn],top,rt,ans;

int edge[N][2], tot,num,cnt,bn[mxn];
void add(int a,int b) {
		edge[++tot][NXT]=info[a].head;info[a].head=tot;edge[tot][DST]=b;}
void Tarjan(int u) {
    info[u].dfn = info[u].low = ++num;
    if (rt==u && !info[u].head) return;
    st[u] = ++top;
    for (int i=info[u].head;i;i=edge[i][NXT]) {
        int v=edge[i][DST];
        if (!info[v].dfn) {
            Tarjan(v);
            info[u].low = min(info[u].low, info[v].low);
            if (info[v].low >= info[u].dfn) {
                ans=1LL*ans*(bn[2 + top - st[v]]-1)%P;
				top = st[v] - 1;
            }
        }
        else {
            info[u].low = min(info[u].low, info[v].dfn);
        }
    }
}
int main() {
	bn[0]=1;
	for (int i=1;i<=300000;i++) bn[i]=(bn[i-1] << 1)%P;
	while (~scanf("%d", &T)) {
		for (;T--;) {
			read(n); read(m);
			tot=num=cnt=top=0;ans=1;
			memset(info + 1, 0, n * sizeof(Info));
			for (int i=1,x,y;i<=m;i++) {
				if (~scanf("%d%d", &x, &y)) {
					add(x,y),add(y,x);
				}
			}
			for (int i=1;i<=n;i++)
				if (!info[i].dfn) rt=i,Tarjan(i);
			printf("%d\n", (ans + P) % P);
		}
	}
    return 0;
}

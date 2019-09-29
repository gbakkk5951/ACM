#include<cmath>  
#include<ctime>  
#include<cstdio>  
#include<cstring>  
#include<cstdlib>  
#include<iostream>  
#include<algorithm>  
#include<iomanip>  
#include<vector>  
#include<bitset>  
#include<string>  
#include<queue>  
#include<set>  
#include<map>  
using namespace std;  

typedef long long ll;  

inline int read()  
{  
    int x=0,f=1;char ch=getchar();  
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  
    while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}  
    return x*f;  
}  
void print(int x)  
{if(x<0)putchar('-'),x=-x;if(x>=10)print(x/10);putchar(x%10+'0');}  

const int N=100100;  

int ecnt,last[N];  
struct EDGE{int to,nt;}e[N<<1];  
inline void add(int u,int v)  
{e[++ecnt]=(EDGE){v,last[u]};last[u]=ecnt;}  

int n;  

int dep[N],size[N],mx[N],anc[N][20],son[N];  

void dfs1(int u)  
{ 
    size[u]=1;mx[u]=dep[u];  
    for(int i=1;(1<<i)<dep[u];++i)anc[u][i]=anc[anc[u][i-1]][i-1];  
    for(int i=last[u];i;i=e[i].nt)  
    if(anc[u][0]^e[i].to)  
    {  
        dep[e[i].to]=dep[u]+1;anc[e[i].to][0]=u;  
        dfs1(e[i].to);size[u]+=size[e[i].to];  
        if(mx[e[i].to]>mx[son[u]])son[u]=e[i].to,mx[u]=mx[e[i].to];  
    }
}  

int top[N],len[N];  

void dfs2(int u,int tp,int L)  
{  
    top[u]=tp;len[u]=L;  
    if(son[u])dfs2(son[u],tp,L+1),len[u]=len[son[u]];  
    for(int i=last[u];i;i=e[i].nt)if(e[i].to^son[u]&&e[i].to^anc[u][0])  
    dfs2(e[i].to,e[i].to,1);
}  

bool book[N];  

vector<int>vec_up[N],vec_down[N];  

int div_2[N];  

void initial()  
{  
    register int i,tp,now,L;  
    for(i=1;i<=n;++i)  
    {  
        tp=top[i];  
        if(!book[tp])  
        {  
            book[tp]=1;L=0;now=tp;  
            while(L<len[tp]&&now)
            {  
                now=anc[now][0];  
                L++;  
                vec_up[tp].push_back(now);  
            }
            L=0;now=tp;  
            while(L<len[tp]&&now)  
            {  
                now=son[now];  
                L++;  
                vec_down[tp].push_back(now);  
            }  
        }  
    }  
    int mx_div=1;  
    for(i=1;i<=n;++i)  
    {  
        if((i>>mx_div)&1)mx_div++;  
        div_2[i]=mx_div-1;  
    }  
}  

inline int getanc(int u,int k)  
{  
    if(!k)return u;  
    u=anc[u][div_2[k]];  
    k-=(1<<div_2[k]);  
    if(!k)return u;  
    if(dep[u]-dep[top[u]]==k)return top[u];  
    if(dep[u]-dep[top[u]]>k)return vec_down[top[u]][dep[u]-dep[top[u]]-k-1];  
    return vec_up[top[u]][k-dep[u]+dep[top[u]]-1];  
}  
int main()  
{  
    n=read();  
    register int i,u,v;  
    for(i=1;i<n;++i){u=read();v=read();add(u,v);add(v,u);}  
    dep[1]=1;  
    dfs1(1);dfs2(1,1,1);  
    initial();  
    int Q=read();  
    while(Q--){u=read();v=read();print(getanc(u,v));puts("");}  
    return 0;  
}

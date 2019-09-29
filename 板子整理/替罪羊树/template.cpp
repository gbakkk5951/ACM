#include<bits/stdc++.h>
#define MAXN 800005
#define INF 2e9
using namespace std;
int read(){
    char c;int x=0,y=1;while(c=getchar(),(c<'0'||c>'9')&&c!='-');
    if(c=='-') y=-1;else x=c-'0';while(c=getchar(),c>='0'&&c<='9')
    x=x*10+c-'0';return x*y;
}
const double alpha=0.7;
int n,sz,root;
struct Scapegoat{
    int sum;
    int son[MAXN][2],siz[MAXN],val[MAXN],ct[MAXN],cur[MAXN],fa[MAXN];
    int isbad(int x){
        return (double)siz[x]*alpha>max(siz[son[x][0]],siz[son[x][1]]);
    }
    void recycle(int k){
        if(!k) return;
        recycle(son[k][0]);
        cur[++sum]=k;
        recycle(son[k][1]);
    }
    int build(int l,int r){
        if(l>r) return 0;
        int mid=(l+r)>>1,id=cur[mid];
        fa[son[id][0]=build(l,mid-1)]=id;
        fa[son[id][1]=build(mid+1,r)]=id;
        siz[id]=siz[son[id][0]]+siz[son[id][1]]+1;
        return id;
    }
    void rebuild(int k){
        sum=0;recycle(k);
        int f=fa[k],d=(son[f][1]==k),id=build(1,sum);
        fa[son[f][d]=id]=f;
        if(k==root) root=id;
    }
    void insert(int x){
        if(!root){val[root=++sz]=x,siz[root]=1,fa[root]=0;return;}
        int tmp=root;
        while(1){
            siz[tmp]++;
            int f=tmp,d=(x>=val[tmp]);tmp=son[tmp][d];
            if(!tmp){
                siz[++sz]=1,val[sz]=x,fa[sz]=f,son[f][d]=sz;
                break;
            }
        }
        int flag=0;
        for(int i=sz;i;i=fa[i]) if(!isbad(i)) flag=i;
        if(flag) rebuild(flag);
    }
    int getpl(int x){
        int tmp=root;
        while(tmp){
            if(x==val[tmp]) return tmp;
            int d=(x>=val[tmp]);
            tmp=son[tmp][d];
        }
        return tmp;
    }
    void erase(int k){
        if(son[k][0]&&son[k][1]){
            int tmp=son[k][0];
            while(son[tmp][1]) tmp=son[tmp][1];
            val[k]=val[tmp];k=tmp;
        }
        int s=son[k][0]?son[k][0]:son[k][1],f=fa[k],d=(son[f][1]==k);
        son[f][d]=s;fa[s]=f;
        for(int i=f;i;i=fa[i]) siz[i]--;
        if(root==k) root=s;
    }
    int findRANK(int x){
        int tmp=root,res=0;
        while(tmp){
            if(x<=val[tmp]) tmp=son[tmp][0];
            else res+=siz[son[tmp][0]]+1,tmp=son[tmp][1];
        }
        return res+1;
    }
    int findNUM(int x){
        int tmp=root;
        while(tmp){
            if(x<=siz[son[tmp][0]]){
                tmp=son[tmp][0];continue;
            }
            x-=siz[son[tmp][0]];
            if(x==1) return val[tmp];x--;
            tmp=son[tmp][1];
        }
    }
    int findPRE(int x){
        int ret=-INF,tmp=root;
        while(tmp){
            if(val[tmp]<x) ret=max(ret,val[tmp]),tmp=son[tmp][1];
            else tmp=son[tmp][0];
        }
        return ret;
    }
    int findSUF(int x){
        int ret=INF,tmp=root;
        while(tmp){
            if(val[tmp]>x) ret=min(ret,val[tmp]),tmp=son[tmp][0];
            else tmp=son[tmp][1];
        }
        return ret;
    }
}T;
int main()
{
    n=read();
    for(int i=1;i<=n;i++){
        int type=read(),x=read();
        if(type==1) T.insert(x);
        if(type==2){int p=T.getpl(x);if(p) T.erase(p);}
        if(type==3) printf("%d\n",T.findRANK(x));
        if(type==4) printf("%d\n",T.findNUM(x));
        if(type==5) printf("%d\n",T.findPRE(x));
        if(type==6) printf("%d\n",T.findSUF(x));
    }
    return 0;
}

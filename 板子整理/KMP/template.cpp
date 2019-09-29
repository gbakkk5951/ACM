#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define PI acos((double)-1)
#define E exp(double(1))
#define K 1000000+9
int nt[10000+1];
char a[K],b[10001];
//参数为模板串和next数组
//字符串均从下标0开始
void kmp_next(char *T,int *nt)
{
    nt[0]=0;
    for(int i=1,j=0,m=strlen(T);i<m;i++)
    {
        while(j&&T[i]!=T[j])j=nt[j-1];
        if(T[i]==T[j])j++;
        nt[i]=j;
    }
}
int kmp(char *S,char *T,int *nt)
{
    kmp_next(T,nt);
    int ans=0,sn=strlen(S),tn=strlen(T);
    for(int i=0,j=0;i<sn;i++)
    {
        while(j&&S[i]!=T[j])j=nt[j-1];
        if(S[i]==T[j])j++;
        if(j==tn)
            ans++;
    }
    return ans;
}
int main(void)
{
    int t;cin>>t;
    while(t--)
    {
        scanf("%s%s",b,a);
        printf("%d\n",kmp(a,b,nt));
    }

    return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define debug cout
#define bool unsigned char
typedef long long int lli;
using namespace std;
const int maxn=1e6+1e2,lim=1e6,maxk=1e3+1e1;
const int mod=998244353;

int n,k;

namespace Sieve {
    lli sum[maxn],mem[maxn];
    bool vis[maxn];
    
    inline void pre() {
        static int prime[maxn/10],cnt;
        static bool vis[maxn];
        sum[1] = 1;
        for(int i=2;i<=lim;i++) {
            if( !vis[i] ) prime[++cnt] = i , sum[i] = i - 1;
            for(int j=1;j<=cnt&&(lli)i*prime[j]<=lim;j++) {
                const int tar = i * prime[j];
                vis[tar] = 1;
                if( i % prime[j] ) sum[tar] = sum[i] * ( prime[j] - 1 );
                else {
                    sum[tar] = sum[i] * prime[j];
                    break;
                }
            }
        }
        for(int i=1;i<=lim;i++) sum[i] = ( sum[i] + sum[i-1] ) % mod;
    }
    inline lli getphi(lli x) {
        if( x <= lim ) return sum[x];
        const lli t = n / x;
		if( vis[t] ) return mem[t];
        lli& ret = mem[t]; ret = x * ( x + 1 ) >> 1  , vis[t] = 1;
        for(lli i=2,j;i<=x;i=j+1) {
            j = x / ( x / i );
            ret -= ( j - i + 1 ) * getphi(x/i) % mod , ret %= mod;
        }
        return ret = ( ret % mod + mod ) % mod;
    }
}

namespace Inter {
    lli in[maxk],fac[maxk],facrev[maxk],pprv[maxk],ssuf[maxk],*prv=pprv+1,*suf=ssuf+1;
    inline lli fastpow(lli base,int tim) {
		lli ret = 1;
        while(tim) {
            if( tim & 1 ) ret = ret * base % mod;
            if( tim >>= 1 ) base = base * base % mod;
        }
        return ret;
    }
    inline void init() {
        for(int i=1;i<k;i++) in[i] = fastpow(i,k-2);
        for(int i=1;i<k;i++) in[i] = ( in[i] + in[i-1] ) % mod;
    }
    inline lli getmul(int p) {
        return p ? fac[p] * facrev[k-p-1] % mod : facrev[k-1];
    }
    inline lli getval(lli x) {
        lli ret = 0;
        prv[-1] = 1;
        for(int i=0;i<k;i++) prv[i] = prv[i-1] * (x-i+mod) % mod;
        suf[k] = 1;
        for(int i=k-1;~i;i--) suf[i] = suf[i+1] * (x-i+mod) % mod;
        for(int i=0;i<k;i++) {
            lli now = prv[i-1] * suf[i+1] % mod;
            ret = ret + now * in[i] % mod * getmul(i) % mod , ret %= mod;
        }
        return ret;
    }
    inline void getinv() {
        static lli inv[maxn];
        *fac = 1;
        for(int i=1;i<=k;i++) fac[i] = fac[i-1] * i % mod;
        inv[k] = fastpow(fac[k],mod-2);
        for(int i=k;i;i--) inv[i-1] = inv[i] * i % mod;
        for(int i=1;i<=k;i++) inv[i] = inv[i] * fac[i-1] % mod;
        for(int i=1;i<=k;i++) fac[i] = fac[i-1] * inv[i] % mod;
        facrev[0] = 1;
        for(int i=1;i<=k;i++) facrev[i] = facrev[i-1] * ( mod - inv[i] ) % mod;
    }
}
inline lli segphi(lli l,lli r) {
    return ( Sieve::getphi(r) - Sieve::getphi(l-1) + mod ) % mod;
}
  
inline lli calc(lli n) {
    lli ret = 0;
    for(lli i=1,j;i<=n;i=j+1) {
        j = n / ( n / i );
        ret += segphi(i,j) % mod * Inter::getval(n/i) % mod , ret %= mod;
    }
    return ret;
}

int main() {
    scanf("%d%d",&n,&k) , k += 2 , Sieve::pre() , Inter::init() , Inter::getinv();
    printf("%lld\n",calc(n));
    return 0;
}

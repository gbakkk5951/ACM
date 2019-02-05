#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
#define debug cerr
using namespace std;
const int maxn = 3e2 + 5e1;

class Bigint { // from lowbit to highbit.
private:
    int dat[maxn], len, base; // range from 0 to len - 1.
    Bigint operator /= (const int &x) { // scalar divide used in converting base.
        assert(len);
        for(int i = len - 1; ~i; i--) {
            if(i) dat[i-1] += (dat[i] % x) * base;
            dat[i] /= x;
        }
        while(len && !dat[len-1]) --len;
        return *this;
    }
    int operator % (const int &x) const {// scalar mod used in converting base.
        int ret = 0;
        assert(len), assert(x);
        for(int i = len - 1; ~i; i--) ret = ret * base + dat[i], ret %= x;
        return ret;
    }
public:
    Bigint(int _len = 0, int _base = 10) : len(_len), base(_base) {
        memset(dat, 0, sizeof(dat));
    }
    const int& operator [] (const int &x) const { return dat[x]; }
    int& operator [] (const int &x) { return dat[x]; }
    inline const int& length() const { return len; }
    Bigint operator * (const int &x) const { // scalar multi.
        Bigint ret = *this;
        for(int i = 0; i < len; i++) ret[i] = ret[i] * x % base;
        return ret;
    }
    Bigint operator -= (const Bigint &b) {
        assert(base == b.base && len >= b.len);
        for(int i = 0; i < len; i++) dat[i] = (dat[i] - b[i] + base) % base;
        while(len && !dat[len-1]) --len;
        return *this;
    }
    Bigint operator += (const Bigint &b) {
        assert(base == b.base);
        assert(b.len);
        len = max(len, b.len);
        for(int i = 0; i < len; i++) dat[i] = (dat[i] + b[i]) % base;
	//	dat[i] == 0 ? 
        return *this;
    }
    inline void fromString(char* s) {
        len = strlen(s);
        for(int i = 0; i < len; i++) dat[i] = s[len - 1 - i] - '0';
        while(len && !dat[len-1]) --len;
    }
    inline Bigint convert(int newbase) const {
        Bigint ret(0, newbase), t = *this;
        while(t.length()) ret.dat[ret.len++] = t % newbase, t /= newbase;
        return ret;
    }
    inline void print() const {
        for(int i = len - 1; ~i; i--) putchar(dat[i] + '0');
        putchar('\n');
    }
}in;

int p;

class LinearBase {
private:
    Bigint dat[maxn];
    int maxlen;
    inline int getInv(int base, int p) {
        int ret = 1, tim = p - 2;
        while(tim) {
            if(tim & 1) ret = ret * base % p;
            if(tim >>= 1) base = base * base % p;
        }
        return ret;
    }
public:
    inline void insert(Bigint cur) {
        maxlen = max(maxlen, cur.length());
        for(int i = cur.length() - 1; ~i; i--) if(cur[i]) {
            if(!dat[i].length()) {
                dat[i] = cur * getInv(cur[i],p);
                return;
            } else cur -= dat[i] * cur[i];
        }
    }
    inline Bigint build() {
        Bigint ret(0, p);
        for(int i = maxlen - 1; ~i; i--) if(dat[i].length()) ret += dat[i] * (p - 1 - ret[i]);
        return ret;
    }
}lb;

int main() {
    static int n;
    static char ss[maxn];
    scanf("%d%d", &n, &p);
    for(int i = 1; i <= n; i++) scanf("%s", ss), in.fromString(ss), lb.insert(in.convert(p));
    lb.build().convert(10).print();
    return 0;
}

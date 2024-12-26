#include<bits/extc++.h>
#define int long long
#define Inv(x) binpow(x,mod - 2)
using namespace std;
const int maxn = 1005;
const int mod = 1e9 + 7;
int n,m;
int a[maxn];
struct modint
{
    int val;
    modint(int val = 0):val(val){};
    int &operator()(){return val %= mod;}
    friend modint operator+(modint x,modint y){return ((x() + y()) % mod + mod) % mod;}
    friend modint &operator+=(modint &x,modint y){return x = x + y;}
    friend modint operator-(modint x,modint y){return ((x() - y()) % mod + mod) % mod;}
    friend modint &operator-=(modint &x,modint y){return x = x - y;}
    friend modint operator*(modint x,modint y){return (x() * y() % mod + mod) % mod;}
    friend modint &operator*=(modint &x,modint y){return x = x * y;}
}fac[maxn * maxn],inv[maxn * maxn],f[maxn];
modint binpow(modint x,int y)
{
    modint ret = 1;
    while (y)
    {
        if (y & 1)
            ret *= x;
        x *= x;
        y >>= 1;
    }
    return ret;
}
void init()
{
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= 1e6; i++)
    {
        fac[i] = fac[i - 1] * i;
        inv[i] = Inv(fac[i]);
    }
}
modint c(int n,int m){return n < m || n < 0 || m < 0 ? 0 : fac[n] * inv[m] * inv[n - m];}
signed main()
{
    init();
    scanf("%lld%lld",&n,&m);
    for (int i = 1; i <= m; i++)
        scanf("%lld",a + i);
    for (int i = 0; i < n; i++)
    {
        f[i] = c(n,i);
        for (int j = 1; j <= m; j++)
            f[i] *= c(a[j] + n - i - 1,n - i - 1);
    }
    modint ans = 0;
    for (int i = 0; i < n; i++)
        ans += (i & 1 ? -1 : 1) * f[i];
    printf("%lld",ans());
    return 0;
}
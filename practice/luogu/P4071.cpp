#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;
int fac[maxn],inv[maxn],f[maxn];
int n,m;
int binpow(int x,int y)
{
    int ret = 1;
    while (y)
    {
        if (y & 1)
            ret = ret * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ret;
}
void init()
{
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= 1e6; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = binpow(fac[i],mod - 2);
    }
    f[1] = 0,f[2] = 1;
    for (int i = 3; i <= 1e6; i++)
        f[i] = (i - 1) * (f[i - 1] + f[i - 2]) % mod;
}
void solve()
{
    scanf("%lld%lld",&n,&m);
    if (m == 0)
        printf("%lld",f[n]);
    else if (n - m == 1)
        putchar('0');
    else if (m == n)
        putchar('1');
    else
    {
        int ans = fac[n] * inv[m] % mod * inv[n - m] % mod * f[n - m] % mod;
        printf("%lld",ans);
    }
    putchar('\n');
}
signed main()
{
    init();
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}
#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e7 + 5;
const int mod = 998244353;
int n;
int fac[maxn],inv[maxn],p2[maxn];
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
    fac[0] = p2[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
        p2[i] = (p2[i - 1] << 1) % mod;
    }
    inv[n] = binpow(fac[n],mod - 2);
    for (int i = n - 1; ~i; i--)
        inv[i] = inv[i + 1] * (i + 1) % mod;
}
int c(int n,int m)
{return n < 0 || m < 0 || n < m ? 0 : fac[n] * inv[m] % mod * inv[n - m] % mod;}
signed main()
{
    scanf("%lld",&n);
    init();
    int ans = 0;
    for (int i = (n >> 1) + 1; i <= n; i++)
        ans = (ans + c(n,i) * p2[n - i] % mod) % mod;
    ans = ((binpow(3,n) - (ans << 1) % mod) % mod + mod) % mod;
    printf("%lld",ans);
    return 0;
}
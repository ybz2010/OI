#include<bits/extc++.h>
#define int long long
#define Inv(x) binpow(x,mod - 2)
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 998244353;
int n,m;
int fac[maxn],inv[maxn];
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
int c(int n,int m)
{
    if (n < m)
        return 0;
    return fac[n] * inv[n - m] % mod * inv[m] % mod;
}
int calc(int x){return binpow(10,n - (x << 2)) * c(n - 3 * x,x) % mod;}
signed main()
{
    cin >> n >> m;
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = Inv(fac[i]); 
    }
    int ans = 0;
    for (int i = m; i <= n >> 2; i++)
        ans = (ans + (((i - m) & 1) ? -1 : 1) * c(i,m) * calc(i) % mod + mod) % mod;
    cout << ans;
    return 0;
}
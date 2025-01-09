#include<bits/extc++.h>
#define int long long
#define Inv(x) binpow(x,mod - 2)
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;
int n,k;
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
    if (n < m || n < 0 || m < 0)
        return 0;
    return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
signed main()
{
    cin >> n >> k;
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = Inv(fac[i]);
    }
    int ans = 0,base = 2;
    for (int i = n; i >= k; i--,base = (base * base) % mod)
        ans = (ans + (((i - k) & 1) ? -1 : 1) * c(i,k) % mod * c(n,i) % mod * (base - 1) % mod + mod) % mod; 
    cout << ans;
    return 0;
}
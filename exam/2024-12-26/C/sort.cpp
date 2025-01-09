#include<bits/extc++.h>
#define int long long
#define Inv(x) binpow(x,mod - 2)
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 998244353;
int n;
int c[maxn];
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
void init()
{
    fac[0] = inv[0] = 1; 
    for (int i = 1; i <= 2e5; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = Inv(fac[i]);
    }
}
int C(int n,int m){return n ++,n < m || n < 0 || m < 0 ? 0 : fac[n] * inv[m] % mod * inv[n - m] % mod;}
signed main()
{
    init();
    scanf("%lld",&n);
    for (int i = 1; i < n; i++)
        cin >> c[i];
    int ans = 1;
    for (int i = n; i; i--)
        if (c[i - 1] <= c[i])
            ans = ans * C(c[i],c[i - 1]) % mod;
    cout << ans;
    return 0;
}
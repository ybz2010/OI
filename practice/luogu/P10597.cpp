#include<bits/extc++.h>
#define int long long
#define Inv(x) binpow(x,mod - 2)
using namespace std;
const int maxn = 2005;
const int mod = 1e9 + 9;
int n;
int a[maxn],cnt[maxn];
int fac[maxn],inv[maxn];
int dp[maxn][maxn];
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
    for (int i = 1; i <= 2000; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = Inv(fac[i]);
    }
}
int c(int n,int m){return n < m || n < 0 || m < 0 ? 0 : fac[n] * inv[m] % mod * inv[n - m] % mod;}
signed main()
{
    init();
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",a + i);
        cnt[a[i]] ++;
    }
    sort(a + 1,a + n + 1);
    int m = unique(a + 1,a + n + 1) - a - 1,tmp = 0;
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++)
    {
        tmp += cnt[a[i]];
        for (int j = 0; j <= tmp; j++)
            for (int k = 0; k <= min(j,cnt[a[i]]); k++)
                dp[i][j] = (dp[i][j] + dp[i - 1][j - k] * c(tmp - j,cnt[a[i]] - k) % mod * c(cnt[a[i]],k) % mod) % mod;
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
        ans = ((ans + (i & 1 ? -1 : 1) * dp[m][i]) % mod + mod) % mod;
    printf("%lld",ans);
    return 0;
}
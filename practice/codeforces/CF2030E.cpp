#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 998244353;
int n,m;
int a[maxn];
vector<int>fac(maxn),inv(maxn);
vector<vector<int> >dp;
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
int Inv(int x){return binpow(x,mod - 2);}
int C(int m,int n)//n里取m个
{
    if (m > n)
        return 0;
    else if (m == 0)
        return 1;
    return fac[n] * inv[n - m] % mod * inv[m] % mod;
}
void solve()
{
    scanf("%lld",&n);
    vector<int>cnt(n + 5,0);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",a + i);
        cnt[a[i]] ++;
    }
    vector<int>suf1(n + 5,0);
    for (int i = n; i >= 0; i--)
        suf1[i] = (suf1[i + 1] + cnt[i]) % mod;
    for (int i = n; i >= 0; i--)
        suf1[i] = binpow(2,suf1[i]);
    vector<vector<int> >dp(n + 5,vector<int>(0));
    dp[0].resize(cnt[0] + 5,0);
    for (int i = 0; i <= cnt[0]; i++)
        dp[0][i] = C(i,cnt[0]);
    vector<int>suf2(n + 5,0);
    for (int i = cnt[0]; i >= 0; i--)
        suf2[i] = (suf2[i + 1] + dp[0][i]) % mod;
    m = cnt[0];
    for (int i = 1; i < n; i++)
    {
        m = min(m,cnt[i]);
        dp[i].resize(m + 5,0);
        vector<int>suf3(cnt[i] + 5,0);
        for (int j = cnt[i]; j >= 0; j--)
            suf3[j] = (suf3[j + 1] + C(j,cnt[i])) % mod;
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = (dp[i][j] + suf2[j + 1] * C(j,cnt[i]) % mod) % mod;
            dp[i][j] = (dp[i][j] + dp[i - 1][j] * suf3[j] % mod) % mod;
        }
        suf2[m + 1] = 0;
        for (int j = m; j >= 0; j--)
            suf2[j] = (suf2[j + 1] + dp[i][j]) % mod;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 1; j < dp[i].size(); j++)
            ans = (ans + dp[i][j] * j % mod * suf1[i + 1] % mod) % mod;
    printf("%lld\n",ans);
}
signed main()
{
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= 2e5; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = inv[i - 1] * Inv(i) % mod;
    }
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}
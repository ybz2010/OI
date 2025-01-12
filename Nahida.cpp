#include <bits/stdc++.h>
#define int long long

using namespace std;
const int maxn = 3e3 + 10, mod = 1e9 + 7;
int n, m, k, mp[maxn][maxn], dp[maxn], g[maxn], _dp[maxn], _g[maxn];

inline int sum_dp(int l, int r)
{
    l = max(l, 1LL), r = min(r, m);
    return (_dp[r] - _dp[l - 1] + mod) % mod;
}

inline int sum_g(int l, int r)
{
    l = max(l, 1LL), r = min(r, m);
    return (_g[r] - _g[l - 1] + mod) % mod;
}

signed main()
{
    scanf("%lld %lld %lld", &n, &m, &k);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            scanf("%1lld", &mp[i][j]);
    }
    _dp[1] = 1;
    for (int i = 2; i <= m; i++)
    {
        _dp[i] = _dp[i - 1] + 1;
        if (mp[1][i] == mp[1][i - 1])
            _g[i] = _g[i - 1] + 1;
        else
            _g[i] = _g[i - 1];
    }
    for (int i = 2; i <= n; i++)
    {
        g[1] = 0;
        dp[1] = ((sum_dp(1,1 + k) - sum_g(1,1 + k)) % mod + mod) % mod;
        for (int j = 2; j <= m; j++)
        {
            if (mp[i][j] == mp[i][j - 1])
                g[j] = ((sum_dp(j - k,j + k - 1) - sum_g(j - k + 1,j + k - 1)) % mod + mod) % mod;
            else
                g[j] = 0;
            dp[j] = ((sum_dp(j - k,j + k) - sum_g(j - k + 1,j + k)) % mod + mod) % mod;
        }
        for (int j = 1; j <= m; j++)
        {
            _dp[j] = (_dp[j - 1] + dp[j]) % mod;
            _g[j] = (_g[j - 1] + g[j]) % mod;
        }
    }
    printf("%lld\n", (_dp[m] - _g[m] + mod) % mod);
    return 0;
}
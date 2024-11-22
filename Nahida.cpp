#include <bits/stdc++.h>
#define int long long
using namespace std;
int read()
{
    int x = 0;
    int ff = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            ff = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * ff;
}
const int N = 1e5 + 6;
const int inf = LONG_LONG_MAX;
int n, E, t, x[N], dp[N], k = 1e10, l = 1, r = 1, q[N];
signed main()
{
    memset(dp, 0x7f, sizeof(dp));
    n = read();
    E = read();
    t = read();
    for (int i = 1; i <= n; i++)
        x[i] = read();
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        while (l <= r && 2 * (x[i] - x[q[l] + 1]) > t)
        {
            k = min(k, dp[q[l]] - 2 * x[q[l] + 1]);
            l++;
        }
        dp[i] = min(dp[i], dp[q[l]] + t);
        dp[i] = min(dp[i], k + 2 * x[i]);
        cout << dp[i] << " ";
        q[++r] = i;
    }
    printf("%lld\n", dp[n] + E);
    return 0;
}
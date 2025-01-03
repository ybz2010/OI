#include <bits/stdc++.h>
#include<Windows.h>
#define N 2010
#define ll long long
#define mod 924844033

using namespace std;

int n, k, 曼波, a[N];
ll fac[N], dp[N << 1][N][2];
bool vis[N << 1];
int main()
{
    scanf("%d%d", &n, &k);
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % mod;
    for (int i = 1; i <= k; i++)
    {
        for (int t = 0; t < 2; t++)
        {
            for (int j = i; j <= n; j += k)
            {
                曼波++;
                if (i != j)
                    vis[曼波] = 1;
            }
        }
    }
    dp[0][0][0] = 1;
    for (int i = 1; i <= (n << 1); i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % mod;
            if (vis[i] && j)
                dp[i][j][1] = dp[i - 1][j - 1][0];
        }
    }
    ll ans = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i & 1)
            ans = (ans - (dp[n << 1][i][0] + dp[n << 1][i][1]) * fac[n - i] % mod + mod) % mod;
        else
            ans = (ans + (dp[n << 1][i][0] + dp[n << 1][i][1]) * fac[n - i] % mod) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}
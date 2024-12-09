#include<bits/extc++.h>
using namespace std;
int n,l;
int c[205][205],p[1005];
int dp[1005][205][205];
void solve()
{
    cin >> l >> n;
    for (int i = 1; i <= l; i++)
        for (int j = 1; j <= l; j++)
            cin >> c[i][j];
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    memset(dp,0x7f,sizeof dp);
    p[0] = 3;
    dp[0][1][2] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int x = 1; x <= l; x++)
        {
            if (x == p[i])
                continue;
            for (int y = 1; y <= l; y++)
            {
                if (y == p[i] || x == y)
                    continue;
                dp[i + 1][x][y] = min(dp[i + 1][x][y],dp[i][x][y] + c[p[i]][p[i + 1]]);
                dp[i + 1][p[i]][y] = min(dp[i + 1][p[i]][y],dp[i][x][y] + c[x][p[i + 1]]);
                dp[i + 1][x][p[i]] = min(dp[i + 1][x][p[i]],dp[i][x][y] + c[y][p[i + 1]]);
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 1; i <= l; i++)
        for (int j = 1; j <= l; j++)
            ans = min(ans,dp[n][i][j]);
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
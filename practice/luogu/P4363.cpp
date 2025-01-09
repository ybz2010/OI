#include<bits/extc++.h>
#define inf 0x7f7f7f7f7f7f7f7f
#define int long long
using namespace std;
int n,m;
int a[15][15],b[15][15];
int dp[(1 << 20) + 5];
int dfs(int sta,int wh)
{
    if (dp[sta] != inf)
        return dp[sta];
    dp[sta] = wh ? -inf : inf;
    int x = n,y = 0;
    for (int i = 0; i < n + m - 1; i++)
    {
        if ((1 << i) & sta)
            x --;
        else
            y ++;
        if (((sta >> i) & 0b11) != 1)
            continue;
        if (wh)
            dp[sta] = max(dp[sta],dfs(sta ^ (0b11 << i),wh ^ 1) + a[x][y]);
        else
            dp[sta] = min(dp[sta],dfs(sta ^ (0b11 << i),wh ^ 1) - b[x][y]);
    }
    return dp[sta];
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> b[i][j];
    memset(dp,0x7f,sizeof dp);
    dp[((1 << n) - 1) << m] = 0;
    cout << dfs((1 << n) - 1,1);
    return 0;
}
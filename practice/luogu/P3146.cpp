#include<bits/extc++.h>
using namespace std;
int n;
int dp[250][250];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> dp[i][i];
    for (int len = 2; len <= n; len ++)
        for (int i = 1,j = len; j <= n; i++,j++)
            for (int k = i; k < j; k++)
                if (dp[i][k] == dp[k + 1][j] && dp[i][k])
                    dp[i][j] = max(dp[i][j],dp[i][k] + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            ans = max(ans,dp[i][j]);
    cout << ans;
    return 0;
}
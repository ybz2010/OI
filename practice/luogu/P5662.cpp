#include<bits/extc++.h>
using namespace std;
const int maxn = 105;
int t,n,m;
int p[maxn][maxn];
int dp[100005];
signed main()
{
    scanf("%d%d%d",&t,&n,&m);
    for (int i = 1; i <= t; i ++)
        for (int j = 1; j <= n; j ++)
            scanf("%d",&p[i][j]);
    int ans = m;
    for (int i = 1; i <= t; i++)
    {
        fill(dp + 1,dp + 100001,0);
        dp[ans] = ans;
        for (int j = 1; j <= n; j++)
            for (int k = ans; k >= p[i][j]; k--)
                dp[k - p[i][j]] = max(dp[k - p[i][j]],dp[k] + p[i + 1][j] - p[i][j]);
        int _max = 0;
        for (int j = 0; j <= ans; j++)
            _max = max(_max,dp[j]);
        ans = _max;
    }
    cout << ans;
    return 0;
}
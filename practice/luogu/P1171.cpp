#include<bits/extc++.h>
using namespace std;
int n;
int dis[25][25];
int dp[(1 << 20) + 5][25];
signed main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d",&dis[i][j]);
    memset(dp,0x3f,sizeof dp);
    dp[1][1] = 0;
    for (int i = 0; i < (1 << n); i++)
        for (int j = 1; j <= n; j++)
            if (!(i & (1 << (j - 1))))
                for (int k = 1; k <= n; k++)
                    if (i & (1 << (k - 1)))
                        dp[i | (1 << (j - 1))][j] = min(dp[i | (1 << (j - 1))][j],dp[i][k] + dis[k][j]);
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++)
        ans = min(ans,dp[(1 << n) - 1][i] + dis[i][1]);
    printf("%d",ans);
    return 0;
}
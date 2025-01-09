#include<bits/extc++.h>
#define int unsigned long long
#define inf 0x7f7f7f7f7f7f7f7f
using namespace std;
const int maxn = (1 << 12) + 5;
int n,m;
int dis[15][15];
int w[15][maxn],dp[15][maxn];
signed main()
{
    scanf("%llu%llu",&n,&m);
    memset(dp,0x7f,sizeof dp);
    memset(dis,0x7f,sizeof dis);
    memset(w,0x7f,sizeof w);
    for (int i = 1; i <= n; i++)
        dis[i][i] = 0;
    for (int i = 1; i <= m; i ++)
    {
        int a,b,c;
        scanf("%llu%llu%llu",&a,&b,&c);
        dis[a][b] = dis[b][a] = min(dis[a][b],c);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < (1 << n); j++)
            for (int k = 1; k <= n; k++)
                if (!(j & (1 << (i - 1))) && (j & (1 << (k - 1))))
                    w[i][j] = min(w[i][j],dis[i][k]);
    for (int i = 1; i <= n; i++)
        dp[1][(1 << (i - 1))] = 0;
    for (int i = 1; i < (1 << n); i++)
    {
        for (int j = i & (i - 1); j; j = i & (j - 1))
        {
            int tmp = 0;
            for (int k = 1; k <= n; k++)
            {
                if ((1 << (k - 1)) & (i - j))
                {
                    if (w[k][j] > inf)
                        tmp = inf;
                    else
                        tmp += w[k][j];
                }
            }
            for (int k = 2; k <= n; k++)
                if (dp[k - 1][j] != inf && tmp != inf)
                    dp[k][i] = min(dp[k][i],dp[k - 1][j] + tmp * (k - 1));
        }
    }
    int ans = inf;
    for (int i = 2; i <= n; i++)
        ans = min(ans,dp[i][(1 << n) - 1]);
    printf("%llu",ans == inf ? 0 : ans);
    return 0;
}
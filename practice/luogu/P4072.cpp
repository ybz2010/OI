#include<bits/extc++.h>
#define int long long
#define sq(x) ((x) * (x))
using namespace std;
const int maxn = 3005;
int n,m;
int dis[maxn];
int dp[maxn][maxn];//dp[i][j]表示走了i段路用了j天的最小答案
signed main()
{
    scanf("%lld%lld",&n,&m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",dis + i);
        dis[i] += dis[i - 1];
    }
    memset(dp,0x3f,sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 0; k < i; k++)
                dp[i][j] = min(dp[i][j],dp[k][j - 1] + m * sq(dis[i] - dis[k]) - 2 * (dis[i] - dis[k]) * dis[n]);
    printf("%lld",dp[n][m] + sq(dis[n]));
    return 0;
}
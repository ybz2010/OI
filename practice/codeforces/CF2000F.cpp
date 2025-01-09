#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,k;
int a[1005],b[1005];
int dp[1005][105];
void solve()
{
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; i++)
        scanf("%d%d",a + i,b + i);
    memset(dp,inf,sizeof dp);
    dp[1][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = a[i],y = b[i];
        int cost = 0;
        for (int j = 0; j <= a[i] + b[i]; j++)
        {
            for (int j1 = 0; j1 + j <= k; j1++)
                dp[i + 1][j1 + j] = min(dp[i + 1][j1 + j],dp[i][j1] + cost);
            if (j < a[i] + b[i])
            {
                if (x >= y)
                {
                    x --;
                    cost += y;
                }
                else    
                {
                    y --;
                    cost += x;
                }
            }
        }
    }
    printf("%d\n",dp[n + 1][k] == inf ? -1 : dp[n + 1][k]);
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}
#include<bits/extc++.h>
#define inf 0x7f7f7f7f7f7f7f7f
#define int long long
using namespace std;
const int maxn = 3e5 + 5;
int n,m;
int a[maxn],b[maxn],sum[maxn];
void solve()
{
    scanf("%lld%lld",&n,&m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",a + i);
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= m; i++)
        scanf("%lld",b + i);
    int ans = inf;
    vector<vector<int> > dp(n + 5,vector<int>(m + 5,inf));
    dp[1][1] = 0;
    for (int j = 1; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            int pos = upper_bound(sum + i,sum + n + 1,b[j] + sum[i - 1]) - sum;
            if (pos > i)
                dp[pos][j] = min(dp[pos][j],dp[i][j] + m - j);
            dp[i][j + 1] = min(dp[i][j + 1],dp[i][j]);
        }
        ans = min(ans,dp[n + 1][j]);
    }
    printf("%lld\n",ans == inf ? -1 : ans);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}
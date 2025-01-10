#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 2e4 + 5;
int n,tot;
int w[maxn],sum[maxn],dis[maxn];
int dp[maxn];
signed main()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld",w + i,dis + i);
        sum[i] = sum[i - 1] + w[i];
    }
    for (int i = n; i >= 1; i--)
    {
        dis[i] += dis[i + 1];
        tot += dis[i] * w[i];
    }
	cout << tot;
    int ans = inf;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = inf;
        for (int j = 1; j < i; j++)
            dp[i] = min(dp[i],tot - dis[j] * sum[j] - dis[i] * (sum[i] - sum[j]));
		cout << dp[i] << endl;;
        ans = min(ans,dp[i]);
    }
    printf("%lld",ans);
    return 0;
}
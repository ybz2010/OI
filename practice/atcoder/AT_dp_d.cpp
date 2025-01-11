#include<bits/extc++.h>
#define int long long 
using namespace std;
const int maxn = 1e5 + 5;
int n,sum;
int dp[maxn];
int w[105],v[105];
signed main()
{
    scanf("%lld%lld",&n,&sum);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld",w + i,v + i);
        for (int j = sum; j >= w[i]; j--)
            dp[j] = max(dp[j],dp[j - w[i]] + v[i]);
    }
    int ans = 0;
    for (int i = 1; i <= sum; i++)
        ans = max(ans,dp[i]);
    printf("%lld",ans);
    return 0;
}
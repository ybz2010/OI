#include<bits/extc++.h>
#define inf 0x7f7f7f7f7f7f7f7f
#define int long long
using namespace std;
const int maxn = 505;
int n;
int a[maxn];
int dp[maxn][maxn],pre[maxn];
int sum(int l,int r)
{
    if (l > r)
        return 0;
    return pre[r] - pre[l - 1];
}
signed main()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",a + i);
        pre[i] = pre[i - 1] + a[i];
    }
    for (int len = 2; len <= n; len ++)
    {
        for (int l = 1; l + len - 1 <= n; l ++)
        {
            int r = l + len - 1;
            dp[l][r] = inf;
            for (int i = l; i <= r; i ++)
                dp[l][r] = min(dp[l][r],max(sum(l,i - 1) + dp[i + 1][r],sum(i + 1,r) + dp[l][i - 1]));
        }
    }
    cout << dp[1][n];
    return 0;
}
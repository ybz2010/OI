#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 505;
int n;
int a[maxn],pre[maxn];
int dp[maxn][maxn];
signed main()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",a + i);
        pre[i] = pre[i - 1] + a[i];
        dp[i][i] = 0;
    }
    for (int len = 2; len <= n; len ++)
    {
        for (int l = 1; l + len - 1 <= n; l ++)
        {
            int r = l + len - 1;
            for (int i = l; i <= r; i ++)
            {
                dp[l][r] = max(dp[l][r],pre[i - 1] - pre[l - 1] + dp[i + 1][r]);
                dp[l][r] = max(dp[l][r],pre[r] - pre[i] + dp[l][i - 1]);
            }
        }
    }
    cout << dp[1][n];
    return 0;
}
#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2005;
int n,v[maxn];
int dp[maxn][maxn];
signed main()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",v + i);
        dp[i][i] = v[i] * n;
    }
    for (int len = 2; len <= n; len ++)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            dp[i][j] = max(dp[i][j],max(dp[i + 1][j] + v[i] * (n - len + 1),dp[i][j - 1] + v[j] * (n - len + 1)));
        }
    }
    cout << dp[1][n];
    return 0;
}
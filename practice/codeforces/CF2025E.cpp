#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 998244353;
const int maxn = 505;
int n,m;
int dp1[maxn][maxn],dp2[maxn][maxn];
signed main()
{
    scanf("%lld%lld",&n,&m);
    dp1[0][0] = 1;
    for (int i = 1; i <= m; i++)
    {
        dp1[i][0] = dp1[i - 1][1];
        for (int j = 1; j <= m; j++)
            dp1[i][j] = (dp1[i - 1][j - 1] + dp1[i - 1][j + 1]) % mod;
    }
    dp2[1][0] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = j; k <= m; k++)
                dp2[i][k] = (dp2[i][k] + dp2[i - 1][k - j] * dp1[m][j] % mod) % mod;
    int ans = 0;
    for (int i = 0; i <= m; i++)
        ans = (ans + dp1[m][i] * dp2[n][i] % mod) % mod;
    printf("%lld",ans);
    return 0;
}
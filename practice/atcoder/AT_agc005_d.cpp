#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2005;
const int mod = 924844033;
int n,k,idx;
bool vis[maxn << 1];
int fac[maxn],dp[maxn << 1][maxn][2];
void init()
{
    fac[0] = 1;
    for (int i = 1; i <= 2000; i++)
        fac[i] = fac[i - 1] * i % mod;
}
signed main()
{
    init();
    scanf("%lld%lld",&n,&k);
    for (int i = 1; i <= k; i++)
    {
        for (int x = 0; x < 2; x++)
        {
            for (int j = i; j <= n; j += k)
            {
                idx ++;
                if (j != i)
                    vis[idx] = 1;
            }
        }
    }
    dp[0][0][0] = 1;
    for (int i = 1; i <= (n << 1); i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % mod;
            if (vis[i] && j)
                dp[i][j][1] = dp[i - 1][j - 1][0];
        }
    }
    int ans = 0;
    for (int i = 0; i <= n; i++)
        ans = ((ans + (i & 1 ? -1 : 1) * (dp[n << 1][i][0] + dp[n << 1][i][1]) % mod * fac[n - i] % mod) + mod) % mod;
    printf("%lld",ans);
    return 0;
}
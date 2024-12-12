#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 1e8;
int n,m;
int a[400],cnt;
int dp[15][400];
int mp[15];
signed main()
{
    scanf("%lld%lld",&n,&m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int ch;
            scanf("%lld",&ch);
            mp[i] = (mp[i] << 1) + (ch == 1);
        }
    }
    for (int i = 0; i < (1 << m); i++)
    {
        if ((i & (i << 1) || i & (i >> 1)))
            continue;
        cnt ++;
        a[cnt] = i;
        if ((mp[1] & i) == i)
            dp[1][cnt] = 1;
    }
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= cnt; j++)
            if ((a[j] & mp[i]) == a[j])
                for (int k = 1; k <= cnt; k++)
                    if (!(a[j] & a[k]))
                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
    int ans = 0;
    for (int i = 1; i <= cnt; i++)
        ans = (ans + dp[n][i]) % mod;
    printf("%lld",ans);
    return 0;
}
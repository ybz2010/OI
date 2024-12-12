#include<bits/extc++.h>
using namespace std;
int l,n,m;
int a[305],b[305][305];
bool dp[305][305][305],sum[305][305];
void solve()
{
    scanf("%d%d%d",&l,&n,&m);
    for (int i = 1; i <= l; i++)
        scanf("%d",a + i);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d",&b[i][j]);
    memset(dp,0,sizeof dp);
    memset(sum,0,sizeof sum);
    for (int k = l; k >= 1; k--)
    {
        for (int i = n; i >= 1; i--)
        {
            for (int j = m; j >= 1; j--)
            {
                if (b[i][j] == a[k] && !sum[i + 1][j + 1])
                    dp[k][i][j] = 1;
                else
                    dp[k][i][j] = 0;
            }
        }
        for (int i = n; i >= 1; i--)
            for (int j = m; j >= 1; j--)
                sum[i][j] = (sum[i][j + 1] | sum[i + 1][j] | dp[k][i][j]);
    }
    bool ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans |= dp[1][i][j];
    puts(ans ? "T" : "N");
}
signed main()
{
    int t;
    scanf("%d",&t);
    while (t--)
        solve();
    return 0;
}
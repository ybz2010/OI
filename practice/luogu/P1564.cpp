#include<bits/extc++.h>
using namespace std;
const int maxn = 2505;
int n,m;
int cnt1[maxn],cnt2[maxn];
int dp[maxn];
signed main()
{
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d",&x);
        cnt1[i] = cnt1[i - 1],cnt2[i] = cnt2[i - 1];
        if (x == 1)
            cnt1[i] ++;
        else
            cnt2[i] ++;
    }
    memset(dp,0x7f,sizeof dp);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int c1 = cnt1[i] - cnt1[j];
            int c2 = cnt2[i] - cnt2[j];
            if (abs(c1 - c2) <= m || c1 == 0 || c2 == 0)
                dp[i] = min(dp[i],dp[j] + 1);
        }
    }
    cout << dp[n];
    return 0;
}
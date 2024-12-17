#include<bits/extc++.h>
#define ll long long
using namespace std;
const int maxn = 1005;
const int maxm = 1e6 + 5;
int n,m;
int w1[maxn],w2[maxn];
ll v1[maxn],v2[maxn],sum1,sum2;
ll dp1[maxm],dp2[maxm];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> w1[i] >> v1[i];
        sum1 += w1[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> w2[i] >> v2[i];
        sum2 += w2[i];
    }
    memset(dp1,~0x3f,sizeof dp1);
    dp1[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = sum1; j >= w1[i]; j--)
            dp1[j] = max(dp1[j],dp1[j - w1[i]] + v1[i]);
    memset(dp2,~0x3f,sizeof dp2);
    dp2[0] = 0;
    for (int i = 1; i <= m; i++)
        for (int j = sum2; j >= w2[i]; j--)
            dp2[j] = max(dp2[j],dp2[j - w2[i]] + v2[i]);
    ll ans = 0;
    for (int i = 1; i <= min(sum1,sum2); i++)
        ans = max(ans,dp1[i] + dp2[i]);
    cout << ans;
    return 0;
}
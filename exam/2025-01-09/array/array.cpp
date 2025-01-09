#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 1e5 + 5;
int n;
int a[maxn],b[maxn];
int pre[maxn][2],suf[maxn][2];
int _pre[maxn],_suf[maxn];//分别表示pre的后缀最大，suf的前缀最大
int dp1[maxn][2][2],dp2[maxn][2][2];
int _dp1[maxn],_dp2[maxn];
void init()
{
    memset(pre,0,sizeof pre);
    memset(suf,0,sizeof suf);
    memset(_pre,~0x3f,sizeof _pre);
    memset(_suf,~0x3f,sizeof _suf);
    memset(dp1,0,sizeof dp1);
    memset(dp2,0,sizeof dp2);
    memset(_dp1,~0x3f,sizeof _dp1);
    memset(_dp2,~0x3f,sizeof _dp2);
}
void solve()
{
    init();
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    for (int j = 1; j <= n; j++)
        scanf("%lld",b + j);
    for (int i = 1; i <= n; i++)
    {
        pre[i][0] = pre[i - 1][0] + a[i] + b[i];
        pre[i][1] = pre[i][0] + max(a[i + 1],b[i + 1]);
    }
    for (int i = n; i >= 1; i--)
    {
        suf[i][0] = suf[i + 1][0] + a[i] + b[i];
        suf[i][1] = suf[i][0] + max(a[i - 1],b[i - 1]);
    }
    for (int i = 1; i <= n; i++)
        _suf[i] = max({_suf[i - 1],suf[i][0],suf[i + 1][1]});
    for (int i = n; i >= 1; i--)
        _pre[i] = max({_pre[i + 1],pre[i][0],pre[i - 1][1]});
    for (int i = 1; i <= n; i++)
    {
        dp1[i][0][0] = max({0ll,dp1[i - 1][0][1],dp1[i - 1][1][1]}) + max(a[i],b[i]);
        dp1[i][0][1] = max(0ll,dp1[i][0][0]) + min(a[i],b[i]);
        dp1[i][1][0] = max({0ll,dp1[i - 1][0][1],dp1[i - 1][1][1]}) + min(a[i],b[i]);
        dp1[i][1][1] = max(0ll,dp1[i][1][0]) + max(a[i],b[i]);
        _dp1[i] = max({_dp1[i - 1],dp1[i][0][0],dp1[i][0][1],dp1[i][1][0],dp1[i][1][1]});
    }
    for (int i = n; i >= 1; i--)
    {
        dp2[i][0][0] = max({0ll,dp2[i + 1][0][1],dp2[i + 1][1][1]}) + min(a[i],b[i]);
        dp2[i][0][1] = max(0ll,dp2[i][0][0]) + max(a[i],b[i]);
        dp2[i][1][0] = max({0ll,dp2[i + 1][0][1],dp2[i + 1][1][1]}) + max(a[i],b[i]);
        dp2[i][1][1] = max(0ll,dp2[i][1][0]) + min(a[i],b[i]);
        _dp2[i] = max({_dp2[i + 1],dp2[i][0][0],dp2[i][0][1],dp2[i][1][0],dp2[i][1][1]});
    }
    int ans = inf;
    for (int i = 1; i <= n; i++)
        ans = min(ans,max({
            max(0ll,_suf[i - 1] - suf[i][0]) + max(0ll,_pre[i + 1] - pre[i][0]) + a[i] + b[i],
            min(
                max(
                    max(0ll,_suf[i - 1] - suf[i][0]) + min(a[i],b[i]),
                    max(0ll,_pre[i + 1] - pre[i][0]) + max(a[i],b[i])
                ),
                max(
                    max(0ll,_suf[i - 1] - suf[i][0]) + max(a[i],b[i]),
                    max(0ll,_pre[i + 1] - pre[i][0]) + min(a[i],b[i])
                )
            ),
            max(_dp1[i - 1],_dp2[i + 1])
        }));
    printf("%lld\n",max(ans,0ll));
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}
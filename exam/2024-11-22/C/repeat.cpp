#include<bits/extc++.h>
#define int long long
#define inf 0x7f7f7f7f7f7f7f7f
using namespace std;
const int maxn = 100000 + 5;
int n,e,t;
int x[maxn];
int dp[maxn];
signed main()
{
    scanf("%lld%lld%lld",&n,&e,&t);
    for (int i = 1; i <= n; i++)
        scanf("%lld",x + i);
    dp[0] = 0;
    int _min = inf;
    int q[maxn],l,r;
    l = r = 1;
    for (int i = 1; i <= n; i++)
    {
        while (l <= r && 2 * (x[i] - x[q[l] + 1]) > t)
        {
            _min = min(_min,dp[q[l]] - 2 * x[q[l] + 1]);
            l ++;
        }
        dp[i] = min(dp[q[l]] + t,_min + 2 * x[i]);
        q[++r] = i;
    }
    cout << dp[n] + e;
    return 0;
}
/*
3 9 3
1 3 8
*/
#include<bits/extc++.h>
#define int long long
#define sq(x) ((x) * (x))
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 1e5 + 5;
int n;
int h[maxn],w[maxn],dp[maxn];
signed main()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
        scanf("%lld",h + i);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",w + i);
        w[i] += w[i - 1];
    }
    for (int i = 2; i <= n; i++)
    {
        dp[i] = inf;
        for (int j = 1; j < i; j++)
            dp[i] = min(dp[i],dp[j] + w[i - 1] - w[j] + sq(h[i] - h[j]));
    }
    cout << dp[n];
    return 0;
}
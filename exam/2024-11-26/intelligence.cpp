#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 5;
int n,k,idx;
int h[maxn],sum[maxn],g[25],pos[25];
signed main()
{
    scanf("%lld%lld",&n,&k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld",h + i);
        sum[i] = sum[i - 1] + h[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= idx; j++)
            g[j] = __gcd(g[j],h[i]);
        if (g[idx] != h[i])
        {
            g[++idx] = h[i];
            pos[idx] = i;
        }
        int idx1 = 0;
        for (int j = 1; j <= idx; j++)
        {
            if (g[j] != g[j - 1])
            {
                g[++idx1] = g[j];
                pos[idx1] = pos[j];
            }
        }
        idx = idx1;
        for (int j = 1; j <= idx; j++)
            if (i - pos[j] + 1>= k)
                ans = max(ans,g[j] * (sum[i] - sum[pos[j] - 1]));
    }
    cout << ans;
    return 0;
}
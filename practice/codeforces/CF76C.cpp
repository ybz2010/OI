#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
const int maxm = 1 << 22 | 5;
int n,k,T,u;
int s[maxn],a[25][25];
int f[maxm],dp[maxm];
signed main()
{
    scanf("%lld%lld%lld",&n,&k,&T);
    for (int i = 1,ch; i <= n; i++)
    {
        do
        {
            ch = getchar();
        } while (ch < 'A' || ch > 'Z');
        s[i] = ch - 'A';
        u |= (1 << s[i]);
    }
    for (int i = 0; i < k; i++)
        scanf("%lld",dp + (1 << i));
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++) 
            scanf("%lld",a[i] + j);
    memset(f,0xff,sizeof f);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (~f[j])
            {
                if (!(f[j] & (1 << j)) && !(f[j] & (1 << s[i])))
                {
                    dp[f[j]] += a[j][s[i]];
                    dp[f[j] | (1 << j)] -= a[j][s[i]];
                    dp[f[j] | (1 << s[i])] -= a[j][s[i]];
                    dp[f[j] | (1 << j) | (1 << s[i])] += a[j][s[i]];
                }
                f[j] |= (1 << s[i]);
            }
        }
        f[s[i]] = 0;
    }
    for (int i = 0; i < k; i++)
        for (int j = 0; j < (1 << k); j++)
            if (j & (1 << i))
                dp[j] += dp[j ^ (1 << i)];
    int ans = 0;
    for (int i = 0; i < (1 << k); i++)
        if ((i & u) == i && dp[i] <= T && i != u)
            ans++;
    printf("%lld",ans);
    return 0;
}
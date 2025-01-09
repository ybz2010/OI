#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 4e5 + 5;
int q,s;
int c[4],d[4];
int dp[maxn];
signed main()
{
    for (int i = 0; i < 4; i++)
        scanf("%lld",c + i);
    dp[0] = 1;
    for (int j = 0; j < 4; j++)
        for (int i = c[j]; i <= 4e5; i++)
            dp[i] += dp[i - c[j]];
    scanf("%lld",&q);
    while (q--)
    {
        for (int i = 0; i < 4; i++)
            scanf("%lld",d + i);
        scanf("%lld",&s);
        int ans = dp[s];
        for (int k = 1; k < (1 << 4); k++)
        {
            int tmp = s;
            for (int i = 0; i < 4; i++)
                if (k & (1 << i))
                    tmp -= (d[i] + 1) * c[i];
            if (tmp >= 0)
                ans += (__builtin_popcount(k) & 1 ? -1 : 1) * dp[tmp];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
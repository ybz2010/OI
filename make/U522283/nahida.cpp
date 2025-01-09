#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 1 << 18 | 5;
int n;
struct Nahida
{
    int max1,max2;
    int min1,min2;
    Nahida(){max1 = max2 = min1 = min2 = 0;};
    friend Nahida operator+(Nahida x,Nahida y)
    {
        Nahida ret;
        if (x.max1 > y.max1)
        {
            ret.max1 = x.max1;
            ret.max2 = max(x.max2,y.max1);
        }
        else
        {
            ret.max1 = y.max1;
            ret.max2 = max(x.max1,y.max2);
        }
        if (x.min1 < y.min1)
        {
            ret.min1 = x.min1;
            ret.min2 = min(x.min2,y.min1);
        }
        else
        {
            ret.min1 = y.min1;
            ret.min2 = min(x.min1,y.min2);
        }
        return ret;
    }
}dp[maxn];
signed main()
{
    scanf("%lld",&n);
    for (int i = 0,x; i < (1 << n); i++)
    {
        scanf("%lld",&x);
        dp[i].max1 = dp[i].min1 = x;
        dp[i].max2 = -inf;
        dp[i].min2 = inf;
    }
    for (int i = 0; i < n; i++)
        for (int k = 0; k < (1 << n); k++)
            if (k & (1 << i))
                dp[k] = dp[k] + dp[k ^ (1 << i)];
    int ans = -inf;
    for (int i = 1; i < (1 << n); i++)
    {
        if (dp[i].max1 != -inf && dp[i].max2 != -inf)
            ans = max(ans,dp[i].max1 * dp[i].max2);
        if (dp[i].min1 != inf && dp[i].max2 != inf)
            ans = max(ans,dp[i].min1 * dp[i].min2);
        printf("%lld\n",ans);
    }
    return 0;
}
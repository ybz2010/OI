#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = (1 << 12) + 5;
int h,w;
int dp[15][maxn];
bool st[maxn];
basic_string<int>a[maxn];
bool check(int x)
{
    int len = 0;
    for (int i = 0; i < w; i++)
    {
        if (x & (1 << i))
        {
            if (len & 1)
                return 0;
            len = 0;
        }
        else
            len ++;
    }
    return !(len & 1);
}
void solve()
{
    for (int i = 0; i < (1 << w); i++)
        st[i] = check(i);
    for (int i = 0; i < (1 << w); i++)
    {
        a[i].clear();
        for (int j = 0; j < (1 << w); j++)
            if (!(i & j) && st[i | j])
                a[i].push_back(j);
    }
    memset(dp,0,sizeof dp);
    dp[0][0] = 1;
    for (int i = 1; i <= h; i++)
        for (int j = 0; j < (1 << w); j++)
            for (auto k : a[j])
                dp[i][j] += dp[i - 1][k];
    printf("%lld\n",dp[h][0]);
}
signed main()
{
    scanf("%lld%lld",&h,&w);
    while (h && w)
    {
        solve();
        scanf("%lld%lld",&h,&w);
    }
    return 0;
}
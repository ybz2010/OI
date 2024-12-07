#include<bits/extc++.h>
#define int long long
#ifdef LINUX
#define __popcount(x) __builtin_popcount(x)
#endif
using namespace std;
int n,K;
int dp[10][105][105];
int a[105];
bool check(int x,int y){return (!(x & y) && !((x << 1) & y) && !((y << 1) & x));}
signed main()
{
    scanf("%lld%lld",&n,&K);
    int cnt = 0;
    for (int i = 0; i < (1 << n); i++)
    {
        if ((i & (i << 1)) || (i & (i >> 1)))
            continue;
        cnt ++;
        a[cnt] = i;
        if(__popcount(i) <= K)
            dp[1][__popcount(i)][cnt] = 1;
    }
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= cnt; j++)
            for (int k = 1; k <= cnt; k++)
                for (int u = 0; u + __popcount(a[j]) <= K; u++)
                    if (check(a[j],a[k]) && __popcount(a[j]) + __popcount(a[k]) <= K)
                        dp[i][__popcount(a[j]) + u][j] += dp[i - 1][u][k];
    int ans = 0;
    for (int i = 1; i <= cnt; i++)
            ans += dp[n][K][i];
    printf("%lld",ans);
    return 0;
}
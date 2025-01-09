#include<bits/extc++.h>
using namespace std;
int n,m,ans;
int mp[105],dp[105][65][65];
pair<int,int>a[105];
signed main()
{
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char ch;
            cin >> ch;
            mp[i] = (mp[i] << 1) + (ch == 'P');
        }
    }
    if (n == 1) 
    {
		for (int i = 1; i <= m; i += 3) 
            ans ++;
		printf("%d\n",ans);
		return 0;
	}
    int cnt = 0;
    for (int i = 0; i < (1 << m); i++)
    {
        if ((i & (i << 1)) || (i & (i << 2)) || (i & (i >> 1)) || (i & (i >> 2)))
            continue;
        cnt ++;
        a[cnt].first = i;
        a[cnt].second = __builtin_popcount(i);
        if ((mp[1] & i) == i)
            dp[1][0][cnt] = a[cnt].second;
    }
    for (int i = 1; i <= cnt; i++)
        for (int j = 1; j <= cnt; j++)
            if (!(a[i].first & a[j].first) && (mp[2] & a[j].first) == a[j].first)
                dp[2][i][j] = dp[1][0][i] + a[j].second;
    for (int i = 3; i <= n; i++)
        for (int j = 1; j <= cnt; j++)
            if ((mp[i] & a[j].first) == a[j].first)
                for (int k = 1; k <= cnt; k++)
                    if (!(a[k].first & a[j].first))
                        for (int l = 1; l <= cnt; l++)
                            if (!(a[k].first & a[l].first) && !(a[j].first & a[l].first))
                                dp[i][k][j] = max(dp[i][k][j],dp[i - 1][l][k] + a[j].second);
    for (int i = 1; i <= cnt; i++)
        for (int j = 1; j <= cnt; j++)
            if (!(a[i].first & a[j].first))
                ans = max(ans,dp[n][i][j]);
    printf("%d",ans);
    return 0;
}
#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n,q;
int a[maxn];
int pre[maxn],id[maxn];
int ipr[maxn],pr[maxn],idx;
int dp[maxn][25];
void prime()
{
    for (int i = 2; i <= 1e5; i++)
    {
        if (!ipr[i])
        {
            pr[++idx] = i;
            id[i] = idx;
        }
        for (int j = 1; j <= idx && i * pr[j] <= n; j++)
        {
            ipr[i * pr[j]] = 1;
            if (i % pr[j] == 0)
                break;
        }
    }
}
void init()
{
    for (int i = 0; i < 25; i++)
        dp[n + 1][i] = n + 1;
    for (int i = 1; i <= idx; i++)
        pre[i] = n + 1;
    for (int i = n; i >= 1; i--)
    {
        int tmp = a[i],nxt = n + 1;
        for (int j = 2; j * j <= tmp; j++)
        {
            if (tmp % j)
                continue;
            nxt = min(nxt,pre[id[j]]);
            while (tmp % j == 0)
                tmp /= j;
            pre[id[j]] = i;
        }
        if (tmp != 1)
        {
            nxt = min(nxt,pre[id[tmp]]);
            pre[id[tmp]] = i;
        }
        dp[i][0] = min(dp[i + 1][0],nxt);
    }
    for (int j = 1; j < 25; j++)
        for (int i = 1; i <= n; i++)
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
}
int que(int l, int r)
{
	int ret = 1;
	for (int i = 24; i >= 0; i--)
	{   
        if (dp[l][i] && dp[l][i] <= r)
		{
			ret += (1 << i);
			l = dp[l][i];
		}
    }
	return ret;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    prime();
    init();
    for (int i = 1; i <= q; i++)
    {
        int l,r,cnt = 1;
        cin >> l >> r;
        for (int j = 24; j >= 0; j--)
        {
            if (dp[l][j] && dp[l][j] <= r)
            {
                cnt += (1 << j);
                l = dp[l][j];
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
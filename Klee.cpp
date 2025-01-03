#include <bits/extc++.h>
#define int long long
using namespace std;
const int mod = 12345678;
const int dir[10][2] = {{0,0},{1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};
bool vis[10][10],mp[10][10];
int n,m,ans;
int dp[30][(1 << 8) + 5],node[30][2],cnt[(1 << 8) + 5];
char ch[10];
bool check(int x,int y)
{
    if (x > 0 && x <= n && y > 0 && y <= m)
        return 1;
    return 0;
}
int f()
{
    int tot = 0;
    memset(dp,0,sizeof(dp));
    memset(vis,0,sizeof(vis));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mp[i][j])
            {
                node[tot][0] = i;
                node[tot++][1] = j;
            }
        }
    }
    for (int k = 0; k <= (1 << tot) - 1; k++)
    {
        int tmp = 0;
        memset(vis,0,sizeof(vis));
        for (int i = 0; i < tot; i++)
        {
            if (!((1 << (i)) & k))
            {
                if (!vis[node[i][0]][node[i][1]])
                {
                    vis[node[i][0]][node[i][1]] = 1;
                    tmp++;
                }
                for (int t = 1; t <= 8; t++)
                {
                    int x = node[i][0] + dir[t][0];
                    int y = node[i][1] + dir[t][1];
                    if (check(x,y) && !vis[x][y])
                    {
                        vis[x][y] = 1;
                        tmp++;
                    }
                }
            }
        }
        cnt[k] = n * m - tmp;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n * m; i++)
    {
        for (int k = 0; k <= (1 << tot) - 1; k++)
        {
            dp[i][k] += dp[i - 1][k] * max(cnt[k] - i + 1,0ll) % mod;
            dp[i][k] %= mod;
            for (int j = 0; j < tot; j++)
            {
                if (!((1 << (j)) & k))
                {
                    dp[i][k | (1 << (j))] += dp[i - 1][k];
                    dp[i][k | (1 << (j))] %= mod;
                }
            }
        }
    }
    return dp[n * m][(1 << tot) - 1];
}
void dfs(int x,int y,bool flg)
{
    if (x > n)
    {
        ans = ((ans + (flg ? -1 : 1) * f() % mod) % mod + mod) % mod;
        return;
    }
    if (y > m)
    {
        dfs(x + 1,1,flg);
        return;
    }
    dfs(x,y + 1,flg);
    if (!mp[x][y])
    {
        bool fl = 0;
        for (int i = 0; i < 8 && !fl; i++)
        {
            int tx = x + dir[i][0];
            int ty = y + dir[i][1];
            if (mp[tx][ty])
                fl = 1;
        }
        if (!fl)
        {
            mp[x][y] = 1;
            dfs(x,y + 1,!flg);
            mp[x][y] = 0;
            return;
        }
    }
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s",ch);
        for (int j = 0; j < m; j++)
        {
            if (ch[j] == '.')
                mp[i][j + 1] = 0;
            else
                mp[i][j + 1] = 1;
        }
    }
    dfs(1,1,0);
    printf("%lld\n",(ans % mod + mod) % mod);
    return 0;
}
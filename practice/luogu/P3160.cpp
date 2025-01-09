#include<bits/extc++.h>
#define int long long
#define pii pair<int,int>
#define mkp make_pair
#define check(x,y) (x >= 1 && x <= n && y >= 1 && y <= m)
using namespace std;
const int mod = 12345678;
const int dir[8][2] = 
{
    1,0,-1,0,0,1,0,-1,
    1,1,1,-1,-1,1,-1,-1
};
int n,m,tot,ans;
char ch;
bool vis[30][30],mp[30][30];
int dp[30][(1 << 8) + 5],cnt[(1 << 8) + 5];
vector<pii>node;
int f()
{
    node.clear();
    memset(dp,0,sizeof dp);
    memset(vis,0,sizeof vis);
    memset(cnt,0,sizeof cnt);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (mp[i][j])
                node.push_back(mkp(i,j));
    tot = node.size();
    for (int k = 0; k < (1 << tot); k++)
    {
        int tmp = 0;
        memset(vis,0,sizeof vis);
        for (int i = 0; i < tot; i++)
        {
            if (k & (1 << i))
                continue;
            int x = node[i].first;
            int y = node[i].second;
            if (!vis[x][y])
            {
                vis[x][y] = 1;
                tmp++;
            }
            for (int j = 0; j < 8; j++)
            {
                int tx = x + dir[j][0];
                int ty = y + dir[j][1];
                if (check(tx,ty) && !vis[tx][ty])
                {
                    vis[tx][ty] = 1;
                    tmp++;
                }
            }
        }
        cnt[k] = n * m - tmp;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n * m; i++)
    {
        for (int k = 0; k < (1 << tot); k++)
        {
            dp[i][k] = (dp[i][k] + max(cnt[k] - i + 1,0ll) * dp[i - 1][k] % mod) % mod;
            for (int j = 0; j < tot; j++)
                if (!(k & (1 << j)))
                    dp[i][k | (1 << j)] = (dp[i][k | (1 << j)] + dp[i - 1][k]) % mod;
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
        for (int j = 1; j <= m; j++)
        {
            cin >> ch;
            mp[i][j] = (ch == 'X');
        }
    }
    dfs(1,1,0);
    printf("%lld",ans);
    return 0;
}
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#define int long long
#define mode 12345678
using namespace std;
bool vis[10][10];
bool mp[10][10];
int n, m;
int dp[30][(1 << 8) + 5];
char ch[10];
int dir[10][2] = {{0, 0}, {1, 1}, {1, 0}, {1, -1}, {0, 1}, {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};
int node[30][2];
int num[(1 << 8) + 5];
int ans = 0;
bool check(int x, int y)
{
    if (x > 0 && x <= n && y > 0 && y <= m)
        return 1;
    return 0;
}
int get_dp()
{
    int tot = 0;
    memset(dp, 0, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (mp[i][j])
            {
                vis[i][j] = 1;
                node[++tot][0] = i;
                node[tot][1] = j;
            }
        }
    }
    for (int k = 0; k <= (1 << tot) - 1; k++)
    {
        int tmp = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= tot; i++)
        {
            if (!((1 << (i - 1)) & k))
            {
                if (!vis[node[i][0]][node[i][1]])
                {
                    vis[node[i][0]][node[i][1]] = 1;
                    tmp++;
                }
                for (int j = 1; j <= 8; j++)
                {
                    int x = node[i][0] + dir[j][0];
                    int y = node[i][1] + dir[j][1];
                    if (check(x, y) && !vis[x][y])
                    {
                        vis[x][y] = 1;
                        tmp++;
                    }
                }
            }
        }
        num[k] = n * m - tmp;
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n * m; i++)
    {
        for (int k = 0; k <= (1 << tot) - 1; k++)
        {
            dp[i][k] += dp[i - 1][k] * max(num[k] - i + 1, 0ll) % mode;
            dp[i][k] %= mode;
            for (int j = 1; j <= tot; j++)
            {
                if (!((1 << (j - 1)) & k))
                {
                    dp[i][k | (1 << (j - 1))] += dp[i - 1][k];
                    dp[i][k | (1 << (j - 1))] %= mode;
                }
            }
        }
    }
    return dp[n * m][(1 << tot) - 1];
}
void dfs(int x, int y, int typ)
{
    if (x == n + 1)
    {
        if (typ % 2)
        {
            ans -= get_dp();
            ans %= mode;
        }
        else
        {
            ans += get_dp();
            ans %= mode;
        }
        return;
    }
    if (y == m + 1)
    {
        dfs(x + 1, 1, typ);
        return;
    }
    dfs(x, y + 1, typ);
    if (!mp[x][y])
    {
        bool flag = 0;
        for (int i = 1; i <= 8; i++)
        {
            int st = x + dir[i][0];
            int ed = y + dir[i][1];
            if (mp[st][ed])
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            mp[x][y] = 1;
            dfs(x, y + 1, typ + 1);
            mp[x][y] = 0;
            return;
        }
    }
}
signed main()
{
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", ch);
        for (int j = 0; j < m; j++)
        {
            if (ch[j] == '.')
                mp[i][j + 1] = 0;
            else
                mp[i][j + 1] = 1;
        }
    }
    dfs(1, 1, 0);
    printf("%lld\n", (ans % mode + mode) % mode);
    return 0;
}
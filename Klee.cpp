#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
inline int read()
{
    int res = 0;
    bool bo = 0;
    char c;
    while (((c = getchar()) < '0' || c > '9') && c != '-')
        ;
    if (c == '-')
        bo = 1;
    else
        res = c - 48;
    while ((c = getchar()) >= '0' && c <= '9')
        res = (res << 3) + (res << 1) + (c - 48);
    return bo ? ~res + 1 : res;
}
typedef long long ll;
const int N = 20, M = 40;
int n, m, ecnt, nxt[M], adj[N], go[M], tot, a[N];
bool g[N][N], vis[N];
ll dp[N][N], ans;
inline void add_edge(const int &u, const int &v)
{
    nxt[++ecnt] = adj[u];
    adj[u] = ecnt;
    go[ecnt] = v;
    nxt[++ecnt] = adj[v];
    adj[v] = ecnt;
    go[ecnt] = u;
}
inline void dfs(const int &u, const int &fu)
{
    int i, j;
    for (int e = adj[u], v; e; e = nxt[e])
    {
        if ((v = go[e]) == fu)
            continue;
        dfs(v, u);
    }
    for (i = 1; i <= tot; i++)
    {
        int x = a[i];
        dp[u][x] = 1;
        for (int e = adj[u], v; e; e = nxt[e])
        {
            if ((v = go[e]) == fu)
                continue;
            ll sum = 0;
            for (j = 1; j <= tot; j++)
            {
                int y = a[j];
                if (!g[x][y])
                    continue;
                sum += dp[v][y];
            }
            dp[u][x] *= sum;
        }
    }
}
inline void solve()
{
    int i;
    tot = 0;
    for (i = 1; i <= n; i++)
        if (vis[i])
            a[++tot] = i;
    dfs(1, 0);
    for (i = 1; i <= tot; i++)
        if (n - tot & 1)
            ans -= dp[1][a[i]];
        else
            ans += dp[1][a[i]];
}
inline void Dfs(const int &dep)
{
    if (dep == n + 1)
        return solve();
    vis[dep] = 0;
    Dfs(dep + 1);
    vis[dep] = 1;
    Dfs(dep + 1);
}
int main()
{
    int i, x, y;
    n = read();
    m = read();
    for (i = 1; i <= m; i++)
        x = read(), y = read(), g[x][y] = g[y][x] = 1;
    for (i = 1; i < n; i++)
        x = read(), y = read(), add_edge(x, y);
    Dfs(1);
    cout << ans << endl;
    return 0;
}

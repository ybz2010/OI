#include <bits/stdc++.h>
using namespace std;

int n, m, a[1010][1010], b[1010][1010], vis[4010], instk[1010], flag;
int head[4010], nxt[4010], to[4010], cnte;
void addedge(int u, int v) { to[++cnte] = v, nxt[cnte] = head[u], head[u] = cnte; }

void dfs(int u)
{
    if (instk[u])
    {
        flag = 1;
        return;
    }
    if (vis[u])
        return;
    instk[u] = vis[u] = 1;
    for (int i = head[u]; i; i = nxt[i])
        dfs(to[i]);
    instk[u] = 0;
}

void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &b[i][j]);
    for (int k = 0; k < 30; k++)
    {
        cnte = flag = 0;
        for (int i = 0; i <= n + m + 10; i++)
            head[i] = vis[i] = instk[i] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (((b[i][j] >> k) & 1) == 1)
                    addedge(i, n + j);
        for (int j = 1; j <= m; j++)
            for (int i = 1; i <= n; i++)
                if (((b[i][j] >> k) & 1) == 0)
                    addedge(n + j, i);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (((a[i][j] >> k) & 1) != ((b[i][j] >> k) & 1))
                {
                    addedge(0, ((a[i][j] >> k) & 1) ? i : n + j);
                }
        dfs(0);
        if (flag)
        {
            puts("No");
            return;
        }
    }
    puts("Yes");
}

signed main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}
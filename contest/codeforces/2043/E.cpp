#include<bits/extc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int n,m;
int a[maxn][maxn],b[maxn][maxn];
int head[maxn << 1],idx;
int vis[maxn << 1],instk[maxn];
bool fl;
struct edge
{
    int v,nxt;
    edge(int v = 0,int nxt = 0):v(v),nxt(nxt){};
}e[maxn << 1];
void adde(int u,int v)
{
    e[++idx] = edge(v,head[u]);
    head[u] = idx;
}
void dfs(int u)
{
    vis[u] = 1;
    instk[u] = 1;
    if (fl)
        return;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (!vis[v])
            dfs(v);
        else if (instk[v])
        {
            fl = 1;
            return;
        }
    }
    instk[u] = 0;
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> b[i][j];
    for (int k = 0; k < 30; k++)
    {
        fill(head,head + n + m + 1,0);
        fill(vis,vis + n + m + 1,0);
        fill(instk,instk + n + m + 1,0);
        idx = fl = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if ((1 << k) & b[i][j])
                    adde(i,n + j);
        for (int j = 1; j <= m; j++)
            for (int i = 1; i <= n; i++)
                if (!((1 << k) & b[i][j]))
                    adde(n + j,i);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (((1 << k) & a[i][j]) != ((1 << k) & b[i][j]))
                    adde(0,((1 << k) & a[i][j]) ? i : n + j);
        dfs(0);
        if (fl)
        {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int read()
{
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
    return s * w;
}
const int maxn = 3010;
vector<int> g2[maxn], g1[maxn], g3[maxn];//g是反图，z是正图，G是树
char vis[maxn];
int st[maxn], ans[400010], n, m, q;
void add(int x, int y) { g2[y].push_back(x), g1[x].push_back(y); }
void ADD(int x, int y) { g3[x].push_back(y); }
void dfs1(int u)
{
    vis[u] = 1;
    for (auto v : g2[u])
        if (!vis[v])
            dfs1(v);
}
struct query{int u,v,k,id;};
vector<query> q1[maxn], q2[maxn];
void dfs2(int u)
{
    st[++st[0]] = u;
    for (auto i : q2[u])
        if (st[0] >= i.k)
            ans[i.id] = st[st[0] - i.k + 1];
    for (auto v : g3[u])
        dfs2(v);
    st[0] --;
}
signed main()
{
    cin >> n >> m >> q;
    int u,v,k;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        g1[u].push_back(v);
        g2[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        sort(g1[i].begin(),g1[i].end());
    for (int i = 1; i <= q; i++)
    {
        cin >> u >> v >> k;
        q1[v].push_back((query){u,v,k,i});
    }
    memset(ans,0xff,sizeof ans);
    for (int ed = 1; ed <= n; ed++)
    {
        for (int j = 1; j <= n; j++)
        {
            vis[j] = 0;
            q2[j].clear();
            g3[j].clear();
        }
        dfs1(ed);
        for (int i = 1; i <= n; i++)
            if (vis[i] && i != ed)
                for (auto v : g1[i])
                    if (vis[v])
                    {
                        ADD(v, i);
                        break;
                    }
        for (auto y : q1[ed])
            q2[y.u].push_back(y);
        dfs2(ed);
    }
    for (int i = 1; i <= q; i++)
        cout << ans[i] << '\n';
    return 0;
}
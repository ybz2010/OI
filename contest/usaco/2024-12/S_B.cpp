#include <bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
using namespace __gnu_pbds;
const int maxn = 500005;
struct edge
{
    int v, w, nxt;
} e[maxn];
int n, m, a[maxn];
int u[maxn], v[maxn], w[maxn];
int head[maxn], idx;
bool vis[maxn];
int dis[maxn];
void init()
{
    for (int i = 1; i <= 1e5; i++)
        e[i].v = e[i].w = e[i].nxt = 0;
    idx = 0;
    memset(head, 0, sizeof head);
}
void adde(int u, int v, int w)
{
    idx++;
    e[idx].v = v;
    e[idx].w = w;
    e[idx].nxt = head[u];
    head[u] = idx;
}
void spfa(int st)
{
    memset(dis, -0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    queue<int> q;
    dis[st] = 0;
    vis[st] = 1;
    q.push(st);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].v, w = e[i].w;
            if (dis[v] < dis[u] + w)
            {
                dis[v] = dis[u] + w;
                if (!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}
void solve()
{
    init();
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", a + i);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld%lld%lld", &u[i], &v[i], &w[i]);
        u[i] = lower_bound(a + 1, a + n + 1, u[i]) - a - 1;
        v[i] = upper_bound(a + 1, a + n + 1, v[i]) - a - 1;
        adde(u[i], v[i], w[i]);
    }
    for (int i = 0; i < n; i++)
    {
        adde(i, i + 1, 0);
        adde(i + 1, i, -1);
    }
    spfa(0);
    cout << n - dis[n] << "\n";
}
signed main()
{
    int t;
    scanf("%lld", &t);
    while (t--)
    {
        solve();
    }
    return 0;
}
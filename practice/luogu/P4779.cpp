#include<bits/extc++.h>
#define pii pair<int,int>
using namespace std;
const int maxn = 1e5 + 5;
int n,m,st;
int dis[maxn];
bool vis[maxn];
struct edge
{
    int v,w;
    edge *nxt;
}*head[maxn];
void adde(int u,int v,int w)
{
    auto tmp = new edge;
    tmp->v = v;
    tmp->w = w;
    tmp->nxt = head[u];
    head[u] = tmp;
}
void dij(int st)
{
    memset(dis,0x7f,sizeof dis);
    memset(vis,0,sizeof vis);
    priority_queue<pii,vector<pii>,greater<pii> >q;
    dis[st] = 0;
    q.push({0,st});
    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto i = head[u]; i; i = i->nxt)
        {
            int v = i->v,w = i->w;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                q.push({dis[v],v});
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> st;
    int u,v,w;
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v >> w;
        adde(u,v,w);
    }
    dij(st);
    for (int i = 1; i <= n; i++)
        cout << dis[i] << ' ';
    return 0;
}
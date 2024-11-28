#include<bits/extc++.h>
#define pii pair<int,int>
#define int long long
using namespace std;
const int maxn = 3e5 + 5;
int n,m,s;
int u[maxn],v[maxn],w[maxn];
int head[maxn],idx = 1;
int dis[maxn],pre[maxn];
int vis[maxn];
struct edge
{
    int v,w,nxt;
    edge(int v = 0,int w = 0,int nxt = 0):v(v),w(w),nxt(nxt){};
}e[maxn << 1];
void adde(int u,int v,int w)
{
    e[++idx] = edge(v,w,head[u]);
    head[u] = idx;
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
        for (int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].v,w = e[i].w;
            if (dis[v] >= dis[u] + w)
            {
                dis[v] = dis[u] + w;
                pre[v] = i;
                q.push({dis[v],v});
            }
        }
    }
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld%lld%lld",u + i,v + i,w + i);
        adde(u[i],v[i],w[i]);
        adde(v[i],u[i],w[i]);
    }
    scanf("%lld",&s);
    dij(s);
    vector<int>ans;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == s)
            continue;
        int id = pre[i];
        sum += e[id].w;
        ans.push_back(id >> 1);
    }
    printf("%lld\n",sum);
    for (auto i : ans)
        printf("%lld ",i);
    return 0;
}
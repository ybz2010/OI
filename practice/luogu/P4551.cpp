#include<bits/extc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n;
int head[maxn],idx = 1;
int dis[maxn],tr[maxn << 4][2],id = 1;
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
void dfs(int u,int fa)
{
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v,w = e[i].w;
        if (v == fa)
            continue;
        dis[v] = (dis[u] ^ w);
        dfs(v,u);
    }
}
void insert(int x)
{
    int p = 1;
    for (int i = 31; i >= 0; i--)
    {
        int ch = ((x >> i) & 1);
        if (!tr[p][ch])
            tr[p][ch] = ++id;
        p = tr[p][ch];
    }
}
int find(int x)
{
    int p = 1,ret = 0;
    for (int i = 31; i >= 0; i--)
    {
        int ch = ((x >> i) & 1);
        if (tr[p][ch ^ 1])
        {
            ret += (1 << i);
            p = tr[p][ch ^ 1];
        }
        else
            p = tr[p][ch];
    }
    return ret;
}
signed main()
{
    scanf("%d",&n);
    for (int i = 1; i < n; i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        adde(u,v,w);
        adde(v,u,w);
    }
    dis[1] = 0;
    dfs(1,0);
    for (int i = 1; i <= n; i++)
        insert(dis[i]);
    int ans = 0;
    for (int i = 1; i <= n; i++)    
        ans = max(ans,find(dis[i]));
    cout << ans;
    return 0;
}
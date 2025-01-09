#include<bits/extc++.h>
#define int long long
using namespace std;
int n,m;
int head[155],idx = 1;
int dfn[155],low[155],tim;
bool gebi[10005];
set<pair<int,int> >ans;
struct edge
{
    int u,v,nxt;
    edge(int u = 0,int v = 0,int nxt = 0):u(u),v(v),nxt(nxt){};
}e[10005];
void adde(int u,int v)
{
    e[++idx] = edge(u,v,head[u]);
    head[u] = idx;
}
void tarjan(int u,int pre)
{
    dfn[u] = low[u] = ++tim;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        if ((i ^ 1) == pre)
            continue;
        int v = e[i].v;
        if (!dfn[v])
        {
            tarjan(v,i);
            low[u] = min(low[u],low[v]);
            if (dfn[u] < low[v])
                gebi[i] = gebi[i ^ 1] = 1;
        }
        else
            low[u] = min(low[u],dfn[v]);
    }
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    for (int i = 1; i <= m; i++)
    {
        int u,v;
        scanf("%lld%lld",&u,&v);
        adde(u,v);
        adde(v,u);
    }
    tarjan(1,-114514);
    for (int i = 2; i <= idx; i++)
    {
        if (gebi[i])
        {
            int u = e[i].u,v = e[i].v;
            if (u > v)
                swap(u,v);
            ans.insert({u,v});
        }
    }
    for (auto i : ans)
        printf("%lld %lld\n",i.first,i.second);
    return 0;
}
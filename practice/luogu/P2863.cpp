#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e4 + 5;
const int maxm = 5e5 + 5;
int n,m;
int u[maxm],v[maxm];
int head[maxn],idx = 1;
int dfn[maxn],low[maxn],tim;
int sc,siz[maxn],out[maxn];
bool vis[maxn];
stack<int>st;
struct edge
{
    int v,nxt;
    edge(int v = 0,int nxt = 0):v(v),nxt(nxt){};
}e[maxm * 2];
void adde(int u,int v)
{
    e[++idx] = edge(v,head[u]);
    head[u] = idx;
}
void tarjan(int u)
{
    dfn[u] = low[u] = ++tim;
    vis[u] = 1;
    st.push(u);
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else if (vis[v])
            low[u] = min(low[u],dfn[v]);
    }
    if (low[u] == dfn[u])
    {
        sc ++;
        while (st.top() != u)
        {
            siz[sc] ++;
            vis[st.top()] = 0;
            st.pop();
        }
        siz[sc] ++;
        vis[u] = 0;
        st.pop();
    }
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld%lld",u + i,v + i);
        if (u[i] == v[i])
            continue;
        adde(u[i],v[i]);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    int ans = 0;
    for (int i = 1; i <= sc; i++)
        if (siz[i] > 1)
            ans ++;
    cout << ans;
    return 0;
}
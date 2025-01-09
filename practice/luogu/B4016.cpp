#include<bits/extc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n;
int head[maxn],idx = 1;
int dp[maxn],_max;
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
void dfs(int u,int fa)
{
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == fa)
            continue;
        dfs(v,u);
        _max = max(_max,dp[u] + dp[v] + 1);
        dp[u] = max(dp[u],dp[v] + 1);
    }
}
signed main()
{
    scanf("%d",&n);
    for (int i = 1; i < n; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        adde(u,v);
        adde(v,u);
    }
    dfs(1,-1);
    cout << _max;
    return 0;
}
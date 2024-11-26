#include<bits/extc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n,m;
bool vis[maxn];
int dp[maxn],_max;
int head[maxn],idx = 1;
struct edge{
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
    vis[u] = dp[u] = 1;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (vis[v])
            continue;
        dfs(v);
        _max = max(_max,dp[u] + dp[v]);
        dp[u] = max(dp[u],dp[v] + 1);
    }
}
signed main()
{
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        adde(a,b);
        adde(b,a);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            _max = 1;
            dfs(i);
            ans += _max;
        }
    }
    cout << ans;
    return 0;
}
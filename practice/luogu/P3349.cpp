#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 300;
int n,m;
bool g[20][20];
int a[20],idx,dp[20][20];
namespace graph
{
    int head[20],idx;
    struct edge
    {
        int v,nxt;
        edge(int v = 0,int nxt = 0):v(v),nxt(nxt){};
    }e[maxn];
    void adde(int u,int v)
    {
        e[++idx] = edge(v,head[u]);
        head[u] = idx;
    }
}
void dfs(int u,int fa)
{
    for (int i = graph::head[u]; i; i = graph::e[i].nxt)
    {
        int v = graph::e[i].v;
        if (v == fa)
            continue;
        dfs(v,u);
    }
    for (int i = 1; i <= idx; i++)
    {
        dp[u][a[i]] = 1;
        for (int k = graph::head[u]; k; k = graph::e[k].nxt)
        {
            int v = graph::e[k].v;
            if (v != fa)
            {
                int sum = 0;
                for (int j = 1; j <= idx; j++)
                    if (g[a[i]][a[j]])
                        sum += dp[v][a[j]];
                dp[u][a[i]] *= sum;
            }
        }
    }
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    int u,v;
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld%lld",&u,&v);
        g[u][v] = g[v][u] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        scanf("%lld%lld",&u,&v);
        graph::adde(u,v);
        graph::adde(v,u);
    }
    int ans = 0;
    for (int k = 0; k < (1 << n); k++)
    {
        idx = 0;
        for (int i = 1; i <= n; i++)
            if (k & (1 << (i - 1)))
                a[++idx] = i;
        dfs(1,-114514);
        for (int i = 1; i <= idx; i++)
            ans += ((n - idx) & 1 ? -1 : 1) * dp[1][a[i]];
    }
    printf("%lld",ans);
    return 0;
}
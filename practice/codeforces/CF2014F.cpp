#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
int n,c;
int a[maxn];
int head[maxn],idx;
int dp[maxn][2];
struct edge
{
    int v,nxt;
    edge(int v = 0,int nxt = 0):v(v),nxt(nxt){};
}e[maxn << 1];
void init()
{
    idx = 1;
    for (int i = 1; i <= n; i++)
    {
        head[i] = 0;
        dp[i][0] = dp[i][1] = 0;
    }
}
void adde(int u,int v)
{
    e[++idx] = edge(v,head[u]);
    head[u] = idx;
}
void dfs(int u,int fa)
{
    dp[u][0] = 0;
    dp[u][1] = a[u];
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == fa)
            continue;
        dfs(v,u);
        dp[u][0] += max(dp[v][0],dp[v][1]);
        dp[u][1] += max(dp[v][0],dp[v][1] - 2 * c);
    }
}
void solve()
{
    init();
    scanf("%lld%lld",&n,&c);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    idx = 1;
    for (int i = 1; i < n; i++)
    {
        int u,v;
        scanf("%lld%lld",&u,&v);
        adde(u,v);
        adde(v,u);
    }
    dfs(1,-114514);
    printf("%lld\n",max(dp[1][0],dp[1][1]));
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}
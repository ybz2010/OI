#include<bits/extc++.h>
#define inv(x) binpow(x,mod - 2)
#define inf 0x7f7f7f7f7f7f
#define int long long
using namespace std;
const int mod = 998244353;
const int maxn = 2e5 + 5;
int n;  
int head[maxn],idx = 1;
int dep[maxn],son[maxn];
int k[maxn],dp[maxn];
struct edge
{
    int v,nxt;
    edge(int v = 0,int nxt = 0):v(v),nxt(nxt){};
}e[maxn << 1];
void adde(int u,int v)
{
    e[++ idx] = edge(v,head[u]);
    head[u] = idx;
}
int binpow(int x,int y)
{
    int ret = 1;
    while (y)
    {
        if (y & 1)
            ret = ret * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ret;
}
void init()
{
    for (int i = 2; i <= idx; i++)
        e[i] = edge();
    fill(head + 1,head + n + 1,0),idx = 1;
    fill(dep + 1,dep + n + 1,0);
    fill(son + 1,son + n + 1,0);
    fill(dp + 1, dp + n + 1,0);
}
void dfs1(int u,int fa)
{
    dep[u] = inf;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == fa)
            continue;
        dfs1(v,u);
        dep[u] = min(dep[u],dep[v] + 1);
    }
    if (dep[u] == inf)
        dep[u] = 0;
}
void dfs3(int u,int fa)
{
    if (u == 1)
        dp[u] = 1;
    else
        dp[u] = dp[fa] * k[dep[u]] % mod;
    for (int i = head[u]; i; i = e[i].nxt)
        if (e[i].v != fa)
            dfs3(e[i].v,u);
}
void solve()
{
    init();
    scanf("%lld",&n);
    int x,y;
    for (int i = 1; i < n; i ++)
    {
        scanf("%lld%lld",&x,&y);
        adde(x,y);
        adde(y,x);
    }
    dfs1(1,0);
    dfs3(1,0);
    for (int i = 1; i <= n; i++)
        printf("%lld ",dp[i]);
    putchar('\n');
}
signed main()
{
    k[0] = 0;
    for (int i = 1; i <= 2e5; i++)
        k[i] = inv((2 - k[i - 1] + mod) % mod);
    int t;
    scanf("%lld",&t);
    while (t --)
        solve();
    return 0;
}
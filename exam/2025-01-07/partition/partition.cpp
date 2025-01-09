#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 998244353;
const int blk = 600;
int n,m;
int head[maxn],idx;
int siz[maxn];
int dp[maxn][blk + 5];
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
void dfs1(int u,int fa)
{
    siz[u] = dp[u][1] = 1;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == fa)
            continue;
        dfs1(v,u);
        for (int j = min(m + 1,siz[u]); j; j--)
        {
            int tmp = dp[u][j];
            if (tmp)
            {
                dp[u][j] = 0;
                for (int k = 0; k <= siz[v] && j + k <= m + 1; k++)
                    dp[u][j + k] = (dp[u][j + k] + tmp * dp[v][k] % mod) % mod;
            }
        }
        siz[u] += siz[v];
    }
    dp[u][0] = (dp[u][m] + dp[u][m + 1]) % mod;
}
void dfs2(int u,int fa)
{
    siz[u] = dp[u][0] = 1;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == fa)
            continue;
        dfs2(v,u);
        for (int j = siz[u] / m; ~j; j--)
        {
            int tmp = dp[u][j];
            if (tmp)
            {
                dp[u][j] = 0;
                for (int k = 0; k * m <= siz[v]; k++)
                    if ((siz[u] - j * m - 1) % (m + 1) + (siz[v] - k * m) % (m + 1) + 1 <= m + 1)
                        dp[u][j + k] = (dp[u][j + k] + tmp * dp[v][k] % mod) % mod;
            }
        }
        siz[u] += siz[v];
    }
    for (int i = siz[u] / m; ~i; i--)
        if ((siz[u] - i * m) % (m + 1) == m)
            dp[u][i + 1] = (dp[u][i + 1] + dp[u][i]) % mod;
}
void solve()
{
    scanf("%lld%lld",&n,&m);
    idx = 0;
    fill(head + 1,head + n + 1,0);
    fill(e + 1,e + (n << 1) + 1,edge());
    for (int i = 1; i <= n; i++)
        fill(dp[i],dp[i] + blk + 1,0);
    for (int i = 1,u,v; i < n; i++)
    {
        scanf("%lld%lld",&u,&v);
        adde(u,v);
        adde(v,u);
    }
    if (m <= blk)
    {
        dfs1(1,0);
        printf("%lld\n",dp[1][0]);
    }
    else
    {
        dfs2(1,0);
        int ans = 0;
        for (int i = 0; i <= n / m; i++)
            if ((n - i * m) % (m + 1) == 0)
                ans = (ans + dp[1][i]) % mod;
        printf("%lld\n",ans);
    }
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}
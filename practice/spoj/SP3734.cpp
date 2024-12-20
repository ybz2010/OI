#include<bits/extc++.h>
#define int long long
#define Inv(x) binpow(x,mod - 2)
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
int n,k;
int h[505],fac[maxn],inv[maxn];
int ls[505],rs[505],siz[505];
int st[505],top,dp[505][505],g[505];
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= 1e6; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = inv[i - 1] * Inv(i) % mod;
    }
}
int a(int n,int m){return n < m ? 0 : fac[n] * inv[n - m] % mod;}
int calc(int n,int m,int k){return a(n,k) * a(m,k) % mod * inv[k] % mod;}
void dfs1(int u)
{
    siz[u] = 1;
    if (ls[u])
    {
        dfs1(ls[u]);
        siz[u] += siz[ls[u]];
    }
    if (rs[u])
    {
        dfs1(rs[u]);
        siz[u] += siz[rs[u]];
    }
}
void dfs2(int u,int hei)
{
    int hu = h[u] - hei;
    if (!ls[u] && !rs[u])
    {
        dp[u][0] = 1;
        for (int i = 1; i <= k; i++)
            dp[u][i] = calc(siz[u],hu,i);
    }
    else if (!ls[u] || !rs[u])
    {
        int v = ls[u] ? ls[u] : rs[u];
        dfs2(v,h[u]);
        memset(g,0,sizeof g);
        g[0] = 1;
        for (int i = 1; i <= k; i++)
            for (int j = 0; j <= i; j++)
                g[i] = (g[i] + dp[0][j] * dp[v][i - j] % mod) % mod;
        dp[u][0] = 1;
        for (int i = 1; i <= k; i++)
            for (int j = 0; j <= i; j++)
                dp[u][i] = (dp[u][i] + g[j] * calc(hu,siz[u] - j,i - j) % mod) % mod;
    }
    else
    {
        dfs2(ls[u],h[u]);
        dfs2(rs[u],h[u]);
        memset(g,0,sizeof g);
        g[0] = 1;
        for (int i = 1; i <= k; i++)
            for (int j = 0; j <= i; j++)
                g[i] = (g[i] + dp[ls[u]][j] * dp[rs[u]][i - j] % mod) % mod;
        dp[u][0] = 1;
        for (int i = 1; i <= k; i++)
            for (int j = 0; j <= i; j++)
                dp[u][i] = (dp[u][i] + g[j] * calc(hu,siz[u] - j,i - j) % mod) % mod;
    }
}
signed main()
{
    init();
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    st[++top] = 1;
    for (int i = 2; i <= n; i++)
    {
        while (top && h[st[top]] > h[i])
            top --;
        if (!top)
            ls[i] = st[top + 1];
        else
        {
            ls[i] = rs[st[top]];
            rs[st[top]] = i;
        }
        st[++top] = i;
    }
    dfs1(st[1]);
    dp[0][0] = 1;
    dfs2(st[1],0);
    cout << dp[st[1]][k];
    return 0;
}
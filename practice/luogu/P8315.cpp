#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 65;
const int mod = 1e9 + 7;
int n,m,k;
int head[maxn],idx;
int f[maxn][10],dep[maxn];
int fa[maxn],l[20];
int c[20],d[20];
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
void dfs(int u,int fa)//lca预处理
{
    f[u][0] = fa;
    dep[u] = dep[fa] + 1;
    for (int i = 1; i < 10; i++)
        f[u][i] = f[f[u][i - 1]][i - 1];
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == fa)
            continue;
        dfs(v,u);
    }
}
int lca(int u,int v)
{
    if (dep[u] < dep[v])
        swap(u,v);
    for (int i = 9; i >= 0; i--)
        if (dep[u] - (1 << i) >= dep[v])
            u = f[u][i];
    if (u == v)
        return u;
    for (int i = 9; i >= 0; i--)
        if (f[u][i] != f[v][i])
            u = f[u][i],v = f[v][i];
    return f[u][0];
}
void init()
{
    for (int i = 1; i <= n; i++)
        fa[i] = i;
}
int find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}
signed main()
{
    scanf("%lld%lld%lld",&n,&m,&k);
    for (int i = 1; i < n; i ++)
    {
        int u,v;
        scanf("%lld%lld",&u,&v);
        adde(u,v);
        adde(v,u);
    }
    dfs(1,0);
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld%lld",c + i,d + i);
        l[i] = lca(c[i],d[i]);
    }
    int ans = binpow(k,n - 1),g,sum;
    int a,b,s,t;
    for (int i = 1; i < (1 << m); i++)
    {
        g = 1,sum = 0;
        init();
        for (int j = 0; j < m; j++)
        {
            if (i >> j & 1)
            {
                g = -g;
                s = c[j + 1];
                while (s != l[j + 1])
                {
                    if (f[s][0] == l[j + 1])
                        break;
                    a = find(s),b = find(f[s][0]);
                    if (a != b)
                        fa[a] = b;
                    s = f[s][0]; 
                }
                t = d[j + 1];
                while (t != l[j + 1])
                {
                    if (f[t][0] == l[j + 1])
                        break;
                    a = find(t),b = find(f[t][0]);
                    if (a != b)
                        fa[a] = b;
                    t = f[t][0];
                }
                if (s != l[j + 1] && t != l[j + 1])
                {
                    a = find(s);
                    b = find(t);
                    if (a != b)
                        fa[a] = b;
                }
            }
        }
        for (int j = 2; j <= n; j++)
            if (fa[j] == j)
                sum ++;
        ans = (ans + g * binpow(k,sum) % mod + mod) % mod;
    }
    ans = (ans + mod) % mod;
    cout << ans;
    return 0;
}
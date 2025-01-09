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
void dfs1(int u,int fa)//lca预处理
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
        dfs1(v,u);
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
    dfs1(1,0);
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld%lld",c + i,d + i);
        l[i] = lca(c[i],d[i]);
    }
    int ans = binpow(k,n - 1),g,sum;
    int tmp1,tmp2,st,en;
    for (int i = 1; i < (1 << m); i++)
    {
        g = 1,sum = 0;
        init();
        for (int j = 0; j < m; j++)
        {
            if (i & (1 << j))
            {
                g = -g;
                st = c[j + 1];
                while (st != l[j + 1])
                {
                    if (f[st][0] == l[j + 1])
                        break;
                    tmp1 = find(st),tmp2 = find(f[st][0]);
                    if (tmp1 != tmp2)
                        fa[tmp1] = tmp2;
                    st = f[st][0]; 
                }
                en = d[j + 1];
                while (en != l[j + 1])
                {
                    if (f[en][0] == l[j + 1])
                        break;
                    tmp1 = find(en),tmp2 = find(f[en][0]);
                    if (tmp1 != tmp2)
                        fa[tmp1] = tmp2;
                    en = f[en][0];
                }
                if (st != l[j + 1] && en != l[j + 1])
                {
                    tmp1 = find(st);
                    tmp2 = find(en);
                    if (tmp1 != tmp2)
                        fa[tmp1] = tmp2;
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
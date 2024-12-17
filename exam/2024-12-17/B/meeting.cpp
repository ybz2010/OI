#include<bits/extc++.h>
#define int long long
#define Inv(x) binpow(x,mod - 2)
using namespace std;
const int maxn = 1e6 + 5;
const int mod = 1000000007;
int n,m;
int head[maxn],idx = 1;
int siz[maxn];
struct edge
{
    int v,nxt;
    edge(int v = 0,int nxt = 0):v(v),nxt(nxt){};
}e[maxn << 1];
struct modint
{
    int val;
    modint(int x = 0):val(x % mod){};
    int &operator()(){return (val %= mod);}
    friend modint operator+(modint x,modint y){return ((x() + y()) % mod);}
    friend modint operator+=(modint &x,modint y){return x() = ((x() + y()) % mod);}
    friend modint operator-(modint x,modint y){return ((x() - y()) % mod + mod) % mod;}
    friend modint operator-=(modint &x,modint y){return x() = ((x() - y()) % mod + mod) % mod;}
    friend modint operator*(modint x,modint y){return (x() * y() % mod);}
    friend modint operator*=(modint &x,modint y){return x() = (x() * y() % mod);}
}fac[maxn],inv[maxn],ans,dp1[maxn],dp2[maxn];
void adde(int u,int v)
{
    e[++idx] = edge(v,head[u]);
    head[u] = idx;
}
modint binpow(modint x,int y)
{
    modint ret = 1;
    while (y)
    {
        if (y & 1)
            ret *= x;
        x *= x;
        y >>= 1;
    }
    return ret;
}
void init()
{
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= 1e6; i++)
    {
        fac[i] = fac[i - 1] * i;
        inv[i] = inv[i - 1] * Inv(i);
    }
}
modint c(int n,int m){return fac[n] * inv[n - m] * inv[m];}
void dfs(int u,int fa)
{
    siz[u] = 1;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == fa)
            continue;
        dfs(v,u);
        siz[u] += siz[v];
        ans += dp2[siz[v]];
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();
    cin >> n >> m;
    int x;
    for (int i = 2; i <= n; i++)
    {
        cin >> x;
        adde(i,x),adde(x,i);
    }
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    int k = (m - 1) >> 1;
    if (k < 1)
        dp1[1] = 0;
    else
        dp1[1] = c(n - 1,m - 1);
    for (int i = 2; i < n; i++)
        dp1[i] = dp1[i - 1] - c(i - 2,k - 1) * c(n - i,m - 1 - k);
    for (int i = 1; i < n; i++)
    {
        dp2[i] = i * dp1[i] + dp1[n - i] * (n - i);
        if (!(m & 1))
            dp2[i] += c(i,m >> 1) * c(n - i,m >> 1) * (m >> 1);
    }
    dfs(1,0);
    cout << ans();
    return 0;
}
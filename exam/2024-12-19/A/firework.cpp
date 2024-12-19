#include<bits/extc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int maxn = 1005;
int n,m;
int l[maxn],r[maxn],t[maxn];
int dp[maxn][505];
struct edge
{
    int v,c;
    edge *nxt;
    edge(int v = 0,int c = 0,edge *nxt = 0):v(v),c(c),nxt(nxt){};
}*head[maxn];
void adde(int u,int v,int c)
{
    auto tmp = new edge;
    tmp->v = v;
    tmp->c = c;
    tmp->nxt = head[u];
    head[u] = tmp;
}
void dfs(int u,int fa)
{
    for (auto i = head[u]; i; i = i->nxt)
    {
        int v = i->v;
        if (v == fa)
            continue;
        dfs(v,u);
        int lu,ru,lv,rv,tmp;
        for (int tu = 0; l[u] + tu + t[u] - 1 <= r[u]; tu++)
        {
            lu = l[u] + tu,ru = l[u] + tu + t[u] - 1;
            tmp = inf;
            for (int tv = 0; l[v] + tv + t[v] - 1 <= r[v]; tv++)
            {
                lv = l[v] + tv,rv = l[v] + tv + t[v] - 1;
                tmp = min(tmp,dp[v][tv] + max(0ll,min(ru,rv) - max(lu,lv) + 1) * i->c);
            }
            dp[u][tu] += tmp;
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i] >> t[i];
    for (int i = 1; i <= m; i++)
    {
        int u,v,c;
        cin >> u >> v >> c;
        adde(u,v,c);
        adde(v,u,c);
    }
    dfs(1,-114514);
    int ans = inf;
    for (int i = 0; l[1] + i + t[1] - 1 <= r[1]; i++)
        ans = min(ans,dp[1][i]);
    cout << ans;
    return 0;
}
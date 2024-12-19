//话说宵宫能够同一时间做多个烟花吗？
//它能过我吃
#include<bits/extc++.h>
#define val (max(0,min(ur,vr) - max(ul,vl) + 1) * i->c)
using namespace std;
const int maxn = 1005;
int n,m;
int l[maxn],r[maxn],t[maxn];
int dp[maxn][2];
struct edge
{
    int v,c;
    edge *nxt;
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
    bool leaf = 1;
    for (auto i = head[u]; i; i = i->nxt)
    {
        int v = i->v;
        if (v == fa)
            continue;
        leaf = 0;
        dfs(v,u);
        int ul,ur,vl,vr;
        ul = l[u],ur = l[u] + t[u] - 1;
        vl = l[v],vr = l[v] + t[v] - 1;
        dp[u][0] = min(dp[u][0],dp[v][0] + val);
        vr = r[v],vl = r[v] - t[v] + 1;
        dp[u][0] = min(dp[u][0],dp[v][1] + val);
        ur = r[u],ur = r[u] - t[u] + 1;
        vl = l[v],vr = l[v] + t[v] - 1;
        dp[u][1] = min(dp[u][1],dp[v][0] + val);
        vr = r[v],vl = l[v] - t[v] + 1;
        dp[u][1] = min(dp[u][1],dp[v][1] + val);
    }
    if (leaf)
        dp[u][0] = dp[u][1] = 0;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i] >> t[i];
    for (int i = 1,u,v,c; i <= m; i++)
    {
        cin >> u >> v >> c;
        adde(u,v,c);
        adde(v,u,c);
    }
    memset(dp,0x3f,sizeof dp);
    dfs(1,-114514);
    cout << min(dp[1][0],dp[1][1]);
    return 0;
}
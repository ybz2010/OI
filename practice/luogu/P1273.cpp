#include<bits/extc++.h>
using namespace std;
const int maxn = 3005;
int n,m;
int a[maxn],siz[maxn];
int dp[maxn][maxn];
struct edge
{
    int v,w;
    edge *nxt;
}*head[maxn];
void adde(int u,int v,int w)
{
    auto tmp = new edge;
    tmp->v = v;
    tmp->w = w;
    tmp->nxt = head[u];
    head[u] = tmp;
}
void dfs(int u)
{
    if (u > n - m)
    {
        siz[u] = 1;
        dp[u][1] = a[u];
        return;
    }
    for (auto i = head[u]; i; i = i->nxt)
    {
        int v = i->v;
        dfs(v);
        siz[u] += siz[v];
        for (int j = siz[u]; j; j--)
            for (int k = 1; k <= siz[v]; k++)
                if (j >= k)
                    dp[u][j] = max(dp[u][j],dp[u][j - k] + dp[v][k] - i->w);
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n - m; i++)
    {
        int k,v,w;
        cin >> k;
        while (k --)
        {
            cin >> v >> w;
            adde(i,v,w);
        }
    }
    for (int i = n - m + 1; i <= n; i++)
        cin >> a[i];
    memset(dp,~0x7f,sizeof dp);
    for (int i = 1; i <= n; i++)
        dp[i][0] = 0;
    dfs(1);
    for (int i = m; i >= 1; i--)
    {   
        if (dp[1][i] >= 0)
        {
            cout << i;
            return 0;
        }
    }
    return 0;
}
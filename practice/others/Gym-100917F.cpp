#include<bits/extc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int maxn = 305;
const int inf = 0x3f3f3f3f3f3f;
int n;
int dis[maxn],fa[maxn];
bool vis[maxn];
int a[maxn][maxn];
void init()
{
    for (int j = 1; j <= n; j++)
        fa[j] = j;
}
int find(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = find(fa[x]);
}
void dij(int st)
{
    memset(dis,0x3f,sizeof dis);
    memset(vis,0,sizeof vis);
    priority_queue<pii,vector<pii>,greater<pii> >q;
    dis[st] = 0;
    q.push({0,st});
    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (int v = 1; v <= n; v++)
        {
            int w = a[u][v];
            if(a[u][v] > 0 && a[u][v] < inf)
            {
                if (dis[v] > dis[u] + w)
                {
                    if (u != st)
                        fa[v] = u;
                    dis[v] = dis[u] + w;
                    q.push({dis[v],v});
                }
            }
        }
    }
}
signed main()
{
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%lld",&a[i][j]);
            if (a[i][j] == -1)
                a[i][j] = inf;
        }
    }
    for(int i = 1;i <= n;i ++) a[i][i] = 0;
    for(int i = 1; i <= n; i++)
    {   
        init();
        dij(i);
        int ans = inf;
        for (int j = 1; j <= n; j++)
            if (fa[j] != j)
                ans = min(ans,dis[j] + a[i][j]);
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                if (j != i && k != i && find(j) != find(k))
                    ans = min(ans,dis[j] + dis[k] + a[j][k]);
        printf("%lld\n",ans >= inf ? -1ll : ans);
    }
    return 0;
}
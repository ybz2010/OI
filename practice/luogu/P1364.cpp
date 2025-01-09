#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 105;
int n,w[maxn];
int dis[maxn][maxn];
int cost(int x)
{
    int ret = 0;
    for (int i = 1; i <= n; i++)
        ret += dis[i][x] * w[i];
    return ret;
}
signed main()
{
    scanf("%d",&n);
    memset(dis,0x3f,sizeof dis);
    for (int i = 1; i <= n; i++)
    {
        dis[i][i] = 0;
        int u,v;
        scanf("%d%d%d",w + i,&u,&v);
        if (u)
            dis[i][u] = dis[u][i] = 1;
        if (v)
            dis[i][v] = dis[v][i] = 1;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dis[i][k] != inf && dis[k][j] != inf)
                    dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
    int ans = inf;
    for (int i = 1; i <= n; i++)
        ans = min(ans,cost(i));
    cout << ans;
    return 0;
}
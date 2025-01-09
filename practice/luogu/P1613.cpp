#include <bits/extc++.h>
#define int long long
using namespace std;
int n,m;
bool g[64][55][55];
int dis[55][55];
signed main()
{
    scanf("%lld%lld",&n,&m);
    memset(dis,0x3f,sizeof dis);
    while (m--)
    {
        int u,v;
        scanf("%lld%lld",&u,&v);
        dis[u][v] = 1;
        g[0][u][v] = 1;
    }
    for (int b = 1; b < 64; b++)
    {
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (g[b - 1][i][k] && g[b - 1][k][j])
                    {
                        g[b][i][j] = 1;
                        dis[i][j] = 1;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        dis[i][i] = 0;
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
    printf("%lld",dis[1][n]);
    return 0;
}
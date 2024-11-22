#include<bits/extc++.h>
#define inf 0x7f7f7f7f
#define pii pair<int,int>
// #define pow(x,k) (x * x)
using namespace std;
const int maxn = 5000 + 5;
int n,v,ans;
int g[maxn][maxn],dis[maxn];
bool vis[maxn];
pii p[maxn];
inline void read(int &x)
{
    x = 0;
    int f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9'){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = x * 10 + ch - '0'; ch = getchar();}
    x *= f;
}
void prim(int st)
{
    memset(dis,0x7f,sizeof dis);
    memset(vis,0,sizeof vis);
    for (int i = 1; i <= n; i++)
        dis[i] = v;
    vis[0] = 1;
    dis[st] = 0;
    for (int i = 1; i <= n; i++)
    {
        int u = 0,_min = inf;
        for (int j = 0; j <= n; j++)
        {
            // cout << (dis[j] == inf ? -1 : dis[j]) << " ";
            if (dis[j] < _min && !vis[j])
            {
                u = j;
                _min = dis[j];
            }
        }
        ans += _min;
        vis[u] = 1;
        for (int v = 0; v <= n; v++)
            if (!vis[v] && dis[v] > g[u][v])
                dis[v] = g[u][v];
    }
}
signed main()
{
    read(n),read(v);
    memset(g,0x7f,sizeof dis);
    for (int i = 1; i <= n; i++)
    {
        read(p[i].first),read(p[i].second);
        g[i][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            int w = pow(p[i].first - p[j].first,2) + pow(p[i].second - p[j].second,2);
            g[i][j] = g[j][i] = w;
        }
    }
    ans = 0;
    prim(0);
    cout << ans;
    return 0;
}
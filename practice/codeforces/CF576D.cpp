#include<bits/extc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define int long long
using namespace std;
const int maxn = 155;
int n,m;
int dis[maxn];
struct edge
{
    int u,v,d;
    friend bool operator<(edge x,edge y){return x.d < y.d;};
}e[maxn];
struct mat
{
    bitset<maxn>a[maxn];
    mat()
    {
        for (int i = 1; i <= 150; i++)
            for (int j = 1; j <= 150; j++)
                a[i][j] = 0;
    };
    bitset<maxn> &operator[](int x){return a[x];}
    void base()
    {
        for (int i = 1; i <= 150; i++)
            a[i][i] = 1;
    }
    friend mat operator*(mat x,mat y)
    {
        mat ret;
        for (int i = 1; i <= n; i++)
            for (int k = 1; k <= n; k++)
                if (x[i][k])
                    ret[i] |= y[k];
        return ret;
    }
}base,origin;
mat binpow(mat x,int y)
{
    mat ret;
    ret.base();
    while (y)
    {
        if (y & 1)
            ret = ret * x;
        x = x * x;
        y >>= 1;
    }
    return ret;
}
void bfs()
{
    queue<int>q;
    memset(dis,0x3f,sizeof dis);
    for (int i = 1; i <= n; i++)
    {   
        if (origin[1][i])
        {
            q.push(i);
            dis[i] = 0;
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 1; v <= n; v++)
        {
            if (base[u][v] && dis[v] == inf)
            {
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
}
signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> e[i].u >> e[i].v >> e[i].d;
    sort(e + 1,e + m + 1);
    origin[1][1] = 1;
    int ans = inf,t = 0;
	dis[n] = inf;
    for (int i = 1; i <= m; i++)
    {
        if (ans < e[i].d)
            break;
        int d = e[i].d - t;
        t = e[i].d;
        origin = origin * binpow(base,d);
        base[e[i].u][e[i].v] = 1;
        if (e[i + 1].d != e[i].d || i == m)
            bfs();
        ans = min(ans,t + dis[n]);
    }
    if (ans == inf)
        cout << "Impossible";
    else
        cout << ans;
    return 0;
}
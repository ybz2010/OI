#include<bits/extc++.h>
#define int long long
#define ri register
#define pii pair<int,int>
using namespace std;
const int maxn = 5005;
int n,v,idx;
int fa[maxn];
pii p[maxn];
struct edge
{
    int u,v,w;
    edge(int u = 0,int v = 0,int w = 0):u(u),v(v),w(w){};
    bool operator<(edge x){return w < x.w;}
}e[maxn * maxn];
inline void read(int &x)
{
    x = 0;
    ri int f = 1;
    ri char ch = getchar();
    while (ch < '0' || ch > '9'){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = x * 10 + ch - '0'; ch = getchar();}
    x *= f;
}
inline void init()
{
    for (ri int i = 0; i <= n; i++)    
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
    read(n),read(v);
    init();
    for (ri int i = 1; i <= n; i++)
        read(p[i].first),read(p[i].second);
    for (ri int i = 1; i <= n; i++)
        for (ri int j = 1; j < i; j++)
        {
            int w = pow(p[i].first - p[j].first,2) + pow(p[i].second - p[j].second,2);
            if (w > v)
                continue;
            e[++idx] = edge(i,j,w);
        }
    for (ri int i = 1; i <= n; i++)
        e[++idx] = edge(0,i,v);
    sort(e + 1,e + idx + 1);
    ri int ans = 0;
    for (ri int i = 1; i <= idx; i++)
    {
        int fu = find(e[i].u),fv = find(e[i].v);
        if (fu != fv)
        {
            ans += e[i].w;
            fa[fu] = fv;
        }
    }
    printf("%lld",ans);
    return 0;
}
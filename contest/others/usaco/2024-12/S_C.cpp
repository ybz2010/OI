#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxq = 2e5 + 5;
const int maxn = 1e6 + 5;
const int dir[4][2] = {-1,0,1,0,0,-1,0,1};
int n,q;
int x[maxq],y[maxq],d[maxq];
int ans[maxn],cnt;
bool vis[maxn],mp[maxn];
struct edge
{
    int v;
    edge *nxt;
}*head[maxn];
int toint(int x,int y)
{
    if (x < 1 || x > n || y < 1 || y > n)
        return 0;
    return (x - 1) * n + y;
}
void adde(int u,int v)
{
    auto tmp = new edge;
    tmp->v = v;
    tmp->nxt = head[u];
    head[u] = tmp;
}
void dfs(int u)
{
    if (vis[u])
        return;
    vis[u] = 1;
    cnt ++;
    for (auto i = head[u]; i; i = i->nxt)
        dfs(i->v);
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= q; i++)
    {
        char ch;
        cin >> x[i] >> y[i] >> ch;
        mp[toint(x[i],y[i])] = 1;
        switch (ch)
        {
        case 'U':
            d[i] = 0;
            break;
        case 'D':
            d[i] = 1;
            break;
        case 'L':
            d[i] = 2;
            break;
        default:
            d[i] = 3;
            break;
        }
        adde(toint(x[i] + dir[d[i]][0],y[i] + dir[d[i]][1]),toint(x[i],y[i]));//建反图
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            // cout << i << " " << j << " " << mp[toint(i,j)] << endl;
            if (!mp[toint(i,j)])
                for (int k = 0; k < 4; k++)
                {
                    adde(toint(i + dir[k][0],j + dir[k][1]),toint(i,j));
                    // cout << toint(i,j) << " " << toint(i + dir[k][0],j + dir[k][1]) << endl;
                }
        }
    vis[0] = 1;
    for (int i = q; i >= 1; i--)
    {
        static int st = 0;
        if (st )
        dfs(st);
        ans[i] = ans[i + 1];
        
        for (int j = 0; j < 4; j++)
        {
            if (j == d[i])
                continue;
            adde(toint(x[i],y[i]),toint(x[i] + dir[j][0],y[i] + dir[j][1]));
        }
    }
    for (int i = 1; i <= q; i++)
        cout << n - ans[i] << endl;
    return 0;
}
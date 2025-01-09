#include<bits/extc++.h>
#pragma GCC optimize(2)
using namespace std;
const int maxn(3005);
const int maxq(4e5 + 5);
int n,m,q;
int ans[maxq];
bool vis[maxn];
int st[maxn];
void read(int &x)
{
    x = 0;
    int f = 1;
    char ch = getchar();
    while (!isdigit(ch)){f = ch == '-' ? -1 : 1; ch = getchar();}
    while (isdigit(ch)){x = (x << 1) + (x << 3) + (ch ^ 48); ch = getchar();}
    x *= f;
}
vector<int>g1[maxn],g2[maxn],g3[maxn];//g1是正图，g2是反图，g3是建出来的树
struct query{int u,v,k,id;};
vector<query>q1[maxn],q2[maxn];
void dfs1(int u)
{
    vis[u] = 1;
    for (auto v : g2[u])
        if (!vis[v])
            dfs1(v);
}
void dfs2(int u)
{
    st[++st[0]] = u;
    for (auto i : q2[u])
        if (st[0] >= i.k)
            ans[i.id] = st[st[0] - i.k + 1];
    for (auto v : g3[u])
        dfs2(v);
    st[0] --;
}
signed main()
{
    read(n),read(m),read(q);
    int u,v,k;
    for (int i(1); i <= m; i++)
    {
        read(u),read(v);
        g1[u].push_back(v);
        g2[v].push_back(u);
    }
    for (int i(1); i <= n; i++)
        sort(g1[i].begin(),g1[i].end());
    for (int i(1); i <= q; i++)
    {
        read(u),read(v),read(k);
        q1[v].push_back((query){u,v,k,i});
    }
    memset(ans,0xff,sizeof ans);
    for (int ed(1); ed <= n; ed++)
    {
        for (int j(1); j <= n; j++)
            vis[j] = 0,q2[j].clear(),g3[j].clear();
        dfs1(ed);
        for (int i(1); i <= n; i++)
        {
            if (vis[i] && i != ed)
            {
                for (auto v : g1[i])
                {
                    if (vis[v])
                    {
                        g3[v].push_back(i);
                        break;
                    }
                }
            }
        }
        for (auto i : q1[ed])
            q2[i.u].push_back(i);
        dfs2(ed);
    }
    for (int i(1); i <= q; i++)
        printf("%d\n",ans[i]);
    return 0;
}
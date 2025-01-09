#include<bits/extc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 1e5 + 5;
int n;
int head[maxn],in[maxn],idx;
int dp1[maxn][2],dp2[maxn][2];
bool vis[maxn];
vector<int>lp,son[maxn];
struct edge
{
    int v,nxt;
    edge(int v = 0,int nxt = 0):v(v),nxt(nxt){};
}e[maxn << 1];
void adde(int u,int v)
{
    e[++idx] = edge(v,head[u]);
    head[u] = idx;
}
void tpsort()
{
    queue<int>q;
    for (int i = 1; i <= n; i++)
        if (in[i] == 1)
            q.push(i);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].v;
            if (in[v] > 1)
            {
                in[v] --;
                if (in[v] == 1)
                    q.push(v);
            }
        }
    }
}
void loop(int u)
{
    vis[u] = 1;
    lp.push_back(u);
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (in[v] == 2 && !vis[v])
            loop(v);
    }
}
void dfs(int u,int fa)
{
    dp1[u][0] = 0;
    dp1[u][1] = 1;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == fa)
            continue;
        son[u].push_back(v);
        dfs(v,u);
    }
    for (auto v : son[u])
    {
        if (son[v].empty())
        {
            dp1[u][0] += dp1[u][1];
            dp1[u][1] += dp1[v][0];
        }
        else
        {
            int _min = inf,sum = 0;
            for (auto j : son[v])
            {
                sum += dp1[j][0];
                _min = min(_min,dp1[j][1] - dp1[j][0]);
            }
            dp1[u][0] += 1 + sum + _min;
        }
    }
}
signed main()
{
    scanf("%d",&n);
    for (int i = 1,u,v; i <= n; i++)
    {
        scanf("%d%d",&u,&v);
        adde(u,v);
        adde(v,u);
        in[u] ++,in[v] ++;
    }
    tpsort();
    for (int i = 1; i <= n; i++)
        if (!vis[i] && in[i] == 2)
            loop(i);
    return 0;
}
#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 305;
const int maxm = 100005;
int n,sub;
int in[maxn],head[maxn],idx = 1;
int bel[maxn],siz[maxn],sc,ans;
bool vis[maxn];
vector<int>scc[maxn];
struct edge
{
    int v,w,nxt;
    edge(int v = 0,int w = 0,int nxt = 0):v(v),w(w),nxt(nxt){};
}e[maxm];
void adde(int u,int v,int w)
{
    e[++idx] = edge(v,w,head[u]);
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
void dfs1(int u,int id)
{
    bel[u] = id;
    scc[id].push_back(u);
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (!bel[v] && in[v] == 2)
            dfs1(v,id);
    }
}
void dfs2(int u,int st,int sum)
{
    vis[u] = 1;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == st)
        {
            sum += e[i].w;
            ans = min(ans,sum);
        }
        else if (!vis[v])
            dfs2(v,st,sum + e[i].w);
    }
    vis[u] = 0;
}
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld",&sub,&n);
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int w;
            scanf("%lld",&w);
            if (w != -1)
            {
                in[i] ++;
                in[j] ++;
                adde(i,j,w);
                adde(j,i,w);
            }
        }
    }
    if (sub == 1)
    {
        tpsort();
        for (int i = 1; i <= n; i++)
            if (!bel[i] && in[i] == 2)
                dfs1(i,++sc);
        for (int i = 1; i <= sc; i++)
        {
            int len = scc[i].size();
            scc[i].push_back(scc[i][0]);
            for (int j = 0; j < len; j++)
            {
                for (int k = head[scc[i][j]]; k; k = e[k].nxt)
                {
                    int v = e[k].v;
                    if (v == scc[i][j + 1])
                    {
                        siz[i] += e[k].w;
                        break;
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (bel[i])
                printf("%lld ",siz[bel[i]]);
            else
                printf("-1 ");
        }
    }
    else 
    {
        for (int i = 1; i <= n; i++)
        {
            memset(vis,0,sizeof vis);
            ans = INT_MAX;
            dfs2(i,i,0);
            printf("%lld ",ans == INT_MAX ? -1 : ans);
        }
    }
    putchar('\n');
    return 0;
}
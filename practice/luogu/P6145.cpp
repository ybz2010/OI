#include<bits/extc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n,m,c;
int head[maxn],idx = 1;
int dis[maxn],vis[maxn];
struct edge
{
    int v,w,nxt;
    edge(int v = 0,int w = 0,int nxt = 0):v(v),w(w),nxt(nxt){};
}e[maxn << 1];
void adde(int u,int v,int w)
{
    e[++idx] = edge(v,w,head[u]);
    head[u] = idx;
}
void spfa(int st)
{
    memset(dis,-1,sizeof dis);
    memset(vis,0,sizeof vis);
    queue<int>q;
    dis[st] = 0;
    vis[st] = 1;
    q.push(st);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].v,w = e[i].w;
            if (dis[v] < dis[u] + w)
            {
                dis[v] = dis[u] + w;
                if (!vis[v])
                {
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}
signed main()
{
    scanf("%d%d%d",&n,&m,&c);
    for (int i = 1; i <= n; i++)
    {
        int s;
        scanf("%d",&s);
        adde(0,i,s);
    }
    for (int i = 1; i <= c; i++)
    {
        int a,b,x;
        scanf("%d%d%d",&a,&b,&x);
        adde(a,b,x);
    }
    spfa(0);
    for (int i = 1; i <= n; i++)
        cout << dis[i] << "\n";
    return 0;
}
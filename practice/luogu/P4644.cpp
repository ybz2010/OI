#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#define int long long
#define inf 0x7f7f7f7f7f7f7f7f
#define mkp(x,y) pii(x,y)
using namespace std;
const int maxn = 1e5 + 5;
int n,m,ed;
int head[maxn],idx;
int dis[maxn];
bool vis[maxn];
struct edge
{
    int v,w,nxt;
    edge(int v = 0,int w = 0,int nxt = 0):v(v),w(w),nxt(nxt){};
}e[maxn];
struct pii
{
    int first,second;
    pii(int first,int second):first(first),second(second){};
};
bool operator<(const pii x,const pii y)
{
    if (x.first == y.first)
        return x.second < y.second;
    return x.first < y.first;
}
bool operator>(const pii x,const pii y)
{
    if (x.first == y.first)
        return x.second > y.second;
    return x.first > y.first;
}
void adde(int u,int v,int w)
{
    e[++idx] = edge(v,w,head[u]);
    head[u] = idx;
}
void dij(int st)
{
    memset(dis,0x7f,sizeof dis);
    memset(vis,0,sizeof vis);
    priority_queue<pii,vector<pii>,greater<pii> >q;
    dis[st] = 0;
    q.push(mkp(0,st));
    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].v,w = e[i].w;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                q.push(mkp(dis[v],v));
            }
        }
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> ed;
    for (int i = 1; i < 86400; i++)
        adde(i,i - 1,0);
    for (int i = 1; i <= n; i++)
    {
        int l,r,w;
        cin >> l >> r >> w;
        adde(l,r + 1,w);
    }
    dij(m);
    cout << (dis[ed + 1] == inf ? -1 : dis[ed + 1]);
    return 0;
}
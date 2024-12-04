#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 5e5 + 5;
int n,Q;
int head[maxn],idx = 0;
int dep[maxn],dsu[maxn];
struct query
{
    int x,y,tim;
    query(int x = 0,int y = 0,int tim = 0):x(x),y(y),tim(tim){};
};
vector<query>q;
struct edge
{
    int v,w,tim,nxt;
    edge(int v = 0,int w = 0,int tim = 0,int nxt = 0):v(v),w(w),tim(tim),nxt(nxt){};
}e[maxn << 1];
struct father
{
    int u,tim,len;
    father(int u = 0,int tim = 0,int len = 0):u(u),tim(tim),len(len){};
}f[maxn][30];
void adde(int u,int v,int w,int tim)
{
    e[++idx] = edge(v,w,tim,head[u]);
    head[u] = idx;
}
void init()
{
    for (int i = 0; i <= n; i++)
        dsu[i] = i;
}
int find(int u)
{
    if (dsu[u] == u)
        return u;
    return dsu[u] = find(dsu[u]);
}
void un(int u,int v)
{
    int fu = find(u),fv = find(v);
    if (fu != fv)
        dsu[fu] = fv;
}
vector<int> input()
{
    vector<int>ret;
    char c;
    int x;
    while(scanf("%lld%c",&x,&c))
    {
        ret.push_back(x);
        if(c == '\n')
            break;
    }
    return ret;
}
void dfs(int u,int len,int t,int fa)
{
    dep[u] = dep[fa] + 1;
    f[u][0] = father(fa,t,len);
    for (int i = 1; i < 20; i++)
    {
        f[u][i].u = f[f[u][i - 1].u][i - 1].u;
        f[u][i].tim = max(f[u][i - 1].tim,f[f[u][i - 1].u][i - 1].tim);
        f[u][i].len = f[u][i - 1].len + f[f[u][i - 1].u][i - 1].len;
    }
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v,w = e[i].w,tim = e[i].tim;
        if (v == fa)
            continue;
        dfs(v,w,tim,u);
    }
}
int lca(int u,int v,int tim)
{
    if (dep[u] < dep[v])
        swap(u,v);
    int ret = 0;
    for (int i = 19; i >= 0; i--)
    {
        if (dep[u] - (1 << i) >= dep[v])
        {
            if (f[u][i].tim > tim)
                return -1;
            ret += f[u][i].len;
            u = f[u][i].u;
        }
    }
    if (u == v)
        return ret;
    for (int i = 19; i >= 0; i--)
    {
        if (f[u][i].u != f[v][i].u)
        {
            if (f[u][i].tim > tim || f[v][i].tim > tim) 
                return -1;
            ret += f[u][i].len + f[v][i].len;
            u = f[u][i].u,v = f[v][i].u;
        }
    }
    if (f[u][0].tim > tim || f[v][0].tim > tim)
        return -1;
    ret += f[u][0].len + f[v][0].len;
    return ret;
}
signed main()
{
    vector<int>que = input();
    n = que[0],Q = que[1];
    init();
    for (int i = 1; i <= Q; i++)
    {
        que = input();
        if (que.size() == 2)
            q.push_back(query(que[0],que[1],i));
        else if(que[0] != que[1])
        {
            adde(que[0],que[1],que[2],i);
            adde(que[1],que[0],que[2],i);
            un(que[0],que[1]);
        }
    }
    for (int i = 1; i <= n; i++)
        if (!dep[i])
            dfs(i,0,0,0);
    for (auto i : q)
    {
        if (find(i.x) != find(i.y))
            printf("-1\n");
        else
            printf("%lld\n",lca(i.x,i.y,i.tim));
    }
    return 0;
}
/*
4 7
1 3
1 3 100
2 3 200
1 3
1 2
2 3
1 4
*/
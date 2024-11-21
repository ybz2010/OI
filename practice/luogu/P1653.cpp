#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxn = 505;
const int maxm = 1.5e6 + 5;
const int dir[4][2] = {1,0,-1,0,0,1,0,-1};
int m,n;
int h[maxn][maxn];
int u[maxm],v[maxm],idx;
bool vis[maxm];
int dfn[maxm],low[maxm],tim;
int bel[maxm],sc;
int in[maxm],out[maxm];
stack<int>st;
struct edge
{
    int v,nxt;
    edge(int v = 0,int nxt = 0):v(v),nxt(nxt){};
};
struct graph
{
    edge e[maxm * 5];
    int head[maxn * maxn],idx;
    graph(){memset(head,0,sizeof head);idx = 1;};
    void adde(int u,int v)
    {
        e[++idx] = edge(v,head[u]);
        head[u] = idx;
    }
}g1;
int toint(int x,int y){return (x - 1) * m + y;}
void tarjan(int u)
{
    dfn[u] = low[u] = ++tim;
    vis[u] = 1;
    st.push(u);
    for (int i = g1.head[u]; i; i = g1.e[i].nxt)
    {
        int v = g1.e[i].v;
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else if (vis[v])    
            low[u] = min(low[u],dfn[v]);
    }
    if (low[u] == dfn[u])
    {
        sc ++;
        while (st.top() != u)
        {
            bel[st.top()] = sc;
            vis[st.top()] = 0;
            st.pop();
        }
        bel[u] = sc;
        vis[u] = 0;
        st.pop();
    }
}
signed main()
{
    scanf("%lld%lld",&m,&n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)    
            scanf("%lld",&h[i][j]);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int tx = i + dir[k][0];
                int ty = j + dir[k][1];
                if (tx >= 1 && ty >= 1 && tx <= n && ty <= m && h[tx][ty] <= h[i][j])
                {
                    idx ++;
                    u[idx] = toint(i,j);
                    v[idx] = toint(tx,ty);
                    g1.adde(toint(i,j),toint(tx,ty));
                }
            }
        }
    }
    for (int i = 1; i <= n * m; i++)
        if (!dfn[i])
            tarjan(i);
    for (int i = 1; i <= idx; i++)
    {
        if (bel[u[i]] != bel[v[i]])
        {
            in[bel[v[i]]]++;
            out[bel[u[i]]]++;
        }
    }
    int cntin,cntout;
    cntin = cntout = 0;
    for (int i = 1; i <= sc; i++)
    {
        if (in[i] == 0)
            cntin++;
        if (out[i] == 0)
            cntout++;
    }
    printf("%lld",sc == 1 ? 0 : max(cntin,cntout));
    return 0;
}
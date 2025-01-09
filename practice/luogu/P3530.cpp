#include<bits/extc++.h>
#define inf 0x7f7f7f7f
using namespace std;
const int maxn = 605;
int n,m1,m2;
int dis[maxn][maxn];
int dfn[maxn],low[maxn],tim;
int bel[maxn],sc,ans[maxn];
bool vis[maxn];
stack<int>st;
void tarjan(int u)
{
    dfn[u] = low[u] = ++tim;
    vis[u] = 1;
    st.push(u);
    for (int v = 1; v <= n; v++)
    {
        if (dis[u][v] == inf)
            continue;
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
    scanf("%d%d%d",&n,&m1,&m2);
    memset(dis,0x7f,sizeof dis);
    int a,b;
    for (int i = 1; i <= m1; i++)
    {
        scanf("%d%d",&a,&b);
        dis[a][b] = min(dis[a][b],1);
        dis[b][a] = min(dis[b][a],-1);
    }
    for (int i = 1; i <= m2; i++)
    {
        scanf("%d%d",&a,&b);
        dis[b][a] = min(dis[b][a],0);
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i][i] = 0;
        if (!dfn[i])
            tarjan(i);
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (bel[i] == bel[j] && bel[j] == bel[k] && dis[i][k] != inf && dis[k][j] != inf)
                    dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
    for (int i = 1; i <= n; i++)
    {
        if (dis[i][i] < 0)
        {
            printf("NIE");
            return 0;
        }
        for (int j = 1; j <= n; j++)
            if (bel[i] == bel[j])
                ans[bel[i]] = max(ans[bel[i]],dis[i][j] + 1);
    }
    int Ans = 0;
    for (int i = 1; i <= sc; i++)
        Ans += ans[i];
    printf("%d",Ans);
    return 0;
}
#include<bits/extc++.h>
using namespace std;
const int maxn = 1505;
int n;
int head[maxn],idx = 1;
int dp[maxn][2];
struct edge
{
    int v,nxt;
    edge(int v = 0,int nxt = 0):v(v),nxt(nxt){};
}e[maxn << 1];
void read(int &ret)
{
    ret = 0;
    int f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9'){f = (ch == '-' ? -1 : 1); ch = getchar();}
    while (ch >= '0' && ch <= '9'){ret = ret * 10 + ch - '0'; ch = getchar();}
    ret *= f;
}
void adde(int u,int v)
{
    e[++ idx] = edge(v,head[u]);
    head[u] = idx;
}
void dfs(int u,int fa)
{
    dp[u][0] = 0;
    dp[u][1] = 1;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == fa)
            continue;
        dfs(v,u);
        dp[u][0] += dp[v][1];
        dp[u][1] += min(dp[v][0],dp[v][1]);
    }
}
inline void init()
{
    memset(head,0,sizeof head);
    memset(dp,0,sizeof dp);
    idx = 1;
}
void solve(int n)
{
    init();
    for (int i = 1; i <= n; i ++)
    {
        int u,v,k;
        read(u),read(k);
        while (k --)
        {
            read(v);
            adde(u,v);
            adde(v,u);
        }
    }
    dfs(0,-1);
    printf("%d\n",min(dp[0][0],dp[0][1]));
}
signed main()
{
    while (scanf("%d",&n) != EOF)
        solve(n);
    return 0;
}
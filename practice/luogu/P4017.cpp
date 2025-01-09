#include<bits/extc++.h>
#define int long long
#define mod 80112002
using namespace std;
const int maxn = 5005;
const int maxm = 5e5 + 5;
int n,m;
int head[maxn],idx = 1;
int dp[maxn],in[maxn],out[maxn];
struct edge
{
    int v,nxt;
    edge(int v = 0,int nxt = 0):v(v),nxt(nxt){};
}e[maxm];
void adde(int u,int v)
{
    e[++idx] = edge(v,head[u]);
    head[u] = idx;
}
void tpsort()
{
    queue<int>q;
    for (int i = 1; i <= n; i++)
    {
        if (!in[i])
        {
            q.push(i);
            dp[i] = 1;
        }
    }
    int ret = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        ret = dp[u];
        for (int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].v;
            in[v] --;
            dp[v] = (dp[v] + dp[u]) % mod;
            if (in[v] == 0)
                q.push(v);
        }
    }
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    for (int i = 1; i <= m; i++)
    {
        int u,v;
        scanf("%lld%lld",&v,&u);
        adde(u,v);
        in[v] ++;
        out[u] ++;
    }
    tpsort();
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (out[i] == 0)
            ans = (ans + dp[i]) % mod;
    cout << ans;
    return 0;
}
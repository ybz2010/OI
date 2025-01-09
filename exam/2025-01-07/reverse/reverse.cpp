#include<bits/extc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e6 + 5;
int n,m;
int head[maxn],idx;
int vis[maxn],cnt[maxn];
vector<vector<int>>a;
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
bool dfs(int u)
{
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v,w = vis[u] ^ e[i].w;
        if (vis[v])
        {
            if (vis[v] != w)
                return 1;
        }
        else
        {
            vis[v] = w;
            if (dfs(v))
                return 1;
        }
    }
    return 0;
}
void solve()
{
    scanf("%lld%lld",&n,&m);
    fill(head + 1,head + n + 1,0);
    fill(vis + 1,vis + n + 1,0);
    fill(cnt + 1,cnt + m + 1,0);
    a.resize(n + 5);
    for (int i = 1; i <= n; i++)
    {
        a[i].resize(m + 5);
        for (int j = 1,ch; j <= m; j++)
        {
            ch = getchar();
            while (!isdigit(ch))
                ch = getchar();
            a[i][j] = ch - '0';
            cnt[j] += ch - '0';
        }
    }
    if ((m & 1) && cnt[(m + 1) >> 1] > 1)
    {
        puts("0");
        return;
    }
    for (int i = 1; i <= (m >> 1); i++)
    {
        if (cnt[i] + cnt[m - i + 1] > 2)
        {
            puts("0");
            return;
        }
        else if (cnt[i] + cnt[m - i + 1] < 2)
            continue;
        int tmp1,tmp2;
        tmp1 = tmp2 = 0;
        for (int j = 1; j <= n; j++)
        {
            if (a[j][i])
                tmp1 ? tmp2 = j : tmp1 = j;
            if (a[j][m - i + 1])
                tmp1 ? tmp2 = j : tmp1 = j;
        }
        if (tmp1 == tmp2)
            continue;
        if (cnt[i] == 2 || cnt[m - i + 1] == 2)
        {
            adde(tmp1,tmp2,0b01);
            adde(tmp2,tmp1,0b01);
        }
        else
        {
            adde(tmp1,tmp2,0b00);
            adde(tmp2,tmp1,0b00);
        }
    }
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            vis[i] = 0b10;
            if (dfs(i))
            {
                puts("0");
                return;
            }
            ans = (ans << 1) % mod;
        }
    }
    printf("%lld\n",ans);
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}
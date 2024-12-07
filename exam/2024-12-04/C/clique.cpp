#include<bits/extc++.h>
using namespace std;
const int maxn = 2005;
int n,m;
int head[maxn],idx = 1;
int col[maxn],cnt[3];
bool g[maxn][maxn];
bitset<maxn>f;
struct edge
{
    int v,nxt;
    edge(int v = 0,int nxt = 0):v(v),nxt(nxt){};
}e[maxn * maxn];
void adde(int u,int v)
{
    e[++ idx] = edge(v,head[u]);
    head[u] = idx; 
}
void dfs(int u)
{
    cnt[col[u]] ++;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (!col[v])
        {
            col[v] = 3 - col[u];
            dfs(v);
        }
        else if (col[v] == col[u])
        {
            puts("-1");
            exit(0);  
        }
    }
}
int calc(int x){return (x * (x - 1) / 2) + ((n - x) * (n - x - 1) / 2);}
signed main()
{
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char ch;
            cin >> ch;
            g[i][j] = (ch == '1');
        }
    }
    for (int i = 1; i <= n; i++)
        g[i][i] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!g[i][j])
                adde(i,j);
    f[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!col[i])
        {
            cnt[1] = cnt[2] = 0;
            col[i] = 1;
            dfs(i);
			for(int j = n; j >= 0; j--)
            {
				bool t = 0;
				if(j >= cnt[1])
                    t |= f[j - cnt[1]];
				if(j >= cnt[2])
                    t |= f[j - cnt[2]];
				f[j] = t;
			}
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i <= n; i++)
        if (f[i])
            ans = min(ans,calc(i));
    printf("%d",ans);
    return 0;
}
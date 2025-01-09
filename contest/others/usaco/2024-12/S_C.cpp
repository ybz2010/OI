#include<bits/extc++.h>
#define int long long
using namespace std;
const int maxq = 2e5 + 5;
const int maxn = 1e6 + 5;
const int dir[4][2] = {-1,0,1,0,0,-1,0,1};
int n,q;
int x[maxq],y[maxq],d[maxq];
int ans[maxn],cnt = -1;
bool vis[maxn],mp[maxn];
struct edge {
    int v;
    edge *nxt;
    ~edge(){if (nxt) delete nxt;}
}*head[maxn];
int toint(int x,int y) {
    if (x < 1 || x > n || y < 1 || y > n)
        return 0;
    return (x - 1) * n + y;
}
void adde(int u,int v) {
    auto tmp = new edge;
    tmp->v = v;
    tmp->nxt = head[u];
    head[u] = tmp;
}
void dfs(int u) {
    if (vis[u])
        return;
    vis[u] = 1;
    cnt ++;
    for (auto i = head[u]; i; i = i->nxt)
        dfs(i->v);
}
signed main() {
    scanf("%lld%lld",&n,&q);
    for (int i = 1; i <= q; i++) {
        scanf("%lld%lld",x + i,y + i);
        char ch;
        cin >> ch;
        mp[toint(x[i],y[i])] = 1;
        switch (ch) {
        case 'U':
            d[i] = 0;
            break;
        case 'D':
            d[i] = 1;
            break;
        case 'L':
            d[i] = 2;
            break;
        default:
            d[i] = 3;
            break;
        }
        adde(toint(x[i] + dir[d[i]][0],y[i] + dir[d[i]][1]),toint(x[i],y[i]));//建反图
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!mp[toint(i,j)])
                for (int k = 0; k < 4; k++)
                    adde(toint(i + dir[k][0],j + dir[k][1]),toint(i,j));
    for (int i = q; i >= 1; i--) {
        static int st = 0;
        static bool fl = 1;
        if (fl)
            dfs(st);
        ans[i] = n * n - cnt;
        st = toint(x[i],y[i]);
        fl = 0;
        for (int j = 0; j < 4; j++)
        {
            if (j == d[i])
                continue;
            int tx = x[i] + dir[j][0];
            int ty = y[i] + dir[j][1];
            fl |= vis[toint(tx,ty)];
            adde(toint(tx,ty),st);
        }
        fl &= (!vis[st]);
    }
    for (int i = 1; i <= q; i++)
        printf("%lld\n",ans[i]);
    return 0;
}
#include<bits/extc++.h>
#define int long long
#define inf 0x7f7f7f7f7f7f7f7f
#define ls (rt << 1)
#define rs (rt << 1 | 1)
using namespace std;
const int maxn = 2e5 + 5;
int n,k;
int d[maxn],s[maxn],c[maxn],w[maxn];
int st[maxn],ed[maxn],dp[maxn];
struct edge
{
    int v;
    edge *nxt;
}*head[maxn];
struct 世界树上最纯净的枝丫
{
    int l,r;
    int val,lazy;
}tree[maxn << 2];
void adde(int u,int v)
{
    auto tmp = new edge;
    tmp->v = v;
    tmp->nxt = head[u];
    head[u] = tmp;
}
void push_up(int rt){tree[rt].val = min(tree[ls].val,tree[rs].val);}
void push_down(int rt)
{
    if (tree[rt].lazy == 0)
        return;
    tree[ls].val += tree[rt].lazy;
    tree[rs].val += tree[rt].lazy;
    tree[ls].lazy += tree[rt].lazy;
    tree[rs].lazy += tree[rt].lazy;
    tree[rt].lazy = 0;
}   
void build(int l,int r,int rt)
{
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].lazy = 0;
    if (l == r)
    {
        tree[rt].val = dp[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
    push_up(rt);
}
void upd(int ql,int qr,int x,int rt = 1)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (ql <= l && r <= qr)
    {
        tree[rt].val += x;
        tree[rt].lazy += x;
        return;
    }
    push_down(rt);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        upd(ql,qr,x,ls);
    if (qr > mid)
        upd(ql,qr,x,rs);
    push_up(rt);
}
int que(int ql,int qr,int rt = 1)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (ql <= l && r <= qr)
        return tree[rt].val;
    push_down(rt);
    int mid = (l + r) >> 1,ret = inf;
    if (ql <= mid)
        ret = min(ret,que(ql,qr,ls));
    if (qr > mid)
        ret = min(ret,que(ql,qr,rs));
    return ret;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    k ++;
    for (int i = 2; i <= n; i++)
        cin >> d[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    n ++;
    d[n] = w[n] = inf;
    for (int i = 1; i <= n; i++)
    {
        st[i] = lower_bound(d + 1,d + n + 1,d[i] - s[i]) - d;
        ed[i] = upper_bound(d + 1,d + n + 1,d[i] + s[i]) - d - 1;
        adde(ed[i],i);
    }
    int ans = inf,tmp = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = tmp + c[i];
        for (auto j = head[i]; j; j = j->nxt)
            tmp += w[j->v];
    }
    ans = min(ans,dp[n]);
    for (int j = 2; j <= k; j++)
    {
        build(1,n,1);
        for (int i = 1; i <= n; i++)
        {
            dp[i] = (i >= j ? que(j - 1,i - 1) : 0) + c[i];
            for (auto k = head[i]; k; k = k->nxt)
                if (st[k->v] > 1)
                    upd(1,st[k->v] - 1,w[k->v]);
        }
        ans = min(ans,dp[n]);
    }
    cout << ans;
    return 0;
}
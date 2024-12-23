#include<bits/extc++.h>
#define int long long
#define ls (rt << 1)
#define rs (rt << 1 | 1)
using namespace std;
const int maxn = 2e5 + 5;
int n,m;
int a[maxn];
struct edge
{
    int l,p;
    edge *nxt;
}*head[maxn];
struct 世界树上最纯净的枝丫
{
    int l,r;
    int val,lazy;
}tree[maxn << 2];
void push_up(int rt){tree[rt].val = max(tree[ls].val,tree[rs].val);}
void push_down(int rt)
{
    if (!tree[rt].lazy)
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
    if (l == r)
    {
        tree[rt].val = tree[rt].lazy = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
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
void adde(int l,int r,int p)
{
    auto tmp = new edge;
    tmp->l = l;
    tmp->p = p;
    tmp->nxt = head[r];
    head[r] = tmp;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int l,r,p;
    for (int i = 1; i <= m; i++)
    {
        cin >> l >> r >> p;
        adde(l,r,p);
    }
    build(1,n,1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        upd(i,i,ans);
        upd(1,i,-a[i]);
        for (auto j = head[i]; j; j = j->nxt)
            upd(1,j->l,j->p);
        ans = max(ans,tree[1].val);
    }
    cout << ans;
    return 0;
}
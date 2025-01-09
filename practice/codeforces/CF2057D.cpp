#include<bits/extc++.h>
#define int long long
#define ls (rt << 1)
#define rs (rt << 1 | 1)
using namespace std;
const int maxn = 2e5 + 5;
int n,q;
int a[maxn],b[maxn];
struct Nahida{int l,r,mina,minb,maxa,maxb,ansa,ansb;}tree[maxn << 2];
void push_up(int rt)
{
    tree[rt].maxa = max(tree[ls].maxa,tree[rs].maxa);
    tree[rt].mina = min(tree[ls].mina,tree[rs].mina);
    tree[rt].maxb = max(tree[ls].maxb,tree[rs].maxb);
    tree[rt].minb = min(tree[ls].minb,tree[rs].minb);
    tree[rt].ansa = max({tree[ls].ansa,tree[rs].ansa,tree[rs].maxa - tree[ls].mina});
    tree[rt].ansb = max({tree[ls].ansb,tree[rs].ansb,tree[ls].maxb - tree[rs].minb});
}
void build(int l,int r,int rt)
{
    tree[rt].l = l;
    tree[rt].r = r;
    if (l == r)
    {
        tree[rt].maxa = tree[rt].mina = a[l];
        tree[rt].maxb = tree[rt].minb = b[l];
        tree[rt].ansa = tree[rt].ansb = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
    push_up(rt);
}
void upd(int pos,int v1,int v2,int rt)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (l == r)
    {
        tree[rt].maxa = tree[rt].mina = v1;
        tree[rt].maxb = tree[rt].minb = v2;
        tree[rt].ansa = tree[rt].ansb = 0;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
        upd(pos,v1,v2,ls);
    else
        upd(pos,v1,v2,rs);
    push_up(rt);
}
void solve()
{
    scanf("%lld%lld",&n,&q);
    for (int i = 1,x; i <= n; i++)
    {
        scanf("%lld",&x);
        a[i] = x - i;
        b[i] = x + i;
    }
    build(1,n,1);
    printf("%lld\n",max(tree[1].ansa,tree[1].ansb));
    int pos,x;
    while (q--)
    {
        scanf("%lld%lld",&pos,&x);
        a[pos] = x - pos;
        b[pos] = x + pos;
        upd(pos,a[pos],b[pos],1);
        printf("%lld\n",max(tree[1].ansa,tree[1].ansb));
    }
}
signed main()
{
    int t;
    scanf("%lld",&t);
    while (t--)
        solve();
    return 0;
}
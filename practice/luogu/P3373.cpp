#include<bits/extc++.h>
#define int long long
#define ls (rt << 1)
#define rs (rt << 1 | 1)
using namespace std;
const int mod = 571373;
const int maxn = 1e5 + 5;
int n,q;
int a[maxn];
struct 世界树上最纯净的枝丫
{
    int l,r,val;
    int add,mul;
}tree[maxn << 2];
void push_up(int rt){tree[rt].val = (tree[ls].val + tree[rs].val) % mod;}
void push_down(int rt)
{
    tree[ls].val = (tree[ls].val * tree[rt].mul + (tree[ls].r - tree[ls].l + 1) * tree[rt].add) % mod;
    tree[rs].val = (tree[rs].val * tree[rt].mul + (tree[rs].r - tree[rs].l + 1) * tree[rt].add) % mod;
    tree[ls].mul = tree[ls].mul * tree[rt].mul % mod;
    tree[rs].mul = tree[rs].mul * tree[rt].mul % mod;
    tree[ls].add = (tree[ls].add * tree[rt].mul + tree[rt].add) % mod;
    tree[rs].add = (tree[rs].add * tree[rt].mul + tree[rt].add) % mod;
    tree[rt].mul = 1,tree[rt].add = 0;
}
void build(int l,int r,int rt)
{
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].add = 0;
    tree[rt].mul = 1;
    if (l == r)
    {
        tree[rt].val = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
    push_up(rt);
}
void upd1(int ql,int qr,int x,int rt = 1)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (ql <= l && r <= qr)
    {
        tree[rt].val = (tree[rt].val + (r - l + 1) * x) % mod;
        tree[rt].add = (tree[rt].add + x) % mod;
        return;
    }
    push_down(rt);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        upd1(ql,qr,x,ls);
    if (qr > mid)
        upd1(ql,qr,x,rs);
    push_up(rt);
}
void upd2(int ql,int qr,int x,int rt = 1)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (ql <= l && r <= qr)
    {
        tree[rt].val = tree[rt].val * x % mod;
        tree[rt].add = tree[rt].add * x % mod;
        tree[rt].mul = tree[rt].mul * x % mod;
        return;
    }
    push_down(rt);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        upd2(ql,qr,x,ls);
    if (qr > mid)
        upd2(ql,qr,x,rs);
    push_up(rt);
}
int que(int ql,int qr,int rt = 1)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (ql <= l && r <= qr)
        return tree[rt].val;
    push_down(rt);
    int mid = (l + r) >> 1,ret = 0;
    if (ql <= mid)
        ret = (ret + que(ql,qr,ls)) % mod;
    if (qr > mid)
        ret = (ret + que(ql,qr,rs)) % mod;
    return ret; 
}
signed main()
{
    scanf("%lld%lld%lld",&n,&q,a);
    for (int i = 1; i <= n; i++)
        scanf("%lld",a + i);
    build(1,n,1);
    int op,x,y,k;
    while (q--)
    {
        scanf("%lld%lld%lld",&op,&x,&y);
        if (op == 1)
        {
            scanf("%lld",&k);
            upd2(x,y,k);
        }
        else if (op == 2)
        {
            scanf("%lld",&k);
            upd1(x,y,k);
        }
        else
            printf("%lld\n",que(x,y));
    }
    return 0;
}
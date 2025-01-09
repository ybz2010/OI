#include <bits/extc++.h>
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#define int long long
#define ls tree[rt].lson
#define rs tree[rt].rson
using namespace std;
const int maxn = 5e5 + 5;
const int mod = 998244353;
int n,cnt,_max,rt;
int a[maxn];
struct 世界树上最纯净的枝丫
{
    int val;
    int lson,rson,add,mul;
    世界树上最纯净的枝丫() {mul = 1;};
}tree[maxn << 5];
void push_up(int rt){tree[rt].val = (tree[ls].val + tree[rs].val + mod) % mod;}
void push_down(int l,int r,int rt)
{
    if (!tree[rt].lson)
        tree[rt].lson = ++cnt;
    if (!tree[rt].rson)
        tree[rt].rson = ++cnt;
    int mid = (l + r) >> 1;
    tree[ls].val = (((tree[ls].val * tree[rt].mul % mod + mod) % mod + (mid - l + 1) * tree[rt].add % mod) % mod + mod) % mod;
    tree[rs].val = (((tree[rs].val * tree[rt].mul % mod + mod) % mod + (r - mid) * tree[rt].add % mod) % mod + mod) % mod;
    tree[ls].mul = (tree[ls].mul * tree[rt].mul % mod + mod) % mod;
    tree[rs].mul = (tree[rs].mul * tree[rt].mul % mod + mod) % mod;
    tree[ls].add = (tree[ls].add * tree[rt].mul % mod + tree[rt].add + mod) % mod;
    tree[rs].add = (tree[rs].add * tree[rt].mul % mod + tree[rt].add + mod) % mod;
    tree[rt].add = 0,tree[rt].mul = 1;
}

// Plus
void add(int ql,int qr,int x,int l,int r,int &rt)
{
    if (!rt)
        rt = ++cnt;
    if (ql <= l && r <= qr)
    {
        tree[rt].val = ((tree[rt].val + x * (r - l + 1) % mod) % mod + mod) % mod;
        tree[rt].add = ((tree[rt].add + x) % mod + mod) % mod;
        return;
    }
    push_down(l,r,rt);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        add(ql,qr,x,l,mid,ls);
    if (qr > mid)
        add(ql,qr,x,mid + 1,r,rs);
    push_up(rt);
}

// Multiple
void multi(int ql,int qr,int x,int l,int r,int &rt)
{
    if (!rt)
        rt = ++cnt;
    if (ql <= l && r <= qr)
    {
        tree[rt].val = (tree[rt].val * x % mod + mod) % mod;
        tree[rt].add = (tree[rt].add * x % mod + mod) % mod;
        tree[rt].mul = (tree[rt].mul * x % mod + mod) % mod;
        return;
    }
    push_down(l,r,rt);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        multi(ql,qr,x,l,mid,ls);
    if (qr > mid)
        multi(ql,qr,x,mid + 1,r,rs);
    push_up(rt);
}
signed main()
{
    freopen("data.txt","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        _max = max(_max,a[i]);
    }
    _max += 5;
    add(1,a[1],1,1,_max,rt);
    for (int i = 2; i <= n; i++)
    {
        int x = (tree[rt].val + mod) % mod;
        if (a[i] >= a[i - 1])
        {
            multi(1,a[i - 1],-1,1,_max,rt);
            add(1,a[i],x,1,_max,rt);
        }
        else
        {
            multi(a[i] + 1,a[i - 1],0,1,_max,rt);
            multi(1,a[i],-1,1,_max,rt);
            add(1,a[i],x,1,_max,rt);
        }
    }
    cout << (tree[rt].val + mod) % mod << " " << clock();
    return 0;
}
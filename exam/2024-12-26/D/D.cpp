#include<bits/extc++.h>
#define int long long
#define Inv(x) binpow(x,mod - 2)
// #define LOCAL
using namespace std;
const int mod = 998244353;
const int maxn = 1e5 + 5;
int n,q;
int dfn[maxn],id[maxn],sn[maxn],tim;
int fa[maxn],son[maxn],siz[maxn],top[maxn];
int head[maxn],pos[maxn],cnt[maxn << 2],idx;
int op,f1[maxn],f2[maxn],v1[maxn],v2[maxn];
struct edge
{
    int v,nxt;
    edge(int v = 0,int nxt = 0):v(v),nxt(nxt){};
}e[maxn << 1];
struct Nahida
{
    int f1,f2,val;
    int l,r,lazy;
}tree[maxn << 2];
void adde(int u,int v)
{
    e[++idx] = edge(v,head[u]);
    head[u] = idx;
}
int binpow(int x,int y)
{
    int ret = 1;
    while (y)
    {
        if (y & 1)
            ret = ret * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ret;
}
void dfs1(int u)
{
    siz[u] = 1;
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        dfs1(v);
        siz[u] += siz[v];
        if (siz[son[u]] < siz[v])
            son[u] = v;
    }
}
void dfs2(int u)
{
    if (!top[u])
        top[u] = u;
    dfn[u] = ++tim;
    id[tim] = u;
    if (son[u])
    {
        top[son[u]] = top[u];
        dfs2(son[u]);
    }
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == son[u])
            continue;
        dfs2(v);
    }
    v1[dfn[u]] = 1;
    v2[dfn[u]] = siz[u];
}

#define ls (rt << 1)
#define rs (rt << 1 | 1)
void push_up(int rt){tree[rt].val = tree[ls].val * tree[rs].val % mod;}
void push_down(int rt)
{
    if (tree[rt].lazy)
    {
        if (tree[rt].lazy == 1)
        {
            tree[ls].val = tree[ls].f1;
            tree[rs].val = tree[rs].f1;
            tree[ls].lazy = tree[rs].lazy = 1;
        }
        else
        {
            tree[ls].val = tree[ls].f2;
            tree[rs].val = tree[rs].f2;
            tree[ls].lazy = tree[rs].lazy = 2;
        }
        tree[rt].lazy = 0;
    }
}
void build(int l,int r,int rt)
{
    tree[rt].l = l;
    tree[rt].r = r;
    tree[rt].lazy = 0;
    if (l == r)
    {
        tree[rt].f1 = v1[l];
        tree[rt].f2 = v2[l];
        tree[rt].val = tree[rt].f1;
        pos[l] = rt;
        return;
    }
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
    tree[rt].f1 = tree[ls].f1 * tree[rs].f1 % mod;
    tree[rt].f2 = tree[ls].f2 * tree[rs].f2 % mod;
    tree[rt].val = tree[rt].f1;
}
void upd1(int ql,int qr,int rt)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (ql <= l && r <= qr)
    {
        tree[rt].val = tree[rt].f1;
        tree[rt].lazy = 1;
        return;
    }
    push_down(rt);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        upd1(ql,qr,ls);
    if (qr > mid)
        upd1(ql,qr,rs);
    push_up(rt);
}
void upd2(int ql,int qr,int rt)
{
    int l = tree[rt].l;
    int r = tree[rt].r;
    if (ql <= l && r <= qr)
    {
        tree[rt].val = tree[rt].f2;
        tree[rt].lazy = 2;
        return;
    }
    push_down(rt);
    int mid = (l + r) >> 1;
    if (ql <= mid)
        upd2(ql,qr,ls);
    if (qr > mid)
        upd2(ql,qr,rs);
    push_up(rt);
}
int pre(int rt)
{
    if (cnt[pos[rt]])
        return rt;
    rt = pos[rt];
    while (rt)
    {
        if (rt & 1)
        {
            rt >>= 1;
            if (cnt[rt << 1])
            {
                rt <<= 1;
                while (1)
                {
                    if (tree[rt].l == tree[rt].r)
                        return tree[rt].l;
                    if (cnt[rs])
                        rt = rs;
                    else
                        rt = ls;
                }
            }
        }
        else
            rt >>= 1;
    }
    return 0;
}
void upd(int u)
{
    upd1(dfn[sn[u]],dfn[sn[u]],1);
    int x = pos[dfn[u]];
    while (x)
    {
        cnt[x] --;
        x >>= 1;
    }
    sn[u] = 0;
}
#undef ls
#undef rs

signed main()
{
    #ifdef LOCAL
    freopen("tree2.in","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    scanf("%lld%lld",&n,&q);
    op = 1;
    for (int i = 2; i <= n; i++)
    {
        cin >> fa[i];
        adde(fa[i],i);
        op = op * i % mod;
    }
    dfs1(1);
    dfs2(1);
    v1[1] = v2[1] = 1;
    build(1,n,1);
    for (int i = 1; i <= n; i++)
        op = op * Inv(siz[i]) % mod;
    while (q--)
    {
        int u;
        scanf("%lld",&u);
        int c = u;
        while (u)
        {
            int a = top[u],b = u,x = dfn[b];
            if (son[u])
                upd1(dfn[son[u]],dfn[son[u]],1);
            while (1)
            {
                x = pre(x);
                if (x < dfn[a])
                    break;
                upd(id[x--]);
            }
            u = fa[top[u]];
        }
        u = c;
        while (u)
        {
            int a = top[u],b = u;
            upd2(dfn[a],dfn[b],1);
            if (top[u] != 1)
            {
                u = top[u];
                sn[fa[u]] = u;
                int x = pos[dfn[fa[u]]];
                while (x > 0)
                    cnt[x]++, x = x >> 1;
            }
            u = fa[top[u]];
        }
        printf("%lld\n",op * tree[1].val % mod);
    }
    return 0;
}
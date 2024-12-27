#include <bits/stdc++.h>
#define LOCAL
using namespace std;
const int maxn = 2e6 + 7,p = 998244353;
int n,q,k,op;
int son[maxn],dfn[maxn],id[maxn],cnt[maxn];
int siz[maxn],fa[maxn],top[maxn],v2[maxn],v1[maxn],f1[maxn],f2[maxn];
int val[maxn],tag[maxn],sn[maxn],pos[maxn],L[maxn],R[maxn];
int head[maxn],idx;
struct edge
{
    int v,nxt;
    edge(int v = 0,int nxt = 0):v(v),nxt(nxt){};
}e[maxn << 1];
void adde(int u,int v)
{
    e[++idx] = edge(v,head[u]);
    head[u] = idx;
}
long long binpow(long long u,int v)
{
    long long ans = 1;
    while (v > 0)
    {
        if (v & 1)
            ans = ans * u % p;
        u = u * u % p,v = v >> 1;
    }
    return ans;
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
    dfn[u] = ++k,id[k] = u;
    if (son[u])
        top[son[u]] = top[u],dfs2(son[u]);
    for (int i = head[u]; i; i = e[i].nxt)
    {
        int v = e[i].v;
        if (v == son[u])
            continue;
        dfs2(v);
    }
    v2[dfn[u]] = siz[u];
    v1[dfn[u]] = 1;
}
void pushdown(int rt)
{
    if (tag[rt] == 0)
        return;
    if (tag[rt] == 1)
    {
        tag[rt << 1] = tag[rt << 1 | 1] = 1;
        val[rt << 1] = f1[rt << 1],val[rt << 1 | 1] = f1[rt << 1 | 1],val[rt] = f1[rt];
    }
    else
    {
        tag[rt << 1] = tag[rt << 1 | 1] = 2;
        val[rt << 1] = f2[rt << 1],val[rt << 1 | 1] = f2[rt << 1 | 1],val[rt] = f2[rt];
    }
    tag[rt] = 0;
}
void build(int l,int r,int rt)
{
    L[rt] = l,R[rt] = r;
    if (l == r)
    {
        f1[rt] = v1[l],f2[rt] = v2[l],val[rt] = f1[rt],tag[rt] = 0,pos[l] = rt;
        return;
    }
    int d = (l + r) / 2;
    build(l,d,rt << 1),build(d + 1,r,rt << 1 | 1);
    f1[rt] = 1ll * f1[rt << 1] * f1[rt << 1 | 1] % p;
    f2[rt] = 1ll * f2[rt << 1] * f2[rt << 1 | 1] % p;
    val[rt] = f1[rt];
}
void upd1(int l,int r,int rt,int ql,int qr)
{
    pushdown(rt);
    if (l == ql && r == qr)
    {
        val[rt] = f1[rt],tag[rt] = 1;
        return;
    }
    int d = (l + r) / 2;
    if (ql <= d)
        upd1(l,d,rt << 1,ql,min(d,qr));
    if (d + 1 <= qr)
        upd1(d + 1,r,rt << 1 | 1,max(d + 1,ql),qr);
    val[rt] = 1ll * val[rt << 1] * val[rt << 1 | 1] % p;
}
void upd2(int l,int r,int rt,int ql,int qr)
{
    pushdown(rt);
    if (l == ql && r == qr)
    {
        val[rt] = f2[rt],tag[rt] = 2;
        return;
    }
    int d = (l + r) / 2;
    if (ql <= d)
        upd2(l,d,rt << 1,ql,min(d,qr));
    if (d + 1 <= qr)
        upd2(d + 1,r,rt << 1 | 1,max(d + 1,ql),qr);
    val[rt] = 1ll * val[rt << 1] * val[rt << 1 | 1] % p;
}

int pre(int rt)
{
    if (cnt[pos[rt]])
        return rt;
    rt = pos[rt];
    while (rt > 0)
    {
        if (rt & 1)
        {
            rt = rt >> 1;
            if (cnt[rt << 1])
            {
                rt = rt << 1;
                while (1)
                {
                    if (L[rt] == R[rt])
                        return L[rt];
                    if (cnt[rt << 1 | 1])
                        rt = rt << 1 | 1;
                    else
                        rt = rt << 1;
                }
            }
        }
        else
            rt = rt >> 1;
    }
    return 0;
}
void upd(int u)
{
    upd1(1,n,1,dfn[sn[u]],dfn[sn[u]]);
    int x = pos[dfn[u]];
    while (x > 0)
        cnt[x]--,x = x >> 1;
    sn[u] = 0;
}
int main()
{
    #ifdef LOCAL
    freopen("tree2.in","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    cin >> n >> q,op = 1;
    for (int i = 2; i <= n; i++)
        cin >> fa[i],adde(fa[i],i),op = 1ll * op * i % p;
    dfs1(1);
    dfs2(1);
    v1[1] = v2[1] = 1,build(1,n,1);
    for (int i = 1; i <= n; i++)
        op = 1ll * op * binpow(siz[i],p - 2) % p;
    while (q--)
    {
        int u;
        cin >> u;
        int c = u;
        while (u > 0)
        {
            int a = top[u],b = u,x = dfn[b];

            if (son[u] > 0)
                upd1(1,n,1,dfn[son[u]],dfn[son[u]]);

            while (1)
            {
                x = pre(x);
                if (x < dfn[a])
                    break;
                upd(id[x]),x--;
            }
            u = fa[top[u]];
        }
        u = c;
        while (u > 0)
        {
            int a = top[u],b = u;
            upd2(1,n,1,dfn[a],dfn[b]);
            if (top[u] != 1)
            {
                u = top[u];
                sn[fa[u]] = u;
                int x = pos[dfn[fa[u]]];
                while (x > 0)
                    cnt[x]++,x = x >> 1;
            }
            u = fa[top[u]];
        }
        cout << 1ll * op * val[1] % p << '\n';
    }
    return 0;
}
#include<cstdio>
#include<algorithm>
#include<stack>
#define ri register
#define int long long
#define inf 0x7f7f7f7f7f7f
#define ls (rt << 1)
#define rs (rt << 1 | 1)
using namespace std;
const int maxn(1e5 + 5);
int n,m;
int h[maxn],sum[maxn],pos[maxn];
int dp[maxn];
void read(int &x)
{
    x = 0;
    ri int f(1);
    ri char ch = getchar();
    while (ch < '0' || ch > '9'){f = ch == '-' ? -1 : 1;ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    x *= f;
}
struct 世界树上最纯净的枝丫
{
    int ans,dp;
    int l,r,lazy;
}tree[maxn << 2];
void push_up(int rt)
{
    tree[rt].ans = min(tree[ls].ans,tree[rs].ans);
    tree[rt].dp = min(tree[ls].dp,tree[rs].dp);
}
void push_down(int rt)
{
    if (tree[rt].lazy == inf)
        return;
    tree[ls].ans = tree[ls].dp + tree[rt].lazy;
    tree[rs].ans = tree[rs].dp + tree[rt].lazy;
    tree[ls].lazy = tree[rs].lazy = tree[rt].lazy;
    tree[rt].lazy = inf;
}
void build(int l,int r,int rt)
{
    tree[rt].l = l;
    tree[rt].r = r;
    if (l == r)
    {
        tree[rt].dp = tree[rt].ans = tree[rt].lazy = inf;
        return;
    }
    ri int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid + 1,r,rs);
    push_up(rt);
}
void upd1(int pos,int rt = 1)
{
    ri int l(tree[rt].l);
    ri int r(tree[rt].r);
    if (l == r)
    {
        tree[rt].dp = dp[pos - 1];
        tree[rt].ans = inf;
        return;
    }
    push_down(rt);
    int mid((l + r) >> 1);
    if (pos <= mid)
        upd1(pos,ls);
    else
        upd1(pos,rs);
    push_up(rt);
} 
void upd2(int ql,int qr,int x,int rt = 1)
{
    ri int l(tree[rt].l);
    ri int r(tree[rt].r);
    if (ql <= l && r <= qr)
    {
        tree[rt].ans = tree[rt].dp + x;
        tree[rt].lazy = x;
        return;
    }
    push_down(rt);
    ri int mid((l + r) >> 1);
    if (ql <= mid)
        upd2(ql,qr,x,ls);
    if (qr > mid)
        upd2(ql,qr,x,rs);
    push_up(rt);
}
int que(int ql,int qr,int rt = 1)
{
    ri int l(tree[rt].l);
    ri int r(tree[rt].r);
    if (ql <= l && r <= qr)
        return tree[rt].ans;
    push_down(rt);
    ri int mid = (l + r) >> 1,ret = inf;
    if (ql <= mid)
        ret = min(ret,que(ql,qr,ls));
    if (qr > mid)
        ret = min(ret,que(ql,qr,rs));
    return ret;
}
void init()
{
    stack<int>st;
    st.push(1);
    for (ri int i(2); i <= n; i++)
    {
        while (!st.empty() && h[i] > h[st.top()])
            st.pop();
        if (!st.empty())
            pos[i] = st.top();
        st.push(i);
    }
    build(1,n,1);
}
signed main()
{
    read(n),read(m);
    for (ri int i(1); i <= n; i++)
    {
        read(h[i]);
        if (h[i] > m)
        {
            puts("-1");
            return 0;
        }
        sum[i] = sum[i - 1] + h[i];
    }
    init();
    for (ri int i(1); i <= n; i++)
    {
        upd1(i);
        if (pos[i] < i)
            upd2(pos[i] + 1,i,h[i]);
        int tpos = lower_bound(sum,sum + i + 1,sum[i] - m) - sum;
        if (tpos < i)
            dp[i] = que(tpos + 1,i);
        else
        {
            puts("-1");
            return 0;
        }
    }
    printf("%lld\n",dp[n]);
    return 0;
}
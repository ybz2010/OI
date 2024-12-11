#include <cstdio>
#include <ctype.h>
#include <cstring>
#include <algorithm>
#define ll long long
#define ls (now << 1)
#define rs (now << 1 | 1)
const int kMaxn = 1e5 + 10;
const ll kInf = 1e12 + 2077;
struct SegmentTree
{
    int L, R;
    ll f, ans, lazy;
} tree[kMaxn << 2];
ll n, m, h[kMaxn], sum[kMaxn], pre[kMaxn], f[kMaxn];
ll top, sta[kMaxn];
inline ll read()
{
    ll f = 1, w = 0;
    char ch = getchar();
    for (; !isdigit(ch); ch = getchar())
        if (ch == '-')
            f = -1;
    for (; isdigit(ch); ch = getchar())
        w = (w << 3) + (w << 1) + (ch ^ '0');
    return f * w;
}
void Pushup(int now)
{
    tree[now].f = std ::min(tree[ls].f, tree[rs].f);
    tree[now].ans = std ::min(tree[ls].ans, tree[rs].ans);
}
void Pushdown(int now)
{
    tree[ls].ans = tree[ls].f + tree[now].lazy;
    tree[rs].ans = tree[rs].f + tree[now].lazy;
    tree[ls].lazy = tree[rs].lazy = tree[now].lazy;
    tree[now].lazy = kInf;
}
void Build(int now, int L, int R)
{
    tree[now].L = L, tree[now].R = R;
    if (L == R)
    {
        tree[now].f = tree[now].ans = tree[now].lazy = kInf;
        return;
    }
    int mid = (L + R) >> 1;
    Build(ls, L, mid), Build(rs, mid + 1, R);
    Pushup(now);
}
ll que(int now, int L, int R)
{
    if (L <= tree[now].L && tree[now].R <= R)
        return tree[now].ans;
    if (tree[now].lazy != kInf)
        Pushdown(now);
    int mid = (tree[now].L + tree[now].R) >> 1;
    ll ret = kInf;
    if (L <= mid)
        ret = std ::min(ret, que(ls, L, R));
    if (R > mid)
        ret = std ::min(ret, que(rs, L, R));
    return ret;
}
void upd1(int now, int L, int R, ll val)
{
    if (L <= tree[now].L && tree[now].R <= R)
    {
        tree[now].ans = tree[now].f + val;
        tree[now].lazy = val;
        return;
    }
    if (tree[now].lazy != kInf)
        Pushdown(now);
    int mid = (tree[now].L + tree[now].R) >> 1;
    if (L <= mid)
        upd1(ls, L, R, val);
    if (R > mid)
        upd1(rs, L, R, val);
    Pushup(now);
}
void upd2(int now, int pos)
{
    if (tree[now].L == tree[now].R)
    {
        tree[now].ans = kInf;
        tree[now].f = f[pos - 1];
        return;
    }
    if (tree[now].lazy != kInf)
        Pushdown(now);
    int mid = (tree[now].L + tree[now].R) >> 1;
    if (pos <= mid)
        upd2(ls, pos);
    else
        upd2(rs, pos);
    Pushup(now);
}
void init()
{
    n = read(), m = read();
    for (int i = 1; i <= n; ++i)
    {
        h[i] = read();
        sum[i] = sum[i - 1] + h[i];
    }

    sta[++top] = 1;
    for (int i = 2; i <= n; ++i)
    {
        while (top && h[sta[top]] < h[i])
            top--;
        if (top)
            pre[i] = sta[top];
        sta[++top] = i;
    }
    Build(1, 1, n);
}
//=============================================================
int main()
{
    init();
    for (int i = 1; i <= n; ++i)
    {
        upd2(1, i);
        if (pre[i] < i)
            upd1(1, pre[i] + 1, i, h[i]);
        int l = std ::lower_bound(sum, sum + i + 1, sum[i] - m) - sum;
        if (l < i)
            f[i] = que(1, l + 1, i);
    }
    printf("%lld", f[n]);
    return 0;
}

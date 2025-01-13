#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 3;
#define db double
db k[N], y[N], a[N], b[N], r[N], x1[N], x2[N];
int u, tree[N * 4];
#define f(x, id) (y[id] + k[id] * x1[x])
void upd(int ln, int l, int r, int rt)
{
    if (l == r)
    {
        if (f(l, ln) > f(l, tree[rt]))
            tree[rt] = ln;
        return;
    }
    int m = l + r >> 1;
    if (f(m, ln) > f(m, tree[rt]))
        swap(ln, tree[rt]);
    f(l, ln) > f(l, tree[rt]) ? upd(ln, l, m, rt * 2) : upd(ln, m + 1, r, rt * 2 + 1);
} // 李超树插入
db que(int rt, int l, int r)
{
    if (l == r)
        return f(u, tree[rt]);
    int m = l + r >> 1;
    return max(f(u, tree[rt]), u > m ? que(rt * 2 + 1, m + 1, r) : que(rt * 2, l, m));
} // 李超树查询
int main()
{
    int n, i;
    db f, g;
    scanf("%d%lf", &n, &f);
    for (i = 1; i <= n; ++i)
        scanf("%lf%lf%lf", a + i, b + i, r + i), x1[i] = a[i] / b[i], x2[i] = x1[i];
    sort(x1 + 1, x1 + n + 1); // 离散化
    for (i = 1; i <= n; ++i)
    {
        u = lower_bound(x1 + 1, x1 + n + 1, x2[i]) - x1, f = max(f, b[i] * que(1, 1, n));
        g = a[i] * r[i] + b[i];
        k[i] = f * r[i] / g;
        y[i] = f / g, upd(i,1,n,1);
    }
    printf("%.3lf", f);
    return 0;
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void read(int &x)
{
    x = 0;
    char ch = getchar();
    while (!isdigit(ch))
        ch = getchar();
    while (isdigit(ch))
        x = x * 10 + (ch & 15), ch = getchar();
}
void write(ll x)
{
    if (x < 0)
        putchar('-'), x = -x;
    if (x > 9)
        write(x / 10);
    putchar('0' + x % 10);
}

const int maxn = 150010;
int n, q, to[maxn], b[maxn];
ll sum[maxn], res, now;
struct node
{
    int val, id;
    bool operator<(const node &rhs) const { return val < rhs.val; }
} a[maxn];

signed main()
{
    read(n);
    for (int i = 1; i <= n; i++)
        read(a[i].val), a[i].id = i;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        to[a[i].id] = i, res += 1ll * i * a[i].val;
    for (int i = 1; i <= n; i++)
        b[i] = a[i].val, sum[i] = sum[i - 1] + b[i];
    read(q);
    for (int i = 1, x, y; i <= q; i++)
    {
        read(x), read(y);
        now = res - 1ll * to[x] * b[to[x]];
        int pos = lower_bound(b + 1, b + n + 1, y) - b;
        now += 1ll * (pos - (pos > to[x])) * y;
        if (pos > to[x])
            now -= (sum[pos - 1] - sum[to[x]]);
        if (pos < to[x])
            now += (sum[to[x] - 1] - sum[pos - 1]);
        write(now), putchar('\n');
    }
    return 0;
}